use bracket::*;
use element::*;
use operator::*;

fn main() {
    let input = vec![num(6 as f64), ope(plus), num(8 as f64)];
    let input = vec![
        num(1 as f64),
        ope(plus),
        num(2 as f64),
        ope(multiply),
        bra(bracket::left),
        num(3 as f64),
        ope(minus),
        num(4 as f64),
        bra(bracket::right),
        ope(division),
        num(5 as f64),
    ];
    // (1+2)*3-(4/5)
    let input = vec![
        bra(left),
        num(1 as f64),
        ope(plus),
        num(2 as f64),
        bra(right),
        ope(multiply),
        num(3 as f64),
        ope(minus),
        bra(left),
        num(4 as f64),
        ope(division),
        num(5 as f64),
        bra(right),
    ];
    // ((1+2)*3-4/5)+6*(7/8-9)
    let input = vec![
        bra(left),
        bra(left),
        num(1 as f64),
        ope(plus),
        num(2 as f64),
        bra(right),
        ope(multiply),
        num(3 as f64),
        ope(minus),
        num(4 as f64),
        ope(division),
        num(5 as f64),
        bra(right),
        ope(plus),
        num(6 as f64),
        ope(multiply),
        bra(left),
        num(7 as f64),
        ope(division),
        num(8 as f64),
        ope(minus),
        num(9 as f64),
        bra(right),
    ];
    // ((A + B * C) / (D - E) * F) + (G / H - I) * J
    let input = vec![
        bra(left),
        bra(left),
        num(1 as f64),
        ope(plus),
        num(2 as f64),
        ope(multiply),
        num(3 as f64),
        bra(right),
        ope(division),
        bra(left),
        num(4 as f64),
        ope(minus),
        num(5 as f64),
        bra(right),
        ope(multiply),
        num(6 as f64),
        bra(right),
        ope(plus),
        bra(left),
        num(7 as f64),
        ope(division),
        num(8 as f64),
        ope(minus),
        num(9 as f64),
        bra(right),
        ope(multiply),
        num(10 as f64),
    ];
    // ((A + B * C) / (D - E) * F) + (G / H - I) * J
    println!("{:?}", input);
    println!("{:?}", convert(input));
}

#[derive(Debug)]
enum operator {
    plus,
    minus,
    multiply,
    division,
}

#[derive(Debug)]
enum bracket {
    right,
    left,
}

#[derive(Debug)]
enum element {
    ope(operator),
    num(f64),
    bra(bracket),
}

impl operator {
    fn precedence(&self) -> u8 {
        match self {
            operator::plus | operator::minus => 1,
            operator::multiply | operator::division => 2,
        }
    }
}

fn convert(source: Vec<element>) -> Vec<element> {
    let mut result: Vec<element> = vec![];
    let mut hold: Vec<element> = vec![];
    for elem in source {
        println!();
        println!("result: {:?}", result);
        println!("hold: {:?}", hold);
        match elem {
            element::num(number) => hold.push(element::num(number)),
            element::ope(operator) => {
                let mut put_back = loop {
                    match result.pop() {
                        None => {
                            break 0;
                        }
                        Some(elem) => match elem {
                            element::num(n) => hold.push(element::num(n)),
                            element::ope(o) => {
                                if operator.precedence() > o.precedence() {
                                    result.push(element::ope(o));
                                    break 1;
                                } else {
                                    hold.push(element::ope(o));
                                }
                            }
                            element::bra(bracket::right) => {
                                println!("I am in!!!");
                                hold.push(bra(right));
                                let mut i = 1;
                                while i > 0 {
                                    let out = result.pop().unwrap();
                                    match out {
                                        bra(right) => i += 1,
                                        bra(left) => i -= 1,
                                        _ => (),
                                    }
                                    hold.push(out);
                                    println!("result: {:?}", result);
                                    println!("hold: {:?}", hold);
                                }
                                println!("I am out!!!");
                            }
                            element::bra(bracket::left) => {
                                result.push(element::bra(bracket::left));
                                break 0;
                            }
                        },
                    };
                };
                println!("I am in!!!");
                while put_back > 0 {
                    match hold.pop().unwrap() {
                        num(n) => {
                            result.push(num(n));
                            put_back -= 1;
                        }
                        ope(o) => {
                            result.push(ope(o));
                            put_back += 1;
                        }
                        bra(left) => {
                            result.push(bra(left));
                            let mut i = 1;
                            while i > 0 {
                                let out = hold.pop().unwrap();
                                match out {
                                    bra(right) => i -= 1,
                                    bra(left) => i += 1,
                                    _ => (),
                                }
                                result.push(out);
                            }
                            put_back -= 1;
                        }
                        bra(right) => panic!("wtf"),
                    }
                    println!("result: {:?}", result);
                    println!("hold: {:?}", hold);
                }
                println!("I am out!!!");
                result.push(element::ope(operator));
                while !hold.is_empty() {
                    result.push(hold.pop().unwrap());
                }
            }
            element::bra(left) => result.push(element::bra(left)),
            element::bra(right) => {
                while !hold.is_empty() {
                    result.push(hold.pop().unwrap());
                }
                result.push(element::bra(right));
            }
        }
    }

    while !hold.is_empty() {
        result.push(hold.pop().unwrap());
    }

    println!("result: {:?}", result);

    result
        .into_iter()
        .filter(|a| match a {
            bra(_) => false,
            _ => true,
        })
        .collect()
}
