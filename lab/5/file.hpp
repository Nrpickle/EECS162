class File : public Document {
  public:
    File();
    File(string pathname, string text);
    void output();
    File & operator=(const File &input);
  private:

  protected:
    string pathname;
};
