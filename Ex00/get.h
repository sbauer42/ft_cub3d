typedef struct  s_data {
    void        *img;
    char        *addr;
    int         bits_per_pixel;
    int         line_length;
    int         endian;
}               t_data;

typedef struct  s_map {
    int         floor;
    int         ceil;
    int         res[2];
    char        **map;
    char        *NO;
    char        *SO;
    char        *WE;
    char        *EA;
}               t_map;