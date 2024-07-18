/**
 * @param {string} s
 * @param {number} k
 * @return {string}
 */
var truncateSentence = function (s, k) {
    const s1 = s.split(" ");
    let ans = "";

    for (let i = 0; i < k; i++) {
        ans = ans + s1[i];
        if (i!= k - 1) {
            ans  = ans + " ";
        }
    }

    return ans;
};