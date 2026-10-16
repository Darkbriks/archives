library IEEE;
use IEEE.STD_LOGIC_1164.ALL;

entity Test_Id_Blake_1 is
end Test_Id_Blake_1;

architecture Behavioral of Test_Id_Blake_1 is
    component Id_Blake_1
        Port ( a : in STD_LOGIC;
               b : in STD_LOGIC;
               c : in STD_LOGIC;
               res : out STD_LOGIC);
    end component;
    
    signal a: STD_LOGIC:='0';
    signal b: STD_LOGIC:='0';
    signal c: STD_LOGIC:='0';
    signal res: STD_LOGIC:='0';
    
    constant period:time :=10 ns;

begin
    Generate_In: process
    begin
        a <= '0'; b <= '0'; c <= '0';
        wait for period;
        a <= '1'; b <= '0'; c <= '0';
        wait for period;
        a <= '0'; b <= '1'; c <= '0';
        wait for period;
        a <= '1'; b <= '1'; c <= '0';
        wait for period;
        a <= '0'; b <= '0'; c <= '1';
        wait for period;
        a <= '1'; b <= '0'; c <= '1';
        wait for period;
        a <= '0'; b <= '1'; c <= '1';
        wait for period;
        a <= '1'; b <= '1'; c <= '1';
        wait for period;
        a <= '0'; b <= '0'; c <= '0';
        wait;
    end process;

    Test : Id_Blake_1 PORT MAP(a, b, c, res);
end Behavioral;
