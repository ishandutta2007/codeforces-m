/*
    author:  Maksim1744
    created: 21.10.2022 17:36:57
*/

pub use __cargo_equip::prelude::*;

use rlib_io::*;
use std::collections::*;

// f(x) = min(a + x, b)
// a = h[v]
// b = leaf[v]
#[derive(Debug, Clone)]
struct Func {
    vals: VecDeque<i32>,
    offset: i32,
}

impl Func {
    fn from_ab(a: i32, b: i32) -> Self {
        Self {
            vals: VecDeque::from([b]),
            offset: b - a,
        }
    }

    fn at(&self, x: i32) -> i32 {
        if x < self.offset {
            self.vals[0] - (self.offset - x)
        } else if x < self.offset + self.vals.len() as i32 {
            self.vals[(x - self.offset) as usize]
        } else {
            *self.vals.back().unwrap()
        }
    }

    fn push_front(&mut self) {
        self.vals.push_front(self.at(self.offset - 1));
        self.offset -= 1;
    }

    fn push_back(&mut self) {
        self.vals.push_back(*self.vals.back().unwrap());
    }
}

fn merge_func(mut a: Func, mut b: Func) -> Func {
    if a.vals.len() < b.vals.len() {
        std::mem::swap(&mut a, &mut b);
    }
    while b.offset < a.offset {
        a.push_front();
    }
    while b.offset + b.vals.len() as i32 > a.offset + a.vals.len() as i32 {
        a.push_back();
    }
    for i in 0..b.vals.len() as i32 {
        let pos = (i + b.offset - a.offset) as usize;
        a.vals[pos] = a.vals[pos].max(b.vals[i as usize]);
    }
    for i in (i32::MIN..0).rev() {
        if b.at(b.offset + i) <= a.at(b.offset + i) {
            break;
        }
        let pos = b.offset + i - a.offset;
        if pos < 0 {
            break;
        }
        a.vals[pos as usize] = b.at(b.offset + i);
    }
    for i in b.vals.len() as i32..i32::MAX {
        if b.at(b.offset + i) <= a.at(b.offset + i) {
            break;
        }
        let pos = b.offset + i - a.offset;
        if pos >= a.vals.len() as i32 {
            break;
        }
        a.vals[pos as usize] = b.at(b.offset + i);
    }
    a
}

