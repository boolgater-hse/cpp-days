#ifndef EXAM_MERGE_OUTPUT_HPP
#define EXAM_MERGE_OUTPUT_HPP

template <typename A, typename B, typename C>
void merge(const A& one, const B& two, C& dest)
{
    for (auto it = one.begin(); it != one.end(); ++it)
    {
        dest.insert(dest.end(), *it);
    }
    for (auto it = two.begin(); it != two.end(); ++it)
    {
        dest.insert(dest.end(), *it);
    }
}

template <typename A, typename B>
A& output(A& buffer, const B& other)
{
    for (auto it: other)
    {
        buffer << it << ' ';
    }

    return buffer;
}

#endif // EXAM_MERGE_OUTPUT_HPP
