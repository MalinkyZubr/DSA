use rand::Rng;
use rand::rngs::ThreadRng;
use std::time::Instant;
use std::env;

mod algorithms;

use algorithms::{insertion, merge, quicksort};

const LENGTH: usize = 100000;

fn main() {
    //env::set_var("RUST_BACKTRACE", "1");
    let mut data: [i32; LENGTH] = [0; LENGTH];
    let mut rng = rand::thread_rng();
    
    data = random_generator(&mut rng, data);
    let mut now = Instant::now();
    println!("Running insertion sort...");
    insertion::insertion_sort(&mut data);
    println!("Insertion sort {:?}", now.elapsed());

    data = random_generator(&mut rng, data);
    now = Instant::now();
    println!("Running merge sort...");
    merge::merge_sort(&mut data);
    println!("Merge sort {:?}", now.elapsed());

    data = random_generator(&mut rng, data);
    now = Instant::now();
    println!("Running quick sort...");
    quicksort::quicksort(&mut data);
    println!("Quicksort {:?}", now.elapsed());
}

fn random_generator(rng: &mut ThreadRng, mut data: [i32; LENGTH]) -> [i32; LENGTH] {
    for value in data.iter_mut()
    {
        *value += rng.gen_range(0..10000);
    }
    return data;
}