#include <bits/stdc++.h>

/* time-complexity - O(log(n)) */
int32_t power_function(int32_t base, int32_t exponent)
{
    if (exponent == 0)
    {
        /* base case when exponent is zero */
        return 1;
    }
    else
    {
        int32_t temp_value{power_function(base, exponent / 2)};

        if (exponent % 2 == 0)
        {
            /* if exponent is an even number */
            return temp_value * temp_value;
        }
        else
        {
            /* if exponent is an odd number */
            return base * temp_value * temp_value;
        }
    }
}

int32_t main(int32_t argc, char *argv[])
{
    /* fast input-output */
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);
    std::cout.tie(nullptr);

    /* define seed_value for random_generator */
    auto seed_value{std::chrono::system_clock::now().time_since_epoch().count()};

    /* declare random_generator with seeded value */
    std::mt19937 random_generator(seed_value);

    /* define range for random numbers */
    int32_t left_bound{1}, right_bound{8};
    std::uniform_int_distribution<int32_t> distinct(left_bound, right_bound);

    /* get base */
    int32_t base{distinct(random_generator)};

    /* get exponent */
    int32_t exponent{distinct(random_generator)};

    /* print appropriate message */
    std::cout << base << " ^ " << exponent << " = ";
    std::cout << power_function(base, exponent) << "\n";

    return 0;
}