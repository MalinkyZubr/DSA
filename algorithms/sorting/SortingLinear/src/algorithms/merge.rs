pub fn merge_sort(input_slice: &mut [i32]) -> &mut [i32] {
    if input_slice.len() == 1
    {
        return input_slice;
    }
    let (mut first_half, mut second_half) = input_slice.split_at_mut(input_slice.len() / 2);
    first_half = merge_sort(first_half);
    second_half = merge_sort(second_half);
    
    let (mut fi, mut si) = (0, 0);

    let mut merged: Vec<i32> = Vec::new();

    while fi < first_half.len() && si < second_half.len()
    {
        if first_half[fi] < second_half[si]
        {
            merged.push(first_half[fi]);
            fi += 1;
        }
        else
        {
            merged.push(second_half[si]);
            si += 1;
        }
    }

    while fi < first_half.len()
    {
        merged.push(first_half[fi]);
        fi += 1;
    }

    while si < second_half.len()
    {
        merged.push(second_half[si]);
        si += 1;
    }

    input_slice.copy_from_slice(&merged);

    input_slice
}