/*
link: https://www.codingninjas.com/codestudio/problems/873366?topList=striver-sde-sheet-problems&utm_source=striver&utm_medium=website&leftPanelTab=0
TC: O(n)
SC: O(1)
Method:

We know that XOR of a number with itself is 0. 

1. Calculate XOR of all the elements of the array.
        findXOR = arr[0]^arr[1]^arr[2]…..arr[n-1]
2. Now, XOR the result with all numbers from 1 to n.
        findXOR = (findXOR)^1^2^…..^n.

3. Now, findXOR will contain the XOR of the missing number and the repeating number as all the numbers would nullify each other.

4. All the set bits in findXOR will be in either the missing number or the repeating number. Using any set bit in the findXOR, let's say 
   the rightmost set bit, we can divide the elements of the given array in two sets.
        1. In the first set, we have the elements with the same bit set.
        2. In the second set, we have all the elements with the same bit not set.

5. Initialize two variables, ‘bitSet’ and ‘bitNotSet’ with 0.

6. Traverse the given array and if the element belongs to the first set, take its XOR with bitSet else take its XOR with bitNotSet.

7. Traverse from 1 to n, and if the number belongs to the first set, take its XOR with bitSet else take its XOR with bitNotSet.

8. Now, we have our missing and repeating numbers stored in bitSet and bitNotSet, but we do not know which one is missing and which one 
   is repeating.

9. To find which one is repeating, we will again traverse the given array and if ‘bitSet’ is present in the array, it means ‘bitSet’ is 
   our repeating number and ‘bitNotSet’ is our missing number. We will store ‘bitSet’ in the variable ‘R’ and ‘bitNotSet’ in the 
   variable ‘M’. If ‘bitNotSet’ is present in the array, it means ‘bitNotSet’ is our repeating number and ‘bitSet’ is our missing 
   number. We will store ‘bitSet’ in the variable ‘M’ and ‘bitNotSet’ in the variable ‘R’.

10. Finally, we will return the missing number ‘M’ and the repeating number ‘R’.



For example:

If the given array is [1, 3, 5, 3, 4]

Then, findXOR = [1 ^ 2 ^ 3 ^ 4 ^ 5] ^ [ 1 ^ 3 ^ 5 ^ 3 ^ 4]  = 1

Notice that, 2 is our missing number and 3 is our repeating number in the given array and 2^3 is 1.

Now, the first bit is set in 1.

We will traverse the array and find all the elements whose this bit is set and take their XOR and store it in A. Also, we will take the XOR of all the elements in the array and from 1 to n whose this bit is not set and store it in B.

A =  [ 1 ^ 3 ^ 3 ^ 5 ] ^ [ 1 ^ 3 ^ 5] = 3

B =  [ 4 ] ^ [ 2 ^ 4] = 2

As 3 is present in the array, this cant be our missing number.

Thus, 2 is our missing number and 3 is our repeating number.

*/

pair<int, int> missingAndRepeating(vector<int> &A, int n)
{
        pair<int, int> ans;
        int a = 0, set_bit, rep = 0, miss = 0;
        for (int i : A)
                a = (a ^ i);
        for (int i = 1; i <= n; i++)
                a = (a ^ i);
        set_bit = (a & (~(a - 1)));
        for (int i : A)
        {
                if (i & set_bit)
                        rep = (rep ^ i);
                else
                        miss = (miss ^ i);
        }
        for (int i = 1; i <= n; i++)
        {
                if (i & set_bit)
                        rep = (rep ^ i);
                else
                        miss = (miss ^ i);
        }

        for (int i : A)
        {
                if (i == miss)
                {
                        swap(miss, rep);
                        break;
                }
                if (i == rep)
                        break;
        }

        ans = {miss, rep};
        return ans;
}