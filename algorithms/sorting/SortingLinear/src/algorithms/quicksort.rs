pub fn quicksort(input_slice: &mut [i32]) -> &mut [i32] {
    if input_slice.len() <= 1
    {
        return input_slice;
    }
    let mut pivot_index: usize = input_slice.len() - 1;
    while pivot_index > 0 && input_slice[pivot_index] < input_slice[pivot_index - 1]
    {
        let tmp: i32 = input_slice[pivot_index];
        input_slice[pivot_index] = input_slice[pivot_index - 1];
        input_slice[pivot_index - 1] = tmp;
        pivot_index -= 1;
    }
    let pivot = input_slice[pivot_index];
    let (mut partition1, mut partition2) = input_slice.split_at_mut(pivot_index);
    partition2 = &mut partition2[1..];

    let mut re_assembled = Vec::new();

    partition1 = quicksort(partition1);
    partition2 = quicksort(partition2);

    re_assembled.extend_from_slice(&partition1);
    re_assembled.push(pivot);
    re_assembled.extend_from_slice(&partition2);



    input_slice.copy_from_slice(&re_assembled);

    return input_slice;
}