fn solve(cin: &mut Reader, cout: &mut Writer, _test: usize) {
    make_output_macro!(cout);

    let n: usize = cin.read();
    let mut g: Vec<Vec<usize>> = vec![Vec::new(); n];
    for i in 1..n {
        let p: usize = cin.read();
        g[p - 1].push(i);
    }
    let q: usize = cin.read();
    let d = cin.read_vec::<i32>(q);
    let mut h = vec![0; n];
    let mut leaf = vec![i32::MAX; n];

    fn dfs1(v: usize, g: &Vec<Vec<usize>>, h: &mut Vec<i32>, leaf: &mut Vec<i32>) {
        if g[v].is_empty() || (v == 0 && g[v].len() == 1) {
            leaf[v] = 0;
        }
        for &k in g[v].iter() {
            h[k] = h[v] + 1;
            dfs1(k, g, h, leaf);
            leaf[v] = leaf[v].min(leaf[k] + 1);
        }
    }
    dfs1(0, &g, &mut h, &mut leaf);

    let mut order = Vec::new();

    fn dfs2(v: usize, g: &Vec<Vec<usize>>, leaf: &mut Vec<i32>, order: &mut Vec<usize>, par_leaf: i32) {
        leaf[v] = leaf[v].min(par_leaf);
        order.push(v);
        for &k in g[v].iter() {
            dfs2(k, g, leaf, order, leaf[v] + 1);
        }
    }
    dfs2(0, &g, &mut leaf, &mut order, i32::MAX);
    order.reverse();

    let mut ans = vec![0; q];
    let mut dp: Vec<Option<Func>> = vec![None; n];
    for v in order.into_iter() {
        let mut func = Func::from_ab(h[v], leaf[v]);

        for &k in g[v].iter() {
            let mut funck = dp[k].take().unwrap();
            if funck.vals.len() > func.vals.len() {
                std::mem::swap(&mut func, &mut funck);
            }
            // diam = min(h[x] + h[y] - 2*h[v], leaf[x] + leaf[y] + d)
            //      = min(h[y] + (h[x]-2h[v]), leaf[y] + (leaf[x]+d))
            //      = min(h[y] + (h[x]-2h[v]-leaf[x]-d), leaf[y]) + (leaf[x] + d)
            for i in 0..d.len() {
                for j in 0..funck.vals.len() {
                    // b - a = j + offset
                    // b = f[j]
                    let b = funck.vals[j];
                    let a = b - (j as i32 + funck.offset);
                    let leafx = b;
                    let hx = a;
                    let query_x = hx - h[v] * 2 - leafx - d[i];
                    let diam = func.at(query_x) + (leafx + d[i]);
                    ans[i] = ans[i].max(diam);
                }
            }

            func = merge_func(func, funck);
        }

        dp[v] = Some(func);
    }

    outln!(ans);
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
#[cfg_attr(any(), rustfmt::skip)]
#[allow(unused)]
mod __cargo_equip {
    pub(crate) mod crates {
        pub mod rlib_integer {use std::cmp::*;use std::ops::*;pub trait Integer:Add<Output=Self>+AddAssign+Sub<Output=Self>+SubAssign+Div<Output=Self>+DivAssign+Rem<Output=Self>+RemAssign+Mul<Output=Self>+MulAssign+PartialEq+Copy+Clone+Sized{type Unsigned:Integer;type Signed:Integer;const BASE_10_LEN:usize;const ZERO:Self;const ONE:Self;const TWO:Self;fn unsigned_abs(self)->Self::Unsigned;fn abs(self)->Self;}macro_rules!integer_common{($it:ty,$ut:ty,$len:expr)=>{type Unsigned=$ut;type Signed=$it;const BASE_10_LEN:usize=$len;const ZERO:Self=0;const ONE:Self=1;const TWO:Self=2;};}macro_rules!base_10_len{($ut:ty)=>{{let mut value=<$ut>::MAX;let mut ans:usize=0;while value!=0{value/=10;ans+=1;}ans}};}macro_rules!integer{($it:ty,$ut:ty,$len:expr)=>{impl Integer for$it{integer_common!($it,$ut,$len);fn unsigned_abs(self)->Self::Unsigned{Self::unsigned_abs(self)}fn abs(self)->Self{self.abs()}}impl Integer for$ut{integer_common!($it,$ut,$len);fn unsigned_abs(self)->Self::Unsigned{self}fn abs(self)->Self{self}}};($it:ty,$ut:ty)=>{integer!($it,$ut,base_10_len!($ut));};}integer!(i8,u8);integer!(i16,u16);integer!(i32,u32);integer!(i64,u64);integer!(i128,u128);integer!(isize,usize);}
        pub mod rlib_io {use crate::__cargo_equip::preludes::rlib_io::*;pub use crate::__cargo_equip::macros::rlib_io::*;pub mod output_macro{use crate::__cargo_equip::preludes::rlib_io::*;#[macro_export]macro_rules!__cargo_equip_macro_def_rlib_io_out_impl{($writer:ident,$x:expr)=>{$writer.write(&$x);};($writer:ident,$x:expr,$($xx:tt)*)=>{$writer.write(&$x);$writer.write_char(' ');rlib_io::out_impl!($writer,$($xx)*);};}macro_rules!out_impl{($($tt:tt)*)=>(crate::__cargo_equip_macro_def_rlib_io_out_impl!{$($tt)*})}#[macro_export]macro_rules!__cargo_equip_macro_def_rlib_io_make_output_macro_{($writer:ident)=>{make_output_macro_!($writer,$);};($writer:ident,$dol:tt)=>{#[allow(unused_macros)]macro_rules!out{($dol($dol x:tt)*)=>{rlib_io::out_impl!($writer,$dol($dol x)*);};}#[allow(unused_macros)]macro_rules!outln{()=>{$writer.write_char('\n');};($dol($dol x:tt)*)=>{rlib_io::out_impl!($writer,$dol($dol x)*);$writer.write_char('\n');};}}}macro_rules!make_output_macro_{($($tt:tt)*)=>(crate::__cargo_equip_macro_def_rlib_io_make_output_macro_!{$($tt)*})}pub use crate::__cargo_equip::crates::rlib_io::make_output_macro_ as make_output_macro;}pub mod reader{use crate::__cargo_equip::preludes::rlib_io::*;use std::io::Read;pub struct Reader{buf:[u8;Reader::BUF_SIZE],begin:usize,end:usize,stdin:Box<dyn Read>,eof:bool,}impl Reader{const BUF_SIZE:usize=1<<16;pub fn new(stdin:Box<dyn Read>)->Self{Self{buf:[0;Reader::BUF_SIZE],begin:0,end:0,stdin,eof:false,}}pub fn read<T:Readable>(&mut self)->T{T::read(self)}pub fn read_vec<T:Readable>(&mut self,n:usize)->Vec<T>{let mut result=Vec::<T>::with_capacity(n);for _ in 0..n{result.push(self.read());}result}fn refill(&mut self){if self.eof{return;}if self.begin!=0{self.buf.copy_within(self.begin..self.end,0);self.end-=self.begin;self.begin=0;}let bytes=self.stdin.read(&mut self.buf[self.end..]).unwrap();if bytes==0{self.eof=true;}self.end+=bytes;}fn skip_whitespace(&mut self){while{if self.begin==self.end{self.refill();}!self.eof&&self.peek().is_ascii_whitespace()}{self.begin+=1;if self.begin==self.end{self.refill();}}}fn peek(&mut self)->u8{if self.begin==self.end{self.refill();}self.buf[self.begin]}}pub trait Readable{fn read(reader:&mut Reader)->Self;}impl Readable for String{fn read(reader:&mut Reader)->Self{reader.skip_whitespace();let mut result=String::new();let mut read_something=false;while{if reader.begin==reader.end{reader.refill();}!reader.eof&&!reader.peek().is_ascii_whitespace()}{result.push(reader.peek()as char);reader.begin+=1;read_something=true;}debug_assert!(read_something);result}}macro_rules!read_signed{($t:ty)=>{impl Readable for$t{fn read(reader:&mut Reader)->Self{reader.skip_whitespace();let mut result:$t=0;let mut read_something=false;if reader.peek()==b'-'{reader.begin+=1;while{if reader.begin==reader.end{reader.refill();}!reader.eof&&!reader.peek().is_ascii_whitespace()}{debug_assert!(reader.buf[reader.begin].is_ascii_digit());result=result*10-(reader.buf[reader.begin]-('0' as u8))as$t;reader.begin+=1;read_something=true;}}else{while{if reader.begin==reader.end{reader.refill();}!reader.eof&&!reader.peek().is_ascii_whitespace()}{debug_assert!(reader.buf[reader.begin].is_ascii_digit());result=result*10+(reader.buf[reader.begin]-('0' as u8))as$t;reader.begin+=1;read_something=true;}}debug_assert!(read_something);result}}};}macro_rules!read_unsigned{($t:ty)=>{impl Readable for$t{fn read(reader:&mut Reader)->Self{reader.skip_whitespace();let mut result:$t=0;let mut read_something=false;while{if reader.begin==reader.end{reader.refill();}!reader.eof&&!reader.peek().is_ascii_whitespace()}{debug_assert!(reader.buf[reader.begin].is_ascii_digit());result=result*10+(reader.buf[reader.begin]-('0' as u8))as$t;reader.begin+=1;read_something=true;}debug_assert!(read_something);result}}};}read_signed!(i8);read_signed!(i16);read_signed!(i32);read_signed!(i64);read_signed!(i128);read_signed!(isize);read_unsigned!(u8);read_unsigned!(u16);read_unsigned!(u32);read_unsigned!(u64);read_unsigned!(u128);read_unsigned!(usize);macro_rules!read_tuple{($($t:ident),*)=>{impl<$($t:Readable,)*>Readable for($($t,)*){fn read(reader:&mut Reader)->Self{($($t::read(reader)),*)}}}}read_tuple!(A,B);read_tuple!(A,B,C);read_tuple!(A,B,C,D);read_tuple!(A,B,C,D,E);read_tuple!(A,B,C,D,E,F);read_tuple!(A,B,C,D,E,F,G);read_tuple!(A,B,C,D,E,F,G,H);}pub mod writer{use crate::__cargo_equip::preludes::rlib_io::*;use std::io::Write;use rlib_integer::Integer;pub struct Writer<'a>{buf:[u8;Writer::BUF_SIZE],end:usize,stdout:Box<dyn Write+'a>,}impl<'a>Writer<'a>{const BUF_SIZE:usize=1<<16;pub fn new(stdout:Box<dyn Write+'a>)->Self{Self{buf:[0;Writer::BUF_SIZE],end:0,stdout,}}pub fn write<T:Writable>(&mut self,t:&T){t.write(self);#[cfg(debug_assertions)]self.flush();}pub fn write_char(&mut self,c:char){self.write_bytes(&[c as u8]);#[cfg(debug_assertions)]self.flush();}fn flush(&mut self){if self.end==0{return;}self.stdout.write_all(&self.buf[..self.end]).unwrap();self.end=0;}fn reserve(&mut self,size:usize){if self.end+size>self.buf.len(){self.flush();}}fn write_bytes(&mut self,buf:&[u8]){self.reserve(buf.len());self.buf[self.end..self.end+buf.len()].copy_from_slice(buf);self.end+=buf.len();}}impl Drop for Writer<'_>{fn drop(&mut self){self.flush();}}pub trait Writable{fn write(&self,writer:&mut Writer);}impl Writable for&str{fn write(&self,writer:&mut Writer){for chunk in self.as_bytes().chunks(Writer::BUF_SIZE){writer.write_bytes(chunk);}}}impl Writable for String{fn write(&self,writer:&mut Writer){for chunk in self.as_bytes().chunks(Writer::BUF_SIZE){writer.write_bytes(chunk);}}}impl<T:Writable>Writable for Vec<T>{fn write(&self,writer:&mut Writer){for(i,value)in self.iter().enumerate(){if i!=0{writer.write_char(' ');}writer.write(value);}}}macro_rules!write_unsigned{($t:ty)=>{impl Writable for$t{fn write(&self,writer:&mut Writer){if self==&0{writer.write_char('0');return;}let mut buf=[0;<$t as Integer>::BASE_10_LEN];let mut index=buf.len();let mut value=*self;while value!=0{index-=1;buf[index]=(value%10)as u8+b'0';value/=10;}writer.write_bytes(&buf[index..]);}}};}macro_rules!write_signed{($t:ty)=>{impl Writable for$t{fn write(&self,writer:&mut Writer){if self<&0{writer.write_char('-');}writer.write(&self.unsigned_abs());}}};}write_signed!(i8);write_signed!(i16);write_signed!(i32);write_signed!(i64);write_signed!(i128);write_signed!(isize);write_unsigned!(u8);write_unsigned!(u16);write_unsigned!(u32);write_unsigned!(u64);write_unsigned!(u128);write_unsigned!(usize);macro_rules!write_tuple{($t1:ident,$($t:ident),*)=>{impl<$t1:Writable,$($t:Writable,)*>Writable for($t1,$($t,)*){fn write(&self,writer:&mut Writer){#[allow(non_snake_case)]let($t1,$($t,)*)=self;writer.write($t1);$(writer.write_char(' ');writer.write($t);)*}}}}write_tuple!(A,B);write_tuple!(A,B,C);write_tuple!(A,B,C,D);write_tuple!(A,B,C,D,E);write_tuple!(A,B,C,D,E,F);write_tuple!(A,B,C,D,E,F,G);write_tuple!(A,B,C,D,E,F,G,H);}pub use output_macro::make_output_macro;pub use reader::{Readable,Reader};pub use writer::{Writable,Writer};#[macro_export]macro_rules!__cargo_equip_macro_def_rlib_io_make_io{($reader:ident,$writer:ident)=>{#[allow(unused_variables)]let mut$reader=rlib_io::reader::Reader::new(Box::new(std::io::stdin().lock()));#[allow(unused_variables)]let mut$writer=rlib_io::writer::Writer::new(Box::new(std::io::stdout().lock()));rlib_io::output_macro::make_output_macro!($writer);};}macro_rules!make_io{($($tt:tt)*)=>(crate::__cargo_equip_macro_def_rlib_io_make_io!{$($tt)*})}}
    }

    pub(crate) mod macros {
        pub mod rlib_integer {}
        pub mod rlib_io {pub use crate::{__cargo_equip_macro_def_rlib_io_make_io as make_io,__cargo_equip_macro_def_rlib_io_make_output_macro_ as make_output_macro_,__cargo_equip_macro_def_rlib_io_out_impl as out_impl};}
    }

    pub(crate) mod prelude {pub use crate::__cargo_equip::crates::*;}

    mod preludes {
        pub mod rlib_integer {}
        pub mod rlib_io {pub(in crate::__cargo_equip)use crate::__cargo_equip::crates::rlib_integer;}
    }
}