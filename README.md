# English-

This was a class assignment with the following instruction

Translate sentences from One functional language to another (ENG++, ENG--)

For this project, consider a fake language called Eng++. Eng++ is made up of English words with three differences borrowed from Japanese:

1.	In Japanese verbs (almost always) come at the end of a sentence.
2.	Japanese adds certain suffixes on words and sentences that indicate grammatical context.
3.	Japanese doesn’t make use of articles such as “the” or “a” .

The English sentence The man caught the fish would be translated into Eng++ as:

man-­‐ga fish-­‐o caught

Where “-­‐ga” marks the subject and “-­‐o” marks the object.

The English sentence Is the woman strong? would be translated into Eng++ as:

Woman-­‐ga strong is-­‐ka

Where “-­‐ga” marks the subject like above and “-­‐ka” marks the sentence as a question, sort of like a spoken question mark.

For this assignment two languages will be defined: Eng-­‐-­‐ which somewhat follows standard English grammar but is limited in the number of words in a sentence, and in the vocabulary, and, Eng++ as described above which is also limited in number of words.

Notes:
1)	For sentences that have the verb “is” only one adjective may appear after the subject or verb, although multiple adjectives can appear before the subject .

2)	Articles in Eng-­‐-­‐ are not repeated, and must come before all adjectives if the adjectives exist.

For example in Eng-­‐-­‐ this is a grammatical sentence: The short strong strong strong red man caught the short fish. Thus sentences can now have any number of words.

Definition of Eng-­‐-­‐:

•	three nouns: man, woman, fish
•	three adjectives: strong, short, red
•	three verbs: caught, kissed, is
•	two articles: a, the
o	The articles can only come before a noun or an adjective, and are optional. So The strong red man caught fish, and, Strong red man caught fish, and, The man caught the fish and Man caught the fish are all grammatical in Eng-­‐-­‐.
•	Sentences can be of any length.
•	Sentences may not begin with a space, and words are separated by one or more spaces.
•	Word order:
o	For declarative sentences: The subject (a noun) always begins a sentence (with or without any preceding adjectives and/or articles), the verb follows the subject. If the verb is either “caught” or “kissed”, then the direct object (a noun) follows the verb (with or without any preceding adjectives and/or articles), otherwise an adjective follows the verb.
o	For questions: Questions in Eng-­‐-­‐ can only use the verb “is”.  The verb (“is”) always begins a question, the subject (a noun) is the middle word optionally preceded by an article. An adjective is always the last word in a question.
 
o	Declarative sentences do not end with a period in Eng-­‐-­‐ and questions do not end with a question mark.


Definition of Eng++:

•	three suffixes:
o	-­‐ga (marks a noun as the subject of a sentence)
o	-­‐o   (marks a noun as the direct object of the verb)
o	-­‐ka (marks the verb in a sentence only if the sentence is a question)
o	Note that adjectives are not marked.
•	three verbs: caught, kissed, is
•	three nouns: man, woman, fish
•	three adjectives: strong, short, red
•	Like Eng-­‐-­‐ sentences can be of any length.
•	Like Eng-­‐-­‐ sentences may not begin with a space, but words are separated by
exactly one space.
•	Word order:
o	Both declarative sentences and questions have exactly the same word order. The subject is the first word in the sentence (with or without any preceding adjectives), the verb is the last. If the verb is either “caught” or “kissed”, then the direct object (a noun) is in the middle (with or without any preceding adjectives), otherwise an adjective is in the middle.
o	Declarative sentences do not end with a period in Eng++, but questions do end with the marker –ka on the last word of the question which is a verb.

Some example Eng-­‐-­‐  sentences in the first column, and their Eng++ translations in the second column:

Eng -­‐-­‐	Eng++
the strong woman kissed the man	strong woman-­‐ga man-­‐o kissed
the fish is strong	fish-­‐ga strong is
red red man caught strong fish	red red man-­‐ga strong fish-­‐o caught
is the red man red	red man-­‐ga red is-­‐ka
red strong fish is short	red strong fish-­‐ga short is
 

Your programs should have the following three classes:

All data members must be in the private section of a class.

1)	A class (VItem) for a vocabulary item which should have two string data members:

•	word:	a word (man, short, kissed, etc.)
•	pos:	a part of speech (noun, adjective, verb, etc.)

2)	A class (Sentence) for a sentence which should have a string data member, and a vector data member:

•	sent:	the entire sentence as a single string
•	vItems:	the sentence as a vector of VItem objects

3)	A class (Corpus) which is a simple “container” class for sentences. It should have only one data member:

•	text:	a vector of Sentence objects Your program should:
0)	have a non-­‐member function that manually populates an array (not a vector) of
VItem objects that correspond to the vocabulary for Eng-­‐-­‐ as outlined above.

1)	overload the input stream operator to populate an instance of a Corpus class that represents Eng-­‐-­‐ from a file of grammatical Eng-­‐-­‐ sentences (Eng-­‐-­‐sents.txt) – you may assume that all sentences in the file are grammatical Eng-­‐-­‐ sentences.

2)	have a non-­‐member function that takes all of the sentences a Eng-­‐-­‐ Corpus object and creates a new new Corpus object filled with all the Eng-­‐-­‐ sentences translated into Eng++. You should pass in both a Corpus object and the array of VItems.

IMPORTANT: In your first assignment you were allowed to use multiple “if” statements to identify part of speech. In this assignment you should search through the array of VItem objects to find the part of speech.
Basically (short of changing a const) your code should be able to work for a realistic sized vocabulary of 10’s of thousands of words.

3)	write out a new file of the original file translated into Eng++.


