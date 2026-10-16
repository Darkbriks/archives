library IEEE;
use IEEE.STD_LOGIC_1164.ALL;

entity Display is
    Port ( s : in STD_LOGIC;
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
    a<=s;
    b<='0';
    c<='0';
    d<=s;
    e<=s;
    f<=s;
    g<='1';
    dp<='1';
end Behavioral;
