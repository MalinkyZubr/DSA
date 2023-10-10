fn get_place(depth: i32, number: i32) -> i32 {
    (number / 10**depth) % 10
}

fn int_log(num: i32) -> i32 {
    let mut digits = 0;
    while num > 0
    {
        num /= 10;
        digits += 1;
    }
    return digits;
}

fn radix_sort_internal(input_slice: &mut [i32], depth: i32, max_depth: i32) -> &mut [i32] {

}

pub fn radix_sort(input_slice: &mut [i32]) -> &mut [i32] {
    let max_depth: i32 = int_log(*input_slice.iter().max().unwrap());
    return radix_sort_internal(&mut input_slice, 0, max_depth);
}