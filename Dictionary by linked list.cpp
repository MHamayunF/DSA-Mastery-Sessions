#include <iostream>
#include <string>
#include<algorithm>
using namespace std;

// Define the structure for a meaning of a word
struct Meaning {
    string meaning;
    Meaning* next;

    Meaning(const string& m) : meaning(m), next(NULL) {}
};

// Define the structure for a word node
struct WordNode {
    string word;
    Meaning* meanings;
    WordNode* next;

    WordNode(const string& w) : word(w), meanings(NULL), next(NULL) {}
};

// Define the structure for an alphabet node
struct AlphabetNode {
    char alphabet;
    WordNode* words;
    AlphabetNode* next;

    AlphabetNode(char a) : alphabet(a), words(NULL), next(NULL) {}
};

class Dictionary {
private:
    AlphabetNode* head;

public:
    Dictionary() {
        head = NULL;
    }

    // Function to insert a new word
    void insertWord(const string& word, const string& meaning) {
        // Convert the word to lowercase for case-insensitive comparison
        string lowercaseWord = word;
        transform(lowercaseWord.begin(), lowercaseWord.end(), lowercaseWord.begin(), ::tolower);

        AlphabetNode* alphabetNode = findAlphabetNode(lowercaseWord[0]);

        // If the alphabet node doesn't exist, create it
        if (!alphabetNode) {
            alphabetNode = new AlphabetNode(lowercaseWord[0]);
            alphabetNode->next = head;
            head = alphabetNode;
        }

        WordNode* wordNode = alphabetNode->words;
        WordNode* prevWordNode = NULL;

        // Search for the word in the alphabet's word list
        while (wordNode && wordNode->word != lowercaseWord) {
            prevWordNode = wordNode;
            wordNode = wordNode->next;
        }

        // If the word is found, display meanings and ask for an update
        if (wordNode) {
            cout << "Word '" << word << "' already exists with the following meanings:" << endl;
            displayMeanings(wordNode);
            cout << "Do you want to add a new meaning? (y/n): ";
            char choice;
            cin >> choice;
            if (choice == 'y') {
                addMeaning(wordNode, meaning);
                cout << "Meaning added successfully." << endl;
            } else {
                cout << "No update performed." << endl;
            }
        } else {
            // If the word is not found, create a new word node and meaning
            WordNode* newWordNode = new WordNode(lowercaseWord);
            newWordNode->next = alphabetNode->words;
            alphabetNode->words = newWordNode;
            addMeaning(newWordNode, meaning);
            cout << "Word '" << word << "' added successfully." << endl;
        }
    }

    // Function to search for a word
    void searchWord(const string& word) {
        string lowercaseWord = word;
        transform(lowercaseWord.begin(), lowercaseWord.end(), lowercaseWord.begin(), ::tolower);

        AlphabetNode* alphabetNode = findAlphabetNode(lowercaseWord[0]);

        if (alphabetNode) {
            WordNode* wordNode = alphabetNode->words;
            while (wordNode && wordNode->word != lowercaseWord) {
                wordNode = wordNode->next;
            }

            if (wordNode) {
                cout << "Word: " << wordNode->word << endl;
                cout << "Meanings:" << endl;
                displayMeanings(wordNode);
            } else {
                cout << "Word not found in the dictionary." << endl;
            }
        } else {
            cout << "Word not found in the dictionary." << endl;
        }
    }

    // Function to delete a word
    void deleteWord(const string& word) {
        string lowercaseWord = word;
        transform(lowercaseWord.begin(), lowercaseWord.end(), lowercaseWord.begin(), ::tolower);

        AlphabetNode* alphabetNode = findAlphabetNode(lowercaseWord[0]);

        if (alphabetNode) {
            WordNode* wordNode = alphabetNode->words;
            WordNode* prevWordNode = NULL;

            while (wordNode && wordNode->word != lowercaseWord) {
                prevWordNode = wordNode;
                wordNode = wordNode->next;
            }

            if (wordNode) {
                cout << "Word: " << wordNode->word << endl;
                cout << "Meanings:" << endl;
                displayMeanings(wordNode);

                if (wordNode->meanings->next) {
                    int meaningChoice;
                    cout << "Select a meaning to delete (1, 2, ...): ";
                    cin >> meaningChoice;
                    if (meaningChoice == 1) {
                        // Delete the first meaning
                        Meaning* temp = wordNode->meanings;
                        wordNode->meanings = wordNode->meanings->next;
                        delete temp;
                    } else {
                        // Find and delete the selected meaning
                        int currentMeaning = 1;
                        Meaning* meaning = wordNode->meanings;
                        Meaning* prevMeaning = NULL;

                        while (currentMeaning < meaningChoice) {
                            prevMeaning = meaning;
                            meaning = meaning->next;
                            currentMeaning++;
                        }

                        prevMeaning->next = meaning->next;
                        delete meaning;
                    }

                    cout << "Meaning deleted successfully." << endl;
                } else {
                    // Delete the entire word
                    if (prevWordNode) {
                        prevWordNode->next = wordNode->next;
                    } else {
                        alphabetNode->words = wordNode->next;
                    }

                    deleteMeanings(wordNode->meanings);
                    delete wordNode;
                    cout << "Word deleted successfully." << endl;
                }
            } else {
                cout << "Word not found in the dictionary." << endl;
            }
        } else {
            cout << "Word not found in the dictionary." << endl;
        }
    }

