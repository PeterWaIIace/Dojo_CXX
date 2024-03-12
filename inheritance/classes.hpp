enum classType {
    BASE,
    DAUGHTER,
    PROTECTED_DAUGHTER
};

class Base{
    public:
    int type;
    int my_val;
    
    Base(){
        this->type = BASE;
        this->my_val = 1;
    }

    virtual int getType(){
        return type;
    }


    protected:

    int retIncremented(){
        return this->my_val + 1;
    }

    private:

    int retDecremented(){
        return this->my_val - 1;
    }

};

class Daughter : public Base{
    public:
    int type = DAUGHTER;
    
    int getType(){
        return this->type;
    }
};


class Protected_Daughter : protected Base{
    public:
    int type = PROTECTED_DAUGHTER;

    int getProtectedType(){
        return this->getType();
    }

    private:

    int getType(){
        return this->type;
    }
};