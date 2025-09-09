auto count = [&](vector<int>& a, vector<int>& b) {
    long long ans = 0;
    for (int i = 0; i < a.size(); i++) {
        if (a[i] > b[i])
            ans += (a[i] - b[i]) / 2;
    }
    return ans;
};

// General Syntax

[capture_list](parameters) -> return_type {
    // function body
}

// capture_list – tells which outside variables the lambda can use (like closure in other languages).
// parameters – like normal function parameters.
// return_type – optional (compiler usually deduces automatically).
// function body – what it does.

// Capture Modes
// [] → capture nothing.
// [=] → capture all local variables by value.
// [&] → capture all local variables by reference.
// [=, &x] → capture everything by value but x by reference.
// [&, x] → capture everything by reference but x by value.



