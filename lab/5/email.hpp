class Email : public Document {
  public:
    Email();
    Email(string sender, string recipient, string title, string body);
    void output();
    Email & operator=(const Email &input);
  private:

  protected:
    string sender, recipient, title;
};
