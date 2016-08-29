class Button {
  public:
    Button(int p, char n);
    void read();
    void setValue(int v);
    int getValue();
    int getPin();
    bool isPressed();
    bool isChanged();
  private:
    bool isChange = 0;
    int pin;
    int value;
    char name;
};
