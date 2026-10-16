library IEEE;
use IEEE.STD_LOGIC_1164.ALL;

entity Test_Display is
end Test_Display;

architecture Behavioral of Test_Display is
    component Display
        Port ( s : in STD_LOGIC;
            a : out STD_LOGIC;
            b : out STD_LOGIC;
            c : out STD_LOGIC;
            d : out STD_LOGIC;
            e : out STD_LOGIC;
            f : out STD_LOGIC;
            g : out STD_LOGIC;
            dp : out STD_LOGIC);
    end component;
    
    signal s: STD_LOGIC:='0';
    signal a: STD_LOGIC;
    signal b: STD_LOGIC;
    signal c: STD_LOGIC;
    signal d: STD_LOGIC;
    signal e: STD_LOGIC;
    signal f: STD_LOGIC;
    signal g: STD_LOGIC;
    signal dp : STD_Logic;
    
    constant period:time :=10 ns;

begin
    Generate_In: process
        begin
        s <='0';
        wait for period;
        s <='1';
        wait;
    end process;

    Affiche : Display PORT MAP(s, a, b, c, d, e, f, g, dp);
end Behavioral;
