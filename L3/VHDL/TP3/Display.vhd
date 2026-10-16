library IEEE;
use IEEE.STD_LOGIC_1164.ALL;



entity Display is
    Port ( s : in STD_LOGIC;
           err : in STD_LOGIC; -- 1 en cas d'erreur
           a : out STD_LOGIC;
           b : out STD_LOGIC;
           c : out STD_LOGIC;
           d : out STD_LOGIC;
           e : out STD_LOGIC;
           f : out STD_LOGIC;
           g : out STD_LOGIC;
           dp : out STD_LOGIC);
end Display;

architecture Behavioral of Display is

begin
    a<='0' when s='0' and err='0' else '1';
    b<=err;
    c<=err;
    d<='0' when s='0' and err='0' else '1';
    e<='0' when s='0' and err='0' else '1';
    f<='0' when s='0' and err='0' else '1';
    g<='0' when err='1' else '1';
    dp<='1';
end Behavioral;
