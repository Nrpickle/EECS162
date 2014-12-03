class Document {
  public:
    Document();
    Document(string inputText);
    void output();
    Document & operator=(const Document &input);
  private:

  protected:
    string text;

};
