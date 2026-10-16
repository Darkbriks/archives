library IEEE;
use IEEE.STD_LOGIC_1164.ALL;

entity Main is
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
end Main;

architecture Behavioral of Main is
    
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
    
    component Gate_And
        Port ( e1 : in STD_LOGIC;
            e2 : in STD_LOGIC;
            s : out STD_LOGIC);
    end component;
    signal s: STD_LOGIC;
begin
    Transmit : Gate_And PORT MAP(
        e1=>e1,
        e2=>e2,
        s=>s
    );
    
    Afficher : Afficheur_Binaire PORT MAP(
        sel=>s,
        A=>a,
        B=>b,
        C=>c,
        D=>d,
        E=>e,
        F=>f,
        G=>g,
        dp=>dp
    );
    
    l1<='1' when e1='1' else '0';
    l2<='1' when e2='1' else '0';
end Behavioral;
