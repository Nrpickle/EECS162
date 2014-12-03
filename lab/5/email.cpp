#include "main.hpp"

//Empty default constructor
Email::Email(){

}

Email::Email(string senderInput, string recipientInput, string titleInput, string bodyInput){
  sender = senderInput;
  recipient = recipientInput;
  title = titleInput;
  text = bodyInput;  
}

Email & Email::operator=(const Email &input){
  sender = input.sender;
  recipient = input.recipient;
  title = input.title;
  text = input.text;
}

void Email::output(){
  cout << setw(15) << left << "Title: " << title << endl;
  cout << setw(15) << left << "Sender: " << sender << endl;
  cout << setw(15) << left << "Recipient: " << recipient << endl;
  //cout << setw(15) << left << "Body: " << text << endl;
  Document::output();


}

