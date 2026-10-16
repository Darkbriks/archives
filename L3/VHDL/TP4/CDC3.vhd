library IEEE;
use IEEE.STD_LOGIC_1164.ALL;

entity CDC3 is
    Port ( in_a : in STD_LOGIC;
           in_b : in STD_LOGIC;
           in_c : in STD_LOGIC;
           i : in STD_LOGIC;
           a : out STD_LOGIC;
           b : out STD_LOGIC;
           c : out STD_LOGIC;
           d : out STD_LOGIC;
           e : out STD_LOGIC;
           f : out STD_LOGIC;
           g : out STD_LOGIC;
           dp : out STD_LOGIC;
           led_a : out STD_LOGIC;
           led_b : out STD_LOGIC;
           led_c : out STD_LOGIC;
           led_i : out STD_LOGIC);
end CDC3;

architecture Behavioral of CDC3 is
    component Select_Id_Blake
        Port ( res_id_1 : in STD_LOGIC;
               res_id_2 : in STD_LOGIC;
               selected_id : in STD_LOGIC;
               result : out STD_LOGIC);
    end component;
    
    component Id_Blake_1
        Port ( a : in STD_LOGIC;
               b : in STD_LOGIC;
               c : in STD_LOGIC;
               res : out STD_LOGIC);
    end component;
    
    component Id_Blake_2
        Port ( a : in STD_LOGIC;
               b : in STD_LOGIC;
               c : in STD_LOGIC;
               res : out STD_LOGIC);
    end component;
    
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
    
    signal res_id_1 : std_logic;
    signal res_id_2 : std_logic;
    signal result : std_logic;
begin
    led_a<=in_a;
    led_b<=in_b;
    led_c<=in_c;
    led_i<=i;
    
    Compute_Id_Blake_1 : Id_Blake_1 PORT MAP(in_a, in_b, in_c, res_id_1);
    Compute_Id_Blake_2 : Id_Blake_2 PORT MAP(in_a, in_b, in_c, res_id_2);
    
    Select_Id : Select_Id_Blake PORT MAP(res_id_1, res_id_2, i, result);
    
    Display_Result : Display PORT MAP(result, a, b, c, d, e, f, g, dp);
end Behavioral;
