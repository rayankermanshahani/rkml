/* ops.h */

#pragma once

#include "../matrix/matrix.h"

class Gate {
    private:
        std::pair<Matrix*, Matrix*> parents;
    public:
        Matrix output;
        Matrix gradient;
        // getter function for parent nodes
        std::pair<Matrix*, Matrix*> getParents() const;
};

// LEAF NODE
class Leaf: public Gate {
    // constructor
    Leaf(Matrix &A); 
    // parents = null pointers
    // output = A;
    // gradient = zero matrix;
}; 

// BINARY OPS 
class AddGate: public Gate {
    // constructor
    AddGate(Gate& A, Gate& B); 
    // parents = A, B

    // forward pass
    void forward(Matrix& A, Matrix& B);
    // output = A + B;

    // backward pass
    void backward(Matrix& outputs_grad); 
    // gradient = outputs_grad * 1;

};

class MulGate: public Gate {
};

// UNARY OPS
class ReLUGate: public Gate {
};

class LSMGate: public Gate  {
};

class NLLLossGate: public Gate {
};