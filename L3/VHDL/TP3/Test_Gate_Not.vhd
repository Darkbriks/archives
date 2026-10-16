library IEEE;
use IEEE.STD_LOGIC_1164.ALL;

entity Test_Gate_Not is
end Test_Gate_Not;

architecture Behavioral of Test_Gate_Not is
    component Gate_Not
        Port ( e : in STD_LOGIC;
               res : out STD_LOGIC);
    end component;
    
    signal e: STD_LOGIC:='0';
    signal res: STD_LOGIC;
    
    constant period:time :=10 ns;
    
begin
    Genere: process
        begin
        e <='0';
        wait for period;
        e<='1';
        wait;
    end process;

    Map_Port : Gate_Not PORT MAP(
        e=>e,
        res=>res);
end Behavioral;
