#ifndef EPSILON_H
#define EPSILON_H

template <typename TValue>
TValue epsilon()
{
    return epsilon_real<TValue>(std::is_floating_point<TValue>());
}

template <typename TValue>
TValue epsilon_real(std::true_type)
{
    return 1e-5;
}

template <typename TValue>
TValue epsilon_real(std::false_type)
{
    return TValue();
}
#endif