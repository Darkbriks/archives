library IEEE;
use IEEE.STD_LOGIC_1164.ALL;

entity Test_Check is
end Test_Check;

architecture Behavioral of Test_Check is
    component Check_Err
        Port (e11 : in STD_LOGIC; -- And
              e12 : in STD_LOGIC; -- Or
              e13 : in STD_LOGIC; -- Not
              e14 : in STD_LOGIC; -- Xor
              e15 : in STD_LOGIC; -- Nand
              e16 : in STD_LOGIC; -- Nor
              err : out STD_LOGIC); -- 1 if more than one switch is up, else 0
    end component;
    
    signal e11: STD_LOGIC:='0';
    signal e12: STD_LOGIC:='0';
    signal e13: STD_LOGIC:='0';
    signal e14: STD_LOGIC:='0';
    signal e15: STD_LOGIC:='0';
    signal e16: STD_LOGIC:='0';
    signal err: STD_LOGIC:='0';
    
    constant period:time:=10 ns;

begin
    Generate_In: process
            begin
            e11 <='0'; e12 <='0'; e13 <='0'; e14 <='0'; e15 <='0'; e16 <='0'; wait for period;
            e11 <='1'; e12 <='0'; e13 <='0'; e14 <='0'; e15 <='0'; e16 <='0'; wait for period;
            e11 <='0'; e12 <='1'; e13 <='0'; e14 <='0'; e15 <='0'; e16 <='0'; wait for period;
            e11 <='1'; e12 <='1'; e13 <='0'; e14 <='0'; e15 <='0'; e16 <='0'; wait for period;
            e11 <='0'; e12 <='0'; e13 <='1'; e14 <='0'; e15 <='0'; e16 <='0'; wait for period;
            e11 <='1'; e12 <='0'; e13 <='1'; e14 <='0'; e15 <='0'; e16 <='0'; wait for period;
            e11 <='0'; e12 <='1'; e13 <='1'; e14 <='0'; e15 <='0'; e16 <='0'; wait for period;
            e11 <='1'; e12 <='1'; e13 <='1'; e14 <='0'; e15 <='0'; e16 <='0'; wait for period;
            e11 <='0'; e12 <='0'; e13 <='0'; e14 <='1'; e15 <='0'; e16 <='0'; wait for period;
            e11 <='1'; e12 <='0'; e13 <='0'; e14 <='1'; e15 <='0'; e16 <='0'; wait for period;
            e11 <='0'; e12 <='1'; e13 <='0'; e14 <='1'; e15 <='0'; e16 <='0'; wait for period;
            e11 <='1'; e12 <='1'; e13 <='0'; e14 <='1'; e15 <='0'; e16 <='0'; wait for period;
            e11 <='0'; e12 <='0'; e13 <='1'; e14 <='1'; e15 <='0'; e16 <='0'; wait for period;
            e11 <='1'; e12 <='0'; e13 <='1'; e14 <='1'; e15 <='0'; e16 <='0'; wait for period;
            e11 <='0'; e12 <='1'; e13 <='1'; e14 <='1'; e15 <='0'; e16 <='0'; wait for period;
            e11 <='1'; e12 <='1'; e13 <='1'; e14 <='1'; e15 <='0'; e16 <='0'; wait for period;
            e11 <='0'; e12 <='0'; e13 <='0'; e14 <='0'; e15 <='1'; e16 <='0'; wait for period;
            e11 <='1'; e12 <='0'; e13 <='0'; e14 <='0'; e15 <='1'; e16 <='0'; wait for period;
            e11 <='0'; e12 <='1'; e13 <='0'; e14 <='0'; e15 <='1'; e16 <='0'; wait for period;
            e11 <='1'; e12 <='1'; e13 <='0'; e14 <='0'; e15 <='1'; e16 <='0'; wait for period;
            e11 <='0'; e12 <='0'; e13 <='1'; e14 <='0'; e15 <='1'; e16 <='0'; wait for period;
            e11 <='1'; e12 <='0'; e13 <='1'; e14 <='0'; e15 <='1'; e16 <='0'; wait for period;
            e11 <='0'; e12 <='1'; e13 <='1'; e14 <='0'; e15 <='1'; e16 <='0'; wait for period;
            e11 <='1'; e12 <='1'; e13 <='1'; e14 <='0'; e15 <='1'; e16 <='0'; wait for period;
            e11 <='0'; e12 <='0'; e13 <='0'; e14 <='1'; e15 <='1'; e16 <='0'; wait for period;
            e11 <='1'; e12 <='0'; e13 <='0'; e14 <='1'; e15 <='1'; e16 <='0'; wait for period;
            e11 <='0'; e12 <='1'; e13 <='0'; e14 <='1'; e15 <='1'; e16 <='0'; wait for period;
            e11 <='1'; e12 <='1'; e13 <='0'; e14 <='1'; e15 <='1'; e16 <='0'; wait for period;
            e11 <='0'; e12 <='0'; e13 <='1'; e14 <='1'; e15 <='1'; e16 <='0'; wait for period;
            e11 <='1'; e12 <='0'; e13 <='1'; e14 <='1'; e15 <='1'; e16 <='0'; wait for period;
            e11 <='0'; e12 <='1'; e13 <='1'; e14 <='1'; e15 <='1'; e16 <='0'; wait for period;
            e11 <='1'; e12 <='1'; e13 <='1'; e14 <='1'; e15 <='1'; e16 <='0'; wait for period;
            e11 <='0'; e12 <='0'; e13 <='0'; e14 <='0'; e15 <='0'; e16 <='1'; wait for period;
            e11 <='1'; e12 <='0'; e13 <='0'; e14 <='0'; e15 <='0'; e16 <='1'; wait for period;
            e11 <='0'; e12 <='1'; e13 <='0'; e14 <='0'; e15 <='0'; e16 <='1'; wait for period;
            e11 <='1'; e12 <='1'; e13 <='0'; e14 <='0'; e15 <='0'; e16 <='1'; wait for period;
            e11 <='0'; e12 <='0'; e13 <='1'; e14 <='0'; e15 <='0'; e16 <='1'; wait for period;
            e11 <='1'; e12 <='0'; e13 <='1'; e14 <='0'; e15 <='0'; e16 <='1'; wait for period;
            e11 <='0'; e12 <='1'; e13 <='1'; e14 <='0'; e15 <='0'; e16 <='1'; wait for period;
            e11 <='1'; e12 <='1'; e13 <='1'; e14 <='0'; e15 <='0'; e16 <='1'; wait for period;
            e11 <='0'; e12 <='0'; e13 <='0'; e14 <='1'; e15 <='0'; e16 <='1'; wait for period;
            e11 <='1'; e12 <='0'; e13 <='0'; e14 <='1'; e15 <='0'; e16 <='1'; wait for period;
            e11 <='0'; e12 <='1'; e13 <='0'; e14 <='1'; e15 <='0'; e16 <='1'; wait for period;
            e11 <='1'; e12 <='1'; e13 <='0'; e14 <='1'; e15 <='0'; e16 <='1'; wait for period;
            e11 <='0'; e12 <='0'; e13 <='1'; e14 <='1'; e15 <='0'; e16 <='1'; wait for period;
            e11 <='1'; e12 <='0'; e13 <='1'; e14 <='1'; e15 <='0'; e16 <='1'; wait for period;
            e11 <='0'; e12 <='1'; e13 <='1'; e14 <='1'; e15 <='0'; e16 <='1'; wait for period;
            e11 <='1'; e12 <='1'; e13 <='1'; e14 <='1'; e15 <='0'; e16 <='1'; wait for period;
            e11 <='0'; e12 <='0'; e13 <='0'; e14 <='0'; e15 <='1'; e16 <='1'; wait for period;
            e11 <='1'; e12 <='0'; e13 <='0'; e14 <='0'; e15 <='1'; e16 <='1'; wait for period;
            e11 <='0'; e12 <='1'; e13 <='0'; e14 <='0'; e15 <='1'; e16 <='1'; wait for period;
            e11 <='1'; e12 <='1'; e13 <='0'; e14 <='0'; e15 <='1'; e16 <='1'; wait for period;
            e11 <='0'; e12 <='0'; e13 <='1'; e14 <='0'; e15 <='1'; e16 <='1'; wait for period;
            e11 <='1'; e12 <='0'; e13 <='1'; e14 <='0'; e15 <='1'; e16 <='1'; wait for period;
            e11 <='0'; e12 <='1'; e13 <='1'; e14 <='0'; e15 <='1'; e16 <='1'; wait for period;
            e11 <='1'; e12 <='1'; e13 <='1'; e14 <='0'; e15 <='1'; e16 <='1'; wait for period;
            e11 <='0'; e12 <='0'; e13 <='0'; e14 <='1'; e15 <='1'; e16 <='1'; wait for period;
            e11 <='1'; e12 <='0'; e13 <='0'; e14 <='1'; e15 <='1'; e16 <='1'; wait for period;
            e11 <='0'; e12 <='1'; e13 <='0'; e14 <='1'; e15 <='1'; e16 <='1'; wait for period;
            e11 <='1'; e12 <='1'; e13 <='0'; e14 <='1'; e15 <='1'; e16 <='1'; wait for period;
            e11 <='0'; e12 <='0'; e13 <='1'; e14 <='1'; e15 <='1'; e16 <='1'; wait for period;
            e11 <='1'; e12 <='0'; e13 <='1'; e14 <='1'; e15 <='1'; e16 <='1'; wait for period;
            e11 <='0'; e12 <='1'; e13 <='1'; e14 <='1'; e15 <='1'; e16 <='1'; wait for period;
            e11 <='1'; e12 <='1'; e13 <='1'; e14 <='1'; e15 <='1'; e16 <='1'; wait for period;
            e11 <='0'; e12 <='0'; e13 <='0'; e14 <='0'; e15 <='0'; e16 <='0'; wait;
        end process;
        
        Map_Port : Check_Err PORT MAP(e11, e12, e13, e14, e15, e16, err);

end Behavioral;
