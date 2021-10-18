/* add your code */
namespace rosetta
  {
  namespace fourBitAdder
    {
    namespace detail
      {
 
      class Block
        {
        public:
          virtual bool TransferFunction(unsigned indexOfOutput)=0;
        };
 
      template<int NumIn, int NumOut>
      class LogicBlock
        :Block
        {
        public:
          PinIn& In(unsigned i = 0)const
            {
            if(i >= NumIn)
              throw std::out_of_range("Index of input pin is out of range!");
            return *in[i];
            }
 
          const PinOut& Out(unsigned i = 0)
          {
          if(i >= NumOut)
            throw std::out_of_range("Index of output pin is out of range!");
          return *out[i];
          }
 
        protected:
          LogicBlock()
            {
            for(int i =0; i < NumIn; i++)
              in.push_back(std::auto_ptr<PinIn>(new PinIn()));
            for(int i =0; i < NumOut; i++)
              out.push_back(std::auto_ptr<PinOut>(new PinOut(*this, i)));            
            }
 
          enum 
            {
            NumInputs = NumIn, 
            NumOutputs = NumOut
            };
        private:
          std::vector<std::auto_ptr<PinIn> > in;
          std::vector<std::auto_ptr<PinOut> > out;
        };
 
      }   //namespace detail
    }     //namespace fourBitAdder
  }       //namespace rosetta
// Note that you will need intermediate classes as well
// for the half-adder and full-adder circuits.
