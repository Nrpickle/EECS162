#ifndef DICE_HPP
#define DICE_HPP

class Dice 
{
  public:
    Dice();
    Dice(int numSides);
    virtual int roll() const;
  protected:
    int numSides;
};


class loadedDice1 : public Dice {
  public:
    loadedDice1();
    loadedDice1(int numSides);
    int roll() const;
};


class loadedDice2 : public Dice {
  public:
    loadedDice2();
    loadedDice2(int numSides);
    int roll() const;
};


#endif
