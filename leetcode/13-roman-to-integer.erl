-spec roman_to_int(S :: unicode:unicode_binary()) -> integer().

f(List) -> 
  case List of
    [$I,$V |Xs] -> 4 + f(Xs);
    [$I,$X |Xs] -> 9 + f(Xs);
    [$X,$L |Xs] -> 40 + f(Xs);
    [$X,$C |Xs] -> 90 + f(Xs);    
    [$C,$D |Xs] -> 400 + f(Xs);      
    [$C,$M |Xs] -> 900 + f(Xs);
    [$I    |Xs] -> 1 + f(Xs);
    [$V    |Xs] -> 5 + f(Xs);
    [$X    |Xs] -> 10 + f(Xs);      
    [$L    |Xs] -> 50 + f(Xs);    
    [$C    |Xs] -> 100 + f(Xs);
    [$D    |Xs] -> 500 + f(Xs);
    [$M    |Xs] -> 1000 + f(Xs);                  
    [ ] -> 0
   end.

roman_to_int(S) -> 
  case unicode:characters_to_list(S,unicode) of 
      List ->  f(List);
      _ -> cannotRead.
  end.
