pub fn insertion_sort(input_array: &mut [i32]) -> &[i32] {
    for i in 1..input_array.len()
    {
        let mut sorting_index: usize = i;
        while sorting_index > 0 && input_array[sorting_index] < input_array[sorting_index - 1]
        {
            let tmp = input_array[sorting_index];
            input_array[sorting_index] = input_array[sorting_index - 1];
            input_array[sorting_index - 1] = tmp;
            sorting_index -= 1;
        }
    }
    input_array
}