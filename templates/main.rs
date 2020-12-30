#![allow(unused_imports)]
use std::cmp::{max, min};
use std::io::{self, prelude::*};

fn solve<R: BufRead, W: Write>(mut input: Scanner<R>, mut w: W) {
    writeln!(w, "come to compete?");
}

fn main() {
    let (stdin, stdout) = (io::stdin(), io::stdout());
    let input = Scanner::from(stdin.lock());
    let writer = io::BufWriter::new(stdout.lock());
    solve(input, writer);
}

#[derive(Default)]
struct Scanner<B> {
    reader: B,
    buffer: Vec<String>,
}
impl<R: BufRead> Scanner<R> {
    pub fn token<T: std::str::FromStr>(&mut self) -> T {
        loop {
            if let Some(token) = self.buffer.pop() {
                return token.parse().ok().expect("Failed parse");
            }
            let mut input = String::new();
            self.reader.read_line(&mut input).expect("Failed read");
            self.buffer = input.split_whitespace().rev().map(String::from).collect();
        }
    }
}
impl<R: BufRead> From<R> for Scanner<R> {
    fn from(reader: R) -> Self {
        Self {
            reader,
            buffer: Vec::new(),
        }
    }
}
