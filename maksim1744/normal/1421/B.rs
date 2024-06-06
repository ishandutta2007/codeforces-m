
/*
    author:  Maksim1744
    created: 18.10.2020 12:09:55
*/

#[allow(unused_imports)]
use std::{
    io,
    collections::*,
    cmp::{min, max},
    time::{Instant},
    fmt::Write,
};

fn test_case(_test: &i32, io: &mut IO) {
    macro_rules! output { ($($args:expr),+) => { write!(&mut io.out_buf, $($args),+).unwrap(); }; }

    let n: usize = io.read();
    let mut v: Vec<Vec<i32>> = Vec::new();
    for i in 0..n {
        let s = io.reads();
        v.push(Vec::new());
        for &c in s.iter() {
            if c == b'1' {
                v[i].push(1);
            } else {
                v[i].push(0);
            }
        }
    }

    let mut cnt1 = 0;
    if v[0][1] == 0 {
        cnt1 += 1;
    }
    if v[1][0] == 0 {
        cnt1 += 1;
    }
    if v[n - 1][n - 2] == 1 {
        cnt1 += 1;
    }
    if v[n - 2][n - 1] == 1 {
        cnt1 += 1;
    }

    let mut ans:Vec<(usize, usize)> = Vec::new();
    let mut w1 = 0;
    let mut w2 = 1;
    if cnt1 < 2 {
        w1 = 1;
        w2 = 0;
    }
    if v[0][1] != w1 {
        ans.push((1, 2));
    }
    if v[1][0] != w1 {
        ans.push((2, 1));
    }
    if v[n - 1][n - 2] != w2 {
        ans.push((n, n - 1));
    }
    if v[n - 2][n - 1] != w2 {
        ans.push((n - 1, n));
    }
    output!("{}\n", ans.len());
    for (a, b) in ans.iter() {
        output!("{} {}\n", a, b);
    }
}

fn main() {
    #[cfg(HOME)]
    let now = Instant::now();

    let mut io = IO::new();

    let t = io.read::<i32>();
    // let t = 1;
    for test in 1..t + 1 {
        test_case(&test, &mut io);
    }

    io.flush();

    #[cfg(HOME)] {
        let d = now.elapsed();
        eprintln!("total: {}", d.as_secs() as f64 + d.subsec_nanos() as f64 * 1e-9);
    }
}

// ********************************************************************************

#[allow(dead_code)]
struct IO {
    buf: std::collections::VecDeque<String>,
    out_buf: String,
}
#[allow(dead_code)]
impl IO {
    fn new() -> IO {
        IO {
            buf: std::collections::VecDeque::new(),
            out_buf: String::new(),
        }
    }

    fn flush(&mut self) {
        print!("{}", self.out_buf);
        self.out_buf.clear();
    }

    fn read<T: std::str::FromStr>(&mut self) -> T {
        while self.buf.is_empty() {
            let mut s = String::new();
            io::stdin().read_line(&mut s).expect("Can't read a line");
            self.buf.extend(s.trim().split(" ").map(|x| x.to_string()));
        }
        self.buf.pop_front().unwrap().parse().ok().unwrap()
    }
    fn readv<T: std::str::FromStr>(&mut self, n: usize) -> Vec<T> {
        let mut res = Vec::new();
        for _i in 0..n {
            res.push(self.read());
        }
        res
    }
    fn readv2<T: std::str::FromStr>(&mut self, n: usize, m: usize) -> Vec<Vec<T>> {
        let mut res = Vec::new();
        for _i in 0..n {
            res.push(self.readv(m));
        }
        res
    }
    fn reads(&mut self) -> Vec<u8> {
        self.read::<String>().as_bytes().to_vec()
    }

    fn debug<T: std::fmt::Debug>(&mut self, _val: &T, _name: &str) {
        #[cfg(HOME)]
        {
            eprint!("    ");
            eprint!("{}", match _name {
                "" => "<val>",
                x => x
            });
            eprintln!(" = {:?}", _val);
        }
    }
    fn debugs(&mut self, _val: &Vec<u8>, _name: &str) {
        #[cfg(HOME)]
        {
            eprint!("    ");
            eprint!("{}", match _name {
                "" => "<val>",
                x => x
            });
            eprintln!(" = {:?}", std::str::from_utf8(_val).unwrap());
        }
    }
}