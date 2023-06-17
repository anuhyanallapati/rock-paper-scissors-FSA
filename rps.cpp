#include <bits/stdc++.h>
using namespace std;

typedef vector<tuple<char, int, int, int>> store;

int win_or_lose(char my_state, char inp_state)
{
    int chk = 0;
    if (my_state == 'R')
    {
        if (inp_state == 'R')
        {
            chk = -1;
        }
        else if (inp_state == 'P')
        {
            chk = -1;
        }
        // inp_state == 'S'
        else
        {
            chk = 1;
        }
    }
    else if (my_state == 'P')
    {
        if (inp_state == 'R')
        {
            chk = 1;
        }
        else if (inp_state == 'P')
        {
            chk = -1;
        }
        // inp_tate == 'S'
        else
        {
            chk = -1;
        }
    }
    // my_state == 'S'
    else
    {
        if (inp_state == 'R')
        {
            chk = -1;
        }
        else if (inp_state == 'P')
        {
            chk = 1;
        }
        // inp_state == 'S'
        else
        {
            chk = -1;
        }
    }
    return chk;
}

int main()
{
    tuple<char, int, int, int> temp_tuple;

    srand(time(0));

    int no_of_states;
    cin >> no_of_states;

    char name_of_state;
    int r;
    int p;
    int s;

    store inp_;

    // taking input
    int cnt = 0;
    while (cnt < no_of_states)
    {
        cin >> name_of_state >> r >> p >> s;
        inp_.push_back(make_tuple(name_of_state, r, p, s));
        cnt++;
    }

    store outp_;

    char var[1];
    int var_;

    for (int i = 0; i < no_of_states; i++)
    {
        outp_.push_back(make_tuple('a', 1 + (rand() % no_of_states), 1 + (rand() % no_of_states), 1 + (rand() % no_of_states)));

        if (get<0>(inp_[i]) == 'R')
        {
            // changing 'R' to 'P'
            get<0>(outp_[i]) = 'P';
            var_ = 2;

            // changing (i,1) will be equal to (i,2)
            get<1>(outp_[i]) = get<2>(inp_[i]);

            // changing the other three
            for (int j = 1; j < 4; j++)
            {
                if (j == 2)
                {
                    int k = 0;
                    // jth coloumn of ith row : get<j>(outp_[i])
                    while (k < no_of_states)
                    {
                        // if (get<0>(inp_[k]) == var)
                        if (get<0>(inp_[k]) == 'P')
                        {
                            get<2>(outp_[i]) = get<2>(inp_[k]);
                            break;
                        }
                        k++;
                    }
                }
                else if (j == 3)
                {
                    int k = 0;
                    // jth coloumn of ith row : get<j>(outp_[i])
                    while (k < no_of_states)
                    {
                        // if (get<0>(inp_[k]) == var)
                        if (get<0>(inp_[k]) == 'S')
                        {
                            get<3>(outp_[i]) = get<2>(inp_[k]);
                            break;
                        }
                        k++;
                    }
                }
            }
        }

        if (get<0>(inp_[i]) == 'P')
        {
            // changing 'P' to 'S'
            get<0>(outp_[i]) = 'S';
            var_ = 3;

            // changing (i,2) will be equal to (i,3)
            get<2>(outp_[i]) = get<3>(inp_[i]);

            // changing the other three
            for (int j = 1; j < 4; j++)
            {
                if (j == 1)
                {
                    int k = 0;
                    // jth coloumn of ith row : get<j>(outp_[i])
                    while (k < no_of_states)
                    {
                        if (get<0>(inp_[k]) == 'R')
                        {
                            get<1>(outp_[i]) = get<3>(inp_[k]);
                            break;
                        }
                        k++;
                    }
                }
                else if (j == 3)
                {
                    int k = 0;
                    // jth coloumn of ith row : get<j>(outp_[i])
                    while (k < no_of_states)
                    {
                        if (get<0>(inp_[k]) == 'S')
                        {
                            get<3>(outp_[i]) = get<3>(inp_[k]);
                            break;
                        }
                        k++;
                    }
                }
            }
        }

        if (get<0>(inp_[i]) == 'S')
        {
            // changing 'S' to 'R'
            get<0>(outp_[i]) = 'R';
            var_ = 1;

            // changing (i,3) will be equal to (i,1)
            get<3>(outp_[i]) = get<1>(inp_[i]);

            // changing the other three
            for (int j = 1; j < 4; j++)
            {
                if (j == 1)
                {
                    int k = 0;
                    // jth coloumn of ith row : get<j>(outp_[i])
                    while (k < no_of_states)
                    {
                        if (get<0>(inp_[k]) == 'R')
                        {
                            get<1>(outp_[i]) = get<1>(inp_[k]);
                            break;
                        }
                        k++;
                    }
                }
                else if (j == 2)
                {
                    int k = 0;
                    // jth coloumn of ith row : get<j>(outp_[i])
                    while (k < no_of_states)
                    {
                        if (get<0>(inp_[k]) == 'P')
                        {
                            get<2>(outp_[i]) = get<1>(inp_[k]);
                            break;
                        }
                        k++;
                    }
                }
            }
        }
    }

    char my_state;
    my_state = get<0>(outp_[0]);
    int cnt_for_change = 1;

    // for loop to go through all states and make them start states
    for (int i = 1; i < no_of_states; i++)
    {
        int my_cnt = 0;
        int counter[100];
        for (int j = 0; j < 100; j++)
        {
            counter[j] = 0;
        }
        char inp_state;
        char prev_inp_state;

        // int cnt_for_change = 1;
        char prev_outp_state;

        // for each input state
        inp_state = get<0>(inp_[i]);
        prev_inp_state = inp_state;

        prev_outp_state = my_state;

        int inp_state_num = i + 1;
        int my_state_num = 1;

        my_state = get<0>(outp_[0]);

        int flag = 0;

        int prev_inp_state_num = 0;
        int prev_outp_state_num = 0;

        for (int j = 0; j < 100; j++)
        {
            prev_inp_state = inp_state;
            prev_outp_state = my_state;

            prev_inp_state_num = inp_state_num;
            prev_outp_state_num = my_state_num;

            // changing state i.e. going to the next state
            if (my_state == 'R')
            {
                if (inp_state == 'R')
                {
                    // same row, 1st coloumn
                    // changing state of input fsa
                    inp_state_num = get<1>(inp_[inp_state_num - 1]);
                    inp_state = get<0>(inp_[inp_state_num - 1]);

                    // same row, 1st coloumn
                    // changing state of output fsa
                    my_state_num = get<1>(outp_[my_state_num - 1]);
                    my_state = get<0>(outp_[my_state_num - 1]);
                }
                else if (inp_state == 'P')
                {
                    // same row, 1st coloumn
                    // changing state of input fsa
                    inp_state_num = get<1>(inp_[inp_state_num - 1]);
                    inp_state = get<0>(inp_[inp_state_num - 1]);

                    // same row, 2nd coloumn
                    // changing state of output fsa
                    my_state_num = get<2>(outp_[my_state_num - 1]);
                    my_state = get<0>(outp_[my_state_num - 1]);
                }
                // inp_state == 'S'
                else
                {
                    // same row, 1st coloumn
                    // changing state of input fsa
                    inp_state_num = get<1>(inp_[inp_state_num - 1]);
                    inp_state = get<0>(inp_[inp_state_num - 1]);

                    // same row, 3rd coloumn
                    // changing state of output fsa
                    my_state_num = get<3>(outp_[my_state_num - 1]);
                    my_state = get<0>(outp_[my_state_num - 1]);
                }
            }
            else if (my_state == 'P')
            {
                if (inp_state == 'R')
                {
                    // same row, 2nd coloumn
                    // changing state of input fsa
                    inp_state_num = get<2>(inp_[inp_state_num - 1]);
                    inp_state = get<0>(inp_[inp_state_num - 1]);

                    // same row, 1st coloumn
                    // changing state of output fsa
                    my_state_num = get<1>(outp_[my_state_num - 1]);
                    my_state = get<0>(outp_[my_state_num - 1]);
                }
                else if (inp_state == 'P')
                {
                    // same row, 2nd coloumn
                    // changing state of input fsa
                    inp_state_num = get<2>(inp_[inp_state_num - 1]);
                    inp_state = get<0>(inp_[inp_state_num - 1]);

                    // same row, 2nd coloumn
                    // changing state of output fsa
                    my_state_num = get<2>(outp_[my_state_num - 1]);
                    my_state = get<0>(outp_[my_state_num - 1]);
                }
                // inp_tate == 'S'
                else
                {
                    // same row, 2nd coloumn
                    // changing state of input fsa
                    inp_state_num = get<2>(inp_[inp_state_num - 1]);
                    inp_state = get<0>(inp_[inp_state_num - 1]);

                    // same row, 3rd coloumn
                    // changing state of output fsa
                    my_state_num = get<3>(outp_[my_state_num - 1]);
                    my_state = get<0>(outp_[my_state_num - 1]);
                }
            }
            // my_state == 'S'
            else
            {
                if (inp_state == 'R')
                {
                    // same row, 3rd coloumn
                    // changing state of input fsa
                    inp_state_num = get<3>(inp_[inp_state_num - 1]);
                    inp_state = get<0>(inp_[inp_state_num - 1]);

                    // same row, 1st coloumn
                    // changing state of output fsa
                    my_state_num = get<1>(outp_[my_state_num - 1]);
                    my_state = get<0>(outp_[my_state_num - 1]);
                }
                else if (inp_state == 'P')
                {
                    // same row, 3rd coloumn
                    // changing state of input fsa
                    inp_state_num = get<3>(inp_[inp_state_num - 1]);
                    inp_state = get<0>(inp_[inp_state_num - 1]);

                    // same row, 2nd coloumn
                    // changing state of output fsa
                    my_state_num = get<2>(outp_[my_state_num - 1]);
                    my_state = get<0>(outp_[my_state_num - 1]);
                }
                // inp_state == 'S'
                else
                {
                    // same row, 3rd coloumn
                    // changing state of input fsa
                    inp_state_num = get<3>(inp_[inp_state_num - 1]);
                    inp_state = get<0>(inp_[inp_state_num - 1]);

                    // same row, 3rd coloumn
                    // changing state of output fsa
                    my_state_num = get<3>(outp_[my_state_num - 1]);
                    my_state = get<0>(outp_[my_state_num - 1]);
                }
            }

            counter[j] = win_or_lose(my_state, inp_state);
            if (j < 1 || counter[j] != -1)
            {
                continue;
            }
            my_cnt++;

            if (my_cnt == cnt_for_change)
            {
                cnt_for_change++;

                my_cnt = 0;
                if (prev_inp_state == 'R')
                {
                    get<1>(outp_[prev_outp_state_num - 1]) = inp_state_num;
                }
                else if (prev_inp_state == 'P')
                {
                    get<2>(outp_[prev_outp_state_num - 1]) = inp_state_num;
                }
                else
                {
                    get<3>(outp_[prev_outp_state_num - 1]) = inp_state_num;
                }
            }

        }
    }

    cout << no_of_states << endl;

    for (int i = 0; i < no_of_states; i++)
    {
        cout << get<0>(outp_[i]) << " " << get<1>(outp_[i]) << " " << get<2>(outp_[i]) << " " << get<3>(outp_[i]) << endl;
    }
}
