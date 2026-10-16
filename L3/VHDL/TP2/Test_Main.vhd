library IEEE;
use IEEE.STD_LOGIC_1164.ALL;

entity Test_Main is
end Test_Main;

architecture Behavioral of Test_Main is
    component Main
        Port ( e1 : in STD_LOGIC;
               e2 : in STD_LOGIC;
               a : out STD_LOGIC;
               b : out STD_LOGIC;
               c : out STD_LOGIC;
               d : out STD_LOGIC;
               e : out STD_LOGIC;
               f : out STD_LOGIC;
               g : out STD_LOGIC;
               dp : out STD_LOGIC;
               l1 : out STD_LOGIC;
               l2 : out STD_LOGIC);
    end component;
    
    signal A: STD_LOGIC;
    signal B: STD_LOGIC;
    signal C: STD_LOGIC;
    signal D: STD_LOGIC;
    signal E: STD_LOGIC;
    signal F: STD_LOGIC;
    signal G: STD_LOGIC;
    signal dp : STD_Logic;
    signal e1 : STD_Logic;
    signal e2 : STD_Logic;
    signal l1 : STD_Logic;
    signal l2 : STD_Logic;
    constant period:time :=10 ns;

begin
    genere: process
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

    Affiche : Main PORT MAP(
        e1=>e1,
        e2=>e2,
        l1=>l1,
        l2=>l2,
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
