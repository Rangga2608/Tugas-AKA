#include <iostream>
#include <vector>
#include <string>

using namespace std;


struct Thread {
    string title;
    int interactions;
};


void printThreads(const vector<Thread>& threads) {
    for (const auto& thread : threads) {
        cout << "Title: " << thread.title
             << ", Interactions: " << thread.interactions << endl;
    }
}


void merge(vector<Thread>& threads, int left, int mid, int right) {
    int n1 = mid - left + 1;
    int n2 = right - mid;

    vector<Thread> leftArray(n1), rightArray(n2);

    for (int i = 0; i < n1; ++i)
        leftArray[i] = threads[left + i];
    for (int i = 0; i < n2; ++i)
        rightArray[i] = threads[mid + 1 + i];

    int i = 0, j = 0, k = left;
    while (i < n1 && j < n2) {
        if (leftArray[i].interactions >= rightArray[j].interactions) {
            threads[k] = leftArray[i];
            ++i;
        } else {
            threads[k] = rightArray[j];
            ++j;
        }
        ++k;
    }

    while (i < n1) {
        threads[k] = leftArray[i];
        ++i;
        ++k;
    }

    while (j < n2) {
        threads[k] = rightArray[j];
        ++j;
        ++k;
    }
}


void mergeSortRecursive(vector<Thread>& threads, int left, int right) {
    if (left < right) {
        int mid = left + (right - left) / 2;
        mergeSortRecursive(threads, left, mid);
        mergeSortRecursive(threads, mid + 1, right);
        merge(threads, left, mid, right);
    }
}

int main() {
    vector<Thread> threads = {
        {"C++ Tips and Tricks", 150},
        {"Breaking News", 1200},
        {"Top 10 Programming Languages", 800},
        {"Meta's New Feature", 450},
        {"AI and the Future", 900}
    };

    cout << "Threads sebelum sorting:\n";
    printThreads(threads);

    mergeSortRecursive(threads, 0, threads.size() - 1);

    cout << "\nThreads setelah sorting (Trending):\n";
    printThreads(threads);

    return 0;
}
