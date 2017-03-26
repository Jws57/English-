/*
Author: <James Santana>
Course: {135}
Instructor: <William Sakas>
Assignment: <Programming Assignment 3>
This program inputs eng-- sentences from a file(Eng--sents.txt), translates them to eng++, creates a
new file (Eng++.txt) filled with the translates sentences
*/
#include <iostream>
#include <fstream>
#include <string>
#include <cstdlib>
#include <sstream>
#include <vector>

using namespace std;


const int VOC_sz=11;
class Corpus;
/*------------------------------------------------------------------------*/
class Vitem{
    public:
	friend Corpus;
    friend void operator >>(istream& is, Corpus &aCorpus);
    private:
    string word;/// a word (man, short, kissed,etc)
    string pos;/// the Kind of word (noun, adjective, verb, etc)
};
/*------------------------------------------------------------------------*/
class Sentence{
    public:
	friend Corpus;
    friend void operator >>(istream& is, Corpus &aCorpus) ;

    private:
    string sent; ///the entire sentence as a single
    vector<Vitem> vitems; ///the sentence as a vector of VItem objects
};
/*------------------------------------------------------------------------*/
class Corpus{
    public:
	void fill_voc();
    void translate(Corpus aCorpus);
	void write_ENGplus_file (ostream& os );
    friend void operator >>(istream& is, Corpus &aCorpus) ;
    private:
    vector<Sentence> text;//a vector of Sentence objects
};

/*------------------------------------------------------------------------*/
void operator >>(istream& is, Corpus &aCorpus);

/*------------------------------------------------------------------------*/
Vitem dictionary[VOC_sz];//vocabulary for Eng--
int main(){
    Corpus aCorpus;

    aCorpus.fill_voc();

    ifstream is;

    is.open("Eng--sents.txt");

    is>>aCorpus;

    Corpus ENGplus_Corpus;

    ENGplus_Corpus.translate(aCorpus);

    ofstream os("Eng++.txt");

    ENGplus_Corpus.write_ENGplus_file (os);
}


void operator >>(istream& is, Corpus &aCorpus){
    /*
    overload the input stream operator to populate an instance of a
    Corpus class that represents Eng­- from a file of grammatical
    Eng­sentences
    */
    if (is.fail()) {
        cerr << "Failed to open the data file." << endl;
        exit(1);
    }
    while(is.peek() != EOF) {
        Sentence s;
        Sentence dell;
        while ( getline(is,s.sent) ){
            int sz=s.sent.length();
            string w;
            Vitem temp;
            for(int i=0; i<sz; i++){
                if(s.sent[i]!=' '){
                    w=w+s.sent[i];
                }
                if(s.sent[i]==' ' or i==sz-1){
                    temp.word=w;
                    for(int c=0; c< VOC_sz; c++){
                        if(w==dictionary[c].word){
                            temp.pos=dictionary[c].pos;
                        }
                    }
                    w="";

                    s.vitems.push_back(temp);
                    temp.word="";
                    temp.pos="";
                }
            }

            aCorpus.text.push_back(s);
            s=dell;
        }
    }
}
/*------------------------------------------------------------------------*/

void Corpus:: write_ENGplus_file (ostream& os ){
    //write out a new file of the original file translated into Eng++.
    int sz=text.size();
    for(int i=0; i< sz; i++){
        int length=text[i].vitems.size();
        for(int g=0; g<length; g++){
            os << text[i].vitems[g].word<<" ";
        }
        os<<endl;
    }
}
/*------------------------------------------------------------------------*/
void Corpus::fill_voc(){
    //populates an array of VItem objects
    //that correspond to the vocabulary for Eng
    dictionary[0].word="man";
    dictionary[0].pos="noun";
    dictionary[1].word="woman";
    dictionary[1].pos="noun";
    dictionary[2].word="fish";
    dictionary[2].pos="noun";
    dictionary[3].word="is";
    dictionary[3].pos="verb";
    dictionary[4].word="kissed";
    dictionary[4].pos="verb";
    dictionary[5].word="caught";
    dictionary[5].pos="verb";
    dictionary[6].word="red";
    dictionary[6].pos="adjective";
    dictionary[7].word="strong";
    dictionary[7].pos="adjective";
    dictionary[8].word="short";
    dictionary[8].pos="adjective";
    dictionary[9].word="a";
    dictionary[9].pos="articles";
    dictionary[10].word="the";
    dictionary[10].pos="articles";
}
/*------------------------------------------------------------------------*/
void Corpus:: translate(Corpus aCorpus){
    /*
    takes all of the sentences a Eng-- Corpus object and
    creates a new new Corpus object filled with all the
    Eng-- sentences translated into Eng++
    */
    Corpus new_Corpus=aCorpus;
    int sz=new_Corpus.text.size();
    for(int i=0; i< sz; i++){
        int length=new_Corpus.text[i].vitems.size();
        bool is_fisr_noun=true;
        for(int g=0; g<length; g++ ){

            if (new_Corpus.text[i].vitems[0].word=="is"){
            new_Corpus.text[i].vitems[0].word=new_Corpus.text[i].vitems[0].word +"-ka" ;}
            if (new_Corpus.text[i].vitems[g].pos=="verb"){
                new_Corpus.text[i].vitems.push_back(new_Corpus.text[i].vitems[g]);
                new_Corpus.text[i].vitems.erase (new_Corpus.text[i].vitems.begin()+g);
            }

            if (new_Corpus.text[i].vitems[g].pos=="articles"){
                new_Corpus.text[i].vitems.erase (new_Corpus.text[i].vitems.begin()+g);
            }

            if (new_Corpus.text[i].vitems[g].pos=="noun"and is_fisr_noun==true){
                new_Corpus.text[i].vitems[g].word=new_Corpus.text[i].vitems[g].word +"-ga" ;
            is_fisr_noun=false;}
            else if(new_Corpus.text[i].vitems[g].pos=="noun"and is_fisr_noun==false){
                new_Corpus.text[i].vitems[g].word=new_Corpus.text[i].vitems[g].word +"-o" ;
            }
        }
    }

    text=new_Corpus.text;

}
