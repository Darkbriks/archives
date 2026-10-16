library IEEE;
use IEEE.STD_LOGIC_1164.ALL;

entity Test_Gate_Nor is
end Test_Gate_Nor;

architecture Behavioral of Test_Gate_Nor is
    component Gate_Nor
        Port ( e1 : in STD_LOGIC;
            e2 : in STD_LOGIC;
            res : out STD_LOGIC);
    end component;
    
    signal e1: STD_LOGIC:='0';
    signal e2: STD_LOGIC:='0';
    signal res: STD_LOGIC;
    
    constant period:time :=10 ns;
    
begin
    Genere: process
        begin
        e1 <='0';
        e2<='0';
        wait for period;
        e1<='1';
        e2<='1';
        wait for period;
        e1 <='1';
        e2<='0';
        wait for period;
        e1 <='0';
        e2<='1';
        wait;
    end process;

    Map_Port : Gate_Nor PORT MAP(
        e1=>e1,
        e2=>e2,
        res=>res);
end Behavioral;