    // Function to print the dictionary words alphabetically
    void printDictionaryAlphabetically() {
        AlphabetNode* currentAlphabet = head;

        while (currentAlphabet) {
            cout << "Alphabet: " << currentAlphabet->alphabet << endl;
            WordNode* currentWord = currentAlphabet->words;

            while (currentWord) {
                cout << "Word: " << currentWord->word << endl;
                cout << "Meanings:" << endl;
                displayMeanings(currentWord);
                currentWord = currentWord->next;
            }

            currentAlphabet = currentAlphabet->next;
        }
    }

    // Function to print the dictionary in reverse order using recursion
    void printDictionaryInReverseRecursive() {
        cout << "Dictionary in reverse order (using recursion):" << endl;
        printReverseRecursive(head);
    }

    // Function to print the dictionary in reverse order using a stack
    void printDictionaryInReverseStack() {
        cout << "Dictionary in reverse order (using a stack):" << endl;
        stack<string> reverseStack;
        AlphabetNode* currentAlphabet = head;

        while (currentAlphabet) {
            WordNode* currentWord = currentAlphabet->words;

            while (currentWord) {
                reverseStack.push(currentWord->word);
                currentWord = currentWord->next;
            }

            currentAlphabet = currentAlphabet->next;
        }

        while (!reverseStack.empty()) {
            cout << "Word: " << reverseStack.top() << endl;
            reverseStack.pop();
        }
    }

    // Function to calculate the average search time
    double calculateAverageSearchTime() {
        int totalJumps = 0;
        int wordCount = 0;

        AlphabetNode* currentAlphabet = head;

        while (currentAlphabet) {
            WordNode* currentWord = currentAlphabet->words;

            while (currentWord) {
                totalJumps += countJumps(currentAlphabet, currentWord->word);
                wordCount++;
                currentWord = currentWord->next;
            }

            currentAlphabet = currentAlphabet->next;
        }

        return static_cast<double>(totalJumps) / wordCount;
    }

private:
    // Helper function to find an alphabet node
    AlphabetNode* findAlphabetNode(char c) {
        AlphabetNode* current = head;

        while (current && current->alphabet != c) {
            current = current->next;
        }

        return current;
    }

    // Helper function to display meanings
    void displayMeanings(WordNode* wordNode) {
        Meaning* currentMeaning = wordNode->meanings;
        int meaningIndex = 1;

        while (currentMeaning) {
            cout << meaningIndex << ". " << currentMeaning->meaning << endl;
            currentMeaning = currentMeaning->next;
            meaningIndex++;
        }
    }

    // Helper function to add a meaning to a word
    void addMeaning(WordNode* wordNode, const string& meaning) {
        Meaning* newMeaning = new Meaning(meaning);
        newMeaning->next = wordNode->meanings;
        wordNode->meanings = newMeaning;
    }

    // Helper function to delete meanings
    void deleteMeanings(Meaning* meanings) {
        while (meanings) {
            Meaning* temp = meanings;
            meanings = meanings->next;
            delete temp;
        }
    }

    // Helper function to print the dictionary in reverse order using recursion
    void printReverseRecursive(AlphabetNode* current) {
        if (current) {
            printReverseRecursive(current->next);
            WordNode* currentWord = current->words;

            while (currentWord) {
                cout << "Word: " << currentWord->word << endl;
                cout << "Meanings:" << endl;
                displayMeanings(currentWord);
                currentWord = currentWord->next;
            }
        }
    }

    // Helper function to count jumps from head to a word
    int countJumps(AlphabetNode* alphabet, const string& word) {
        int jumps = 0;

        AlphabetNode* currentAlphabet = head;
        while (currentAlphabet && currentAlphabet != alphabet) {
            jumps++;
            currentAlphabet = currentAlphabet->next;
        }

        if (currentAlphabet) {
            WordNode* currentWord = currentAlphabet->words;
            while (currentWord && currentWord->word != word) {
                jumps++;
                currentWord = currentWord->next;
            }
        }

        return jumps;
    }
};

int main() {
    Dictionary dictionary;
    char choice;

    do {
        cout << "Dictionary Options:" << endl;
        cout << "1. Insert a new word" << endl;
        cout << "2. Search for a word" << endl;
        cout << "3. Delete a word" << endl;
        cout << "4. Print the dictionary words alphabetically" << endl;
        cout << "5. Print the dictionary in reverse order (using recursion)" << endl;
        cout << "6. Print the dictionary in reverse order (using a stack)" << endl;
        cout << "7. Calculate average search time" << endl;
        cout << "8. Exit" << endl;
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
            case '1':
                {
                    string word, meaning;
                    cout << "Enter the word: ";
                    cin >> word;
                    cout << "Enter the meaning: ";
                    cin.ignore();
                    getline(cin, meaning);
                    dictionary.insertWord(word, meaning);
                }
                break;
            case '2':
                {
                    string word;
                    cout << "Enter the word to search: ";
                    cin >> word;
                    dictionary.searchWord(word);
                }
                break;
            case '3':
                {
                    string word;
                    cout << "Enter the word to delete: ";
                    cin >> word;
                    dictionary.deleteWord(word);
                }
                break;
            case '4':
                dictionary.printDictionaryAlphabetically();
                break;
            case '5':
                dictionary.printDictionaryInReverseRecursive();
                break;
            case '6':
                dictionary.printDictionaryInReverseStack();
                break;
            case '7':
                {
                    double averageSearchTime = dictionary.calculateAverageSearchTime();
                    cout << "Average search time: " << averageSearchTime << " jumps per word." << endl;
                }
                break;
            case '8':
                cout << "Goodbye!" << endl;
                break;
            default:
                cout << "Invalid choice. Please try again." << endl;
        }
    } while (choice != '8');

    return 0;
}
