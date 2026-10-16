library IEEE;
use IEEE.STD_LOGIC_1164.ALL;

entity Test_Afficheur_Binaire is
end Test_Afficheur_Binaire;

architecture Behavioral of Test_Afficheur_Binaire is
    component Afficheur_Binaire
        Port ( sel : in STD_LOGIC;
            a : out STD_LOGIC;
            b : out STD_LOGIC;
            c : out STD_LOGIC;
            d : out STD_LOGIC;
            e : out STD_LOGIC;
            f : out STD_LOGIC;
            g : out STD_LOGIC;
            dp : out STD_LOGIC);
    end component;
    
    signal sel: STD_LOGIC:='0';
    signal A: STD_LOGIC;
    signal B: STD_LOGIC;
    signal C: STD_LOGIC;
    signal D: STD_LOGIC;
    signal E: STD_LOGIC;
    signal F: STD_LOGIC;
    signal G: STD_LOGIC;
    signal dp : STD_Logic;
    
    constant period:time :=10 ns;
    
begin
    genereSel: process
        begin
        sel <='0';
        wait for period;
        sel <='1';
        wait for period;
        sel <='0';
        wait for period;
        sel <='1';
        wait;
    end process;

    Affiche : Afficheur_Binaire PORT MAP(
        sel=>sel,
        A=>a,
        B=>b,
        C=>c,
        D=>d,
        E=>e,
        F=>f,
        G=>g,
        dp=>dp
    );
end Behavioral;