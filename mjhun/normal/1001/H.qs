namespace Solution {
    open Microsoft.Quantum.Primitive;
    open Microsoft.Quantum.Canon;

    operation Set(desired: Result, q1: Qubit) : ()
    {
        body
        {
            let current = M(q1);
            if(desired != current){
                X(q1);
            }
        }
    }

    operation Solve (x : Qubit[], y : Qubit) : ()
    {
        body
        {
            let n = Length(x);
            for(k in 0..n-1){
                CNOT(x[k],y);
            }
        }
    }
}