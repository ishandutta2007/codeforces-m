/*
    author:  Maksim1744
    created: 19.10.2022 21:30:52
*/

pub use __cargo_equip::prelude::*;

use rlib_io::*;
use rlib_sieve::*;

const ROTATE_DELTA: [u32; 4] = [3, 0, 0, 1];

fn hilbert_order(x: u32, y: u32, pow: u32, rotate: u32) -> i64 {
    if pow == 0 {
        return 0;
    }
    let hpow = 1 << (pow - 1);
    let xi = x >> (pow - 1);
    let yi = y >> (pow - 1);
    let seg = xi ^ yi ^ (yi << 1);
    let seg = (seg + rotate) & 3;
    let x = x & !hpow;
    let y = y & !hpow;
    let nrot = (rotate + ROTATE_DELTA[seg as usize]) & 3;
    let square_size = 1i64 << (pow * 2 - 2);
    let mut ans = seg as i64 * square_size;
    let add = hilbert_order(x, y, pow - 1, nrot);
    ans += match seg {
        1 | 2 => add,
        0 | 3 => square_size - add - 1,
        _ => unsafe { std::hint::unreachable_unchecked() },
    };
    ans
}

fn solve(cin: &mut Reader, cout: &mut Writer, _test: usize) {
    make_output_macro!(cout);

    let (n, m, c, q): (usize, usize, i32, usize) = cin.read();
    let a: Vec<i32> = cin.read_vec(n);

    let sieve = Sieve::new(m);

    let mut s = Vec::new();
    for i in 1.. {
        if i * i > c {
            break;
        }
        s.push(i);
        s.push(c / i);
    }
    s.sort();
    s.dedup();

    let inds = a
        .iter()
        .map(|x| {
            sieve
                .factorize(*x)
                .map(|(p, _)| sieve.primes().partition_point(|&y| y < p))
                .collect::<Vec<_>>()
        })
        .collect::<Vec<_>>();

    let get_ind = |i: i32| -> usize {
        if (i as i64) * (i as i64) <= c as i64 {
            i as usize - 1
        } else {
            s.len() - (c / i) as usize
        }
    };

    let mut sinds = vec![usize::MAX; c as usize + 1];
    for &x in s.iter() {
        sinds[x as usize] = get_ind(x);
    }

    let mut v = s.clone();

    let add_p = |v: &mut Vec<i32>, ip: usize| {
        let p = sieve.primes()[ip];
        for i in (0..v.len()).rev() {
            if s[i] / p == 0 {
                break;
            }
            v[i] -= v[sinds[(s[i] / p) as usize]];
        }
    };
    let lowb = sieve.primes().iter().map(|&p| s.partition_point(|&y| y < p)).collect::<Vec<_>>();
    let remove_p = |v: &mut Vec<i32>, ip: usize| {
        let p = sieve.primes()[ip];
        for i in lowb[ip]..v.len() {
            v[i] += v[sinds[(s[i] / p) as usize]];
        }
    };

    let mut cnts = vec![0i32; sieve.primes().len()];

    let mut ques = (0..q)
        .map(|_| cin.read::<(usize, usize)>())
        .map(|(l, r)| (l - 1, r - 1))
        .enumerate()
        .collect::<Vec<_>>();

    ques.sort_by_cached_key(|&(_, (l, r))| hilbert_order(l as u32, r as u32, 18, 0));

    let mut ans = vec![0i32; q];

    let mut lastr = ques[0].1 .1;
    let mut lastl = lastr + 1;

    for (i, (l, r)) in ques {
        let mut add_ind = |ind: usize| {
            for &i in inds[ind].iter() {
                cnts[i] += 1;
                if cnts[i] == 1 {
                    add_p(&mut v, i);
                }
            }
        };

        while lastl > l {
            lastl -= 1;
            add_ind(lastl);
        }
        while lastr < r {
            lastr += 1;
            add_ind(lastr);
        }

        let mut remove_ind = |ind: usize| {
            for &i in inds[ind].iter() {
                cnts[i] -= 1;
                if cnts[i] == 0 {
                    remove_p(&mut v, i);
                }
            }
        };

        while lastl < l {
            remove_ind(lastl);
            lastl += 1;
        }
        while lastr > r {
            remove_ind(lastr);
            lastr -= 1;
        }
        ans[i] = *v.last().unwrap();
    }
    for x in ans {
        outln!(x);
    }
}

fn main() {
    make_io!(cin, cout);
    solve(&mut cin, &mut cout, 1);
}

// The following code was expanded by `cargo-equip`.

///  # Bundled libraries
/// 
///  - `rlib_integer 0.1.0 (path+)` published in https://github.com/maksim1744/rlib licensed under `MIT` as `crate::__cargo_equip::crates::rlib_integer`
///  - `rlib_io 0.1.0 (path+)`           published in https://github.com/maksim1744/rlib licensed under `MIT` as `crate::__cargo_equip::crates::rlib_io`
///  - `rlib_sieve 0.1.0 (path+)`     published in https://github.com/maksim1744/rlib licensed under `MIT` as `crate::__cargo_equip::crates::rlib_sieve`
#[cfg_attr(any(), rustfmt::skip)]
#[allow(unused)]
mod __cargo_equip {
    pub(crate) mod crates {
        pub mod rlib_integer {use std::cmp::*;use std::ops::*;pub trait Integer:Add<Output=Self>+AddAssign+Sub<Output=Self>+SubAssign+Div<Output=Self>+DivAssign+Rem<Output=Self>+RemAssign+Mul<Output=Self>+MulAssign+PartialEq+Copy+Clone+Sized{type Unsigned:Integer;type Signed:Integer;const BASE_10_LEN:usize;const ZERO:Self;const ONE:Self;const TWO:Self;fn unsigned_abs(self)->Self::Unsigned;fn abs(self)->Self;}macro_rules!integer_common{($it:ty,$ut:ty,$len:expr)=>{type Unsigned=$ut;type Signed=$it;const BASE_10_LEN:usize=$len;const ZERO:Self=0;const ONE:Self=1;const TWO:Self=2;};}macro_rules!base_10_len{($ut:ty)=>{{let mut value=<$ut>::MAX;let mut ans:usize=0;while value!=0{value/=10;ans+=1;}ans}};}macro_rules!integer{($it:ty,$ut:ty,$len:expr)=>{impl Integer for$it{integer_common!($it,$ut,$len);fn unsigned_abs(self)->Self::Unsigned{Self::unsigned_abs(self)}fn abs(self)->Self{self.abs()}}impl Integer for$ut{integer_common!($it,$ut,$len);fn unsigned_abs(self)->Self::Unsigned{self}fn abs(self)->Self{self}}};($it:ty,$ut:ty)=>{integer!($it,$ut,base_10_len!($ut));};}integer!(i8,u8);integer!(i16,u16);integer!(i32,u32);integer!(i64,u64);integer!(i128,u128);integer!(isize,usize);}
        pub mod rlib_io {use crate::__cargo_equip::preludes::rlib_io::*;pub use crate::__cargo_equip::macros::rlib_io::*;pub mod output_macro{use crate::__cargo_equip::preludes::rlib_io::*;#[macro_export]macro_rules!__cargo_equip_macro_def_rlib_io_out_impl{($writer:ident,$x:expr)=>{$writer.write(&$x);};($writer:ident,$x:expr,$($xx:tt)*)=>{$writer.write(&$x);$writer.write_char(' ');rlib_io::out_impl!($writer,$($xx)*);};}macro_rules!out_impl{($($tt:tt)*)=>(crate::__cargo_equip_macro_def_rlib_io_out_impl!{$($tt)*})}#[macro_export]macro_rules!__cargo_equip_macro_def_rlib_io_make_output_macro_{($writer:ident)=>{make_output_macro_!($writer,$);};($writer:ident,$dol:tt)=>{#[allow(unused_macros)]macro_rules!out{($dol($dol x:tt)*)=>{rlib_io::out_impl!($writer,$dol($dol x)*);};}#[allow(unused_macros)]macro_rules!outln{()=>{$writer.write_char('\n');};($dol($dol x:tt)*)=>{rlib_io::out_impl!($writer,$dol($dol x)*);$writer.write_char('\n');};}}}macro_rules!make_output_macro_{($($tt:tt)*)=>(crate::__cargo_equip_macro_def_rlib_io_make_output_macro_!{$($tt)*})}pub use crate::__cargo_equip::crates::rlib_io::make_output_macro_ as make_output_macro;}pub mod reader{use crate::__cargo_equip::preludes::rlib_io::*;use std::io::Read;pub struct Reader{buf:[u8;Reader::BUF_SIZE],begin:usize,end:usize,stdin:Box<dyn Read>,eof:bool,}impl Reader{const BUF_SIZE:usize=1<<16;pub fn new(stdin:Box<dyn Read>)->Self{Self{buf:[0;Reader::BUF_SIZE],begin:0,end:0,stdin,eof:false,}}pub fn read<T:Readable>(&mut self)->T{T::read(self)}pub fn read_vec<T:Readable>(&mut self,n:usize)->Vec<T>{let mut result=Vec::<T>::with_capacity(n);for _ in 0..n{result.push(self.read());}result}fn refill(&mut self){if self.eof{return;}if self.begin!=0{self.buf.copy_within(self.begin..self.end,0);self.end-=self.begin;self.begin=0;}let bytes=self.stdin.read(&mut self.buf[self.end..]).unwrap();if bytes==0{self.eof=true;}self.end+=bytes;}fn skip_whitespace(&mut self){while{if self.begin==self.end{self.refill();}!self.eof&&self.peek().is_ascii_whitespace()}{self.begin+=1;if self.begin==self.end{self.refill();}}}fn peek(&mut self)->u8{if self.begin==self.end{self.refill();}self.buf[self.begin]}}pub trait Readable{fn read(reader:&mut Reader)->Self;}impl Readable for String{fn read(reader:&mut Reader)->Self{reader.skip_whitespace();let mut result=String::new();let mut read_something=false;while{if reader.begin==reader.end{reader.refill();}!reader.eof&&!reader.peek().is_ascii_whitespace()}{result.push(reader.peek()as char);reader.begin+=1;read_something=true;}debug_assert!(read_something);result}}macro_rules!read_signed{($t:ty)=>{impl Readable for$t{fn read(reader:&mut Reader)->Self{reader.skip_whitespace();let mut result:$t=0;let mut read_something=false;if reader.peek()==b'-'{reader.begin+=1;while{if reader.begin==reader.end{reader.refill();}!reader.eof&&!reader.peek().is_ascii_whitespace()}{debug_assert!(reader.buf[reader.begin].is_ascii_digit());result=result*10-(reader.buf[reader.begin]-('0' as u8))as$t;reader.begin+=1;read_something=true;}}else{while{if reader.begin==reader.end{reader.refill();}!reader.eof&&!reader.peek().is_ascii_whitespace()}{debug_assert!(reader.buf[reader.begin].is_ascii_digit());result=result*10+(reader.buf[reader.begin]-('0' as u8))as$t;reader.begin+=1;read_something=true;}}debug_assert!(read_something);result}}};}macro_rules!read_unsigned{($t:ty)=>{impl Readable for$t{fn read(reader:&mut Reader)->Self{reader.skip_whitespace();let mut result:$t=0;let mut read_something=false;while{if reader.begin==reader.end{reader.refill();}!reader.eof&&!reader.peek().is_ascii_whitespace()}{debug_assert!(reader.buf[reader.begin].is_ascii_digit());result=result*10+(reader.buf[reader.begin]-('0' as u8))as$t;reader.begin+=1;read_something=true;}debug_assert!(read_something);result}}};}read_signed!(i8);read_signed!(i16);read_signed!(i32);read_signed!(i64);read_signed!(i128);read_signed!(isize);read_unsigned!(u8);read_unsigned!(u16);read_unsigned!(u32);read_unsigned!(u64);read_unsigned!(u128);read_unsigned!(usize);macro_rules!read_tuple{($($t:ident),*)=>{impl<$($t:Readable,)*>Readable for($($t,)*){fn read(reader:&mut Reader)->Self{($($t::read(reader)),*)}}}}read_tuple!(A,B);read_tuple!(A,B,C);read_tuple!(A,B,C,D);read_tuple!(A,B,C,D,E);read_tuple!(A,B,C,D,E,F);read_tuple!(A,B,C,D,E,F,G);read_tuple!(A,B,C,D,E,F,G,H);}pub mod writer{use crate::__cargo_equip::preludes::rlib_io::*;use std::io::Write;use rlib_integer::Integer;pub struct Writer<'a>{buf:[u8;Writer::BUF_SIZE],end:usize,stdout:Box<dyn Write+'a>,}impl<'a>Writer<'a>{const BUF_SIZE:usize=1<<16;pub fn new(stdout:Box<dyn Write+'a>)->Self{Self{buf:[0;Writer::BUF_SIZE],end:0,stdout,}}pub fn write<T:Writable>(&mut self,t:&T){t.write(self);#[cfg(debug_assertions)]self.flush();}pub fn write_char(&mut self,c:char){self.write_bytes(&[c as u8]);#[cfg(debug_assertions)]self.flush();}fn flush(&mut self){if self.end==0{return;}self.stdout.write_all(&self.buf[..self.end]).unwrap();self.end=0;}fn reserve(&mut self,size:usize){if self.end+size>self.buf.len(){self.flush();}}fn write_bytes(&mut self,buf:&[u8]){self.reserve(buf.len());self.buf[self.end..self.end+buf.len()].copy_from_slice(buf);self.end+=buf.len();}}impl Drop for Writer<'_>{fn drop(&mut self){self.flush();}}pub trait Writable{fn write(&self,writer:&mut Writer);}impl Writable for&str{fn write(&self,writer:&mut Writer){for chunk in self.as_bytes().chunks(Writer::BUF_SIZE){writer.write_bytes(chunk);}}}impl Writable for String{fn write(&self,writer:&mut Writer){for chunk in self.as_bytes().chunks(Writer::BUF_SIZE){writer.write_bytes(chunk);}}}impl<T:Writable>Writable for Vec<T>{fn write(&self,writer:&mut Writer){for(i,value)in self.iter().enumerate(){if i!=0{writer.write_char(' ');}writer.write(value);}}}macro_rules!write_unsigned{($t:ty)=>{impl Writable for$t{fn write(&self,writer:&mut Writer){if self==&0{writer.write_char('0');return;}let mut buf=[0;<$t as Integer>::BASE_10_LEN];let mut index=buf.len();let mut value=*self;while value!=0{index-=1;buf[index]=(value%10)as u8+b'0';value/=10;}writer.write_bytes(&buf[index..]);}}};}macro_rules!write_signed{($t:ty)=>{impl Writable for$t{fn write(&self,writer:&mut Writer){if self<&0{writer.write_char('-');}writer.write(&self.unsigned_abs());}}};}write_signed!(i8);write_signed!(i16);write_signed!(i32);write_signed!(i64);write_signed!(i128);write_signed!(isize);write_unsigned!(u8);write_unsigned!(u16);write_unsigned!(u32);write_unsigned!(u64);write_unsigned!(u128);write_unsigned!(usize);macro_rules!write_tuple{($t1:ident,$($t:ident),*)=>{impl<$t1:Writable,$($t:Writable,)*>Writable for($t1,$($t,)*){fn write(&self,writer:&mut Writer){#[allow(non_snake_case)]let($t1,$($t,)*)=self;writer.write($t1);$(writer.write_char(' ');writer.write($t);)*}}}}write_tuple!(A,B);write_tuple!(A,B,C);write_tuple!(A,B,C,D);write_tuple!(A,B,C,D,E);write_tuple!(A,B,C,D,E,F);write_tuple!(A,B,C,D,E,F,G);write_tuple!(A,B,C,D,E,F,G,H);}pub use output_macro::make_output_macro;pub use reader::{Readable,Reader};pub use writer::{Writable,Writer};#[macro_export]macro_rules!__cargo_equip_macro_def_rlib_io_make_io{($reader:ident,$writer:ident)=>{#[allow(unused_variables)]let mut$reader=rlib_io::reader::Reader::new(Box::new(std::io::stdin().lock()));#[allow(unused_variables)]let mut$writer=rlib_io::writer::Writer::new(Box::new(std::io::stdout().lock()));rlib_io::output_macro::make_output_macro!($writer);};}macro_rules!make_io{($($tt:tt)*)=>(crate::__cargo_equip_macro_def_rlib_io_make_io!{$($tt)*})}}
        pub mod rlib_sieve {pub struct PrimeIter<'a>{sieve:&'a Sieve,n:i32,}impl<'a>Iterator for PrimeIter<'a>{type Item=(i32,i32);fn next(&mut self)->Option<Self::Item>{if self.n==1{return None;}let mut cnt=0;let p=self.sieve.min_prime(self.n);while self.sieve.min_prime(self.n)==p{cnt+=1;self.n/=p;}Some((p,cnt))}}pub struct Sieve{isp:Vec<bool>,mnp:Vec<i32>,primes:Vec<i32>,}impl Sieve{pub fn new(n:usize)->Self{let n=n+1;let mut isp=vec![false;n];let mut mnp=vec![0i32;n];let mut primes=Vec::new();for i in 2..n{if mnp[i]==0{isp[i]=true;mnp[i]=i as i32;primes.push(i as i32);}for j in 0..primes.len(){if primes[j]>mnp[i]||primes[j]as usize*i>=n{break;}mnp[primes[j]as usize*i]=primes[j];}}Self{isp,mnp,primes}}pub fn min_prime(&self,n:i32)->i32{self.mnp[n as usize]}pub fn is_prime(&self,n:i32)->bool{self.isp[n as usize]}pub fn primes(&self)->&Vec<i32>{&self.primes}pub fn factorize(&self,n:i32)->PrimeIter{PrimeIter{sieve:&self,n}}}}
    }

    pub(crate) mod macros {
        pub mod rlib_integer {}
        pub mod rlib_io {pub use crate::{__cargo_equip_macro_def_rlib_io_make_io as make_io,__cargo_equip_macro_def_rlib_io_make_output_macro_ as make_output_macro_,__cargo_equip_macro_def_rlib_io_out_impl as out_impl};}
        pub mod rlib_sieve {}
    }

    pub(crate) mod prelude {pub use crate::__cargo_equip::crates::*;}

    mod preludes {
        pub mod rlib_integer {}
        pub mod rlib_io {pub(in crate::__cargo_equip)use crate::__cargo_equip::crates::rlib_integer;}
        pub mod rlib_sieve {}
    }
}