#include <fstream>
#include <iostream>

#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <sys/mman.h>
#include <unistd.h>

#include <iomanip>
#include <cstring>

#include "defs.h"

using namespace std;

image read(const string& file_name)
{
    image img{nullptr, 0};
    ifstream fs_img_file(file_name, ios::binary);

    if (fs_img_file) {
        filebuf* pbuf = fs_img_file.rdbuf();

        img.size = pbuf->pubseekoff(0, fs_img_file.end, fs_img_file.in);
        pbuf->pubseekpos(0, fs_img_file.in);
        img.data = (block*)(new char[img.size]);

        pbuf->sgetn((char*)img.data, img.size);
        fs_img_file.close();
    }
    return img;
}

void display_dir(image& img, uint inumber)
{
    dinode* inodes = (dinode*)(img.data + 32);

    // Vérifier que l'inode est un répertoire
    if (inodes[inumber].type != 1) {
        cerr << "Inode " << inumber << " is not a directory" << endl;
        return;
    }

    // Parcours des adresses des blocs de données
    for (int i = 0; i < NDIRECT; ++i) {
        if (inodes[inumber].addrs[i] != 0) {
            dirent* entries = (dirent*)(img.data + inodes[inumber].addrs[i]);
            int num_entries = BSIZE / sizeof(dirent);
            for (int j = 0; j < num_entries; ++j) { // Parcours des entrées du répertoire
                if (entries[j].inum != 0) {
                    cout << "[ " << entries[j].inum << " ; " << entries[j].name << " ]" << endl;
                }
            }
        }
    }
}

void display_text_file(image& img, const string& file_name)
{
    dinode* inodes = (dinode*)(img.data + 32);
    int inumber = 0;

    // Parcours des adresses des blocs de données
    for (int i = 0; i < NDIRECT; ++i) {
        if (inodes[1].addrs[i] != 0) {
            dirent* entries = (dirent*)(img.data + inodes[1].addrs[i]);
            for (int j = 0; j < (int)(BSIZE / sizeof(dirent)); ++j) { // Parcours des entrées du répertoire
                if (entries[j].inum != 0 && entries[j].name == file_name) {
                    inumber = entries[j].inum;
                    break;
                }
            }
        }
    }

    if (inumber == 0) {
        cerr << "File " << file_name << " not found" << endl;
        return;
    }

    // Parcours des adresses des blocs de données
    char* data = (char*)(img.data + inodes[inumber].addrs[0]);
    for (uint i = 0; i < inodes[inumber].size; ++i) {
        cout << data[i];
    }
}

void display_info(image& img)
{
    superblock* sb = (superblock*)(&img.data[1]);

    uint IPB = BSIZE / sizeof(struct dinode);

    uint N = sb->size;
    uint Nb = 1;
    uint Ns = 1;
    uint Nl = sb->nlog;
    uint Ni = sb->ninodes / IPB + 1;
    uint Nm = N / (BSIZE * 8) + 1;
    uint Nd = sb->nblocks;

    uint l= sb->logstart ;
    uint i = sb->inodestart;
    uint m = sb->bmapstart;
    uint d = m + Nm;

    // Debug : affichage des valeurs
    cout << "IPB = " << IPB << "\n";
    cout << "N = " << N << " ; Nb = " << Nb << " ; Ns = " << Ns << " ; Nl = " << Nl << " ; Ni = " << Ni << " ; Nm = " << Nm << " ; Nd = " << Nd << "\n";
    cout << "l = " << l << " ; i = " << i << " ; m = " << m << " ; d = " << d << "\n";

    //cout << "BB: boot block      [0, 0]    = [0x00000000, 0x000003ff]\n";
    //cout << "SB: super block     [1, 1]    = [0x00000400, 0x000007ff]\n";
    //cout << "LB: log block       [" << l << ", "  <<  l + Nl - 1 << "]   = [0x00000800, 0x00007fff]\n";
    //cout << "IB: inode block     [" << i << ", " << i + Ni - 1 << "]  = [0x00008000, 0x0000b3ff]\n";
    //cout << "BB: bitmap block    [" << m << ", " << m + Nm - 1 << "]  = [0x0000b400, 0x0000b7ff]\n";
    //cout << "DB: data block      [" << d << ", " << d + Nd - 1 << "] = [0x0000b800, 0x000f9fff]\n";

    // Affichage des adresse de manière dynamique en decimal
    //cout << "BB: boot block      [0, 0]    = [" << 0 * BSIZE << ", " << 0 * BSIZE + BSIZE - 1 << "]\n";
    //cout << "SB: super block     [1, 1]    = [" << 1 * BSIZE << ", " << 1 * BSIZE + BSIZE - 1 << "]\n";
    //cout << "LB: log block       [" << l << ", " << l + Nl - 1 << "]   = [" << l * BSIZE << ", " << (l + Nl) * BSIZE - 1 << "]\n";
    //cout << "IB: inode block     [" << i << ", " << i + Ni - 1 << "]  = [" << i * BSIZE << ", " << (i + Ni) * BSIZE - 1 << "]\n";
    //cout << "BB: bitmap block    [" << m << ", " << m + Nm - 1 << "]  = [" << m * BSIZE << ", " << (m + Nm) * BSIZE - 1 << "]\n";
    //cout << "DB: data block      [" << d << ", " << d + Nd - 1 << "] = [" << d * BSIZE << ", " << (d + Nd) * BSIZE - 1 << "]\n";

    // Affichage des adresse de manière dynamique en hexadecimal
    cout << "BB: boot block      [0, 0]    = [0x" << setfill('0') << setw(8) << hex << 0 * BSIZE << ", 0x" << setfill('0') << setw(8) << hex << 0 * BSIZE + BSIZE - 1 << "]\n";
    cout << "SB: super block     [1, 1]    = [0x" << setfill('0') << setw(8) << hex << 1 * BSIZE << ", 0x" << setfill('0') << setw(8) << hex << 1 * BSIZE + BSIZE - 1 << "]\n";
    cout << "LB: log block       [" << l << ", " << l + Nl - 1 << "]   = [0x" << setfill('0') << setw(8) << hex << l * BSIZE << ", 0x" << setfill('0') << setw(8) << hex << (l + Nl) * BSIZE - 1 << "]\n";
    cout << "IB: inode block     [" << i << ", " << i + Ni - 1 << "]  = [0x" << setfill('0') << setw(8) << hex << i * BSIZE << ", 0x" << setfill('0') << setw(8) << hex << (i + Ni) * BSIZE - 1 << "]\n";
    cout << "BB: bitmap block    [" << m << ", " << m + Nm - 1 << "]  = [0x" << setfill('0') << setw(8) << hex << m * BSIZE << ", 0x" << setfill('0') << setw(8) << hex << (m + Nm) * BSIZE - 1 << "]\n";
    cout << "DB: data block      [" << d << ", " << d + Nd - 1 << "] = [0x" << setfill('0') << setw(8) << hex << d * BSIZE << ", 0x" << setfill('0') << setw(8) << hex << (d + Nd) * BSIZE - 1 << "]\n";
    cout << dec;

}

void display_inode(image& img)
{
    dinode* inodes = (dinode*)(img.data + 32);
    for (int i = 1; i < 19; ++i) {
        if (inodes[i].type != 0) {
            cout << "Inode " << i << ": type = ";
            switch (inodes[i].type) {
                case 0: cout << "UNUSED"; break;
                case 1: cout << "DIR"; break;
                case 2: cout << "FILE"; break;
                case 3: cout << "DEV"; break;
                default: cout << "UNKNOWN"; break;
            }
            cout << " ; size = " << inodes[i].size << " bytes ; links = " << inodes[i].nlink << endl;
        }
    }
}

void display_free_data_block(image& img)
{
    superblock* p = (superblock*)(&img.data[1]);
    uint8_t* q = (uint8_t*)(&img.data[p->bmapstart]);
    uint c1 = 0, c2 = 0;
    uint8_t mask = 1;
    uint m = 0, k = 0;
    for (uint i = 0; i < p->nblocks; ++i ) {
        if (!(q[m]&mask)) {
            ++c1;
        } else {
            ++c2;
        }
        ++k;
        if (k == 8) {
            k = 0;
            mask = 1;
            ++m;
        } else {
            mask <<= 1;
        }
    }
    cout << "Free block number = " << c1 << endl;
    cout << "No free block number = " << c2 << endl ;
    cout << "Total block number = " << p->nblocks << endl ;
}

void delete_file(image& img, const string& file_name)
{
    // Affichage du tableau bitmap avant suppression
    cout << "Before deletion of " << file_name << ":" << endl;
    display_free_data_block(img);

    dinode* inodes = (dinode*)(img.data + 32);
    dirent* entries = nullptr;
    int inumber = 0;

    // Parcours des adresses des blocs de données
    for (int i = 0; i < NDIRECT; ++i) {
        if (inodes[1].addrs[i] != 0) {
            entries = (dirent*)(img.data + inodes[1].addrs[i]);
            for (int j = 0; j < (int)(BSIZE / sizeof(dirent)); ++j) { // Parcours des entrées du répertoire
                if (entries[j].inum != 0 && entries[j].name == file_name) {
                    inumber = entries[j].inum;
                    break;
                }
            }
        }
    }

    if (inumber == 0) {
        cerr << "File " << file_name << " not found" << endl;
        return;
    }

    // Mise à jour de l'attribut type de l'inode
    dinode* inode = inodes + inumber;
    inode->type = 0;

    // Mise à zero des bits correspondants aux blocs de données utilisés par le fichier
    superblock* sb = (superblock*)(&img.data[1]);
    uint8_t* bitmap = (uint8_t*)(img.data + sb->bmapstart);

    // Parcours des adresses des blocs de données du fichier à supprimer
    for (int i = 0; i < NDIRECT && inode->addrs[i] != 0; ++i) {
        bitmap[inode->addrs[i] / 8] &= ~(1 << (inode->addrs[i] % 8));
    }

    // Retrait de l'entrée correspondant au fichier dans le répertoire
    int num_entries = BSIZE / sizeof(dirent);

    // Parcours des entrées de répertoire dans le bloc de données
    for (int i = 0; i < num_entries; ++i) {
        if (entries[i].inum == inumber) {
            entries[i].inum = 0;
            memset(entries[i].name, 0, DIRSIZ);
            break;
        }
    }

    // Affichage du tableau bitmap après suppression
    cout << "\nAfter deletion of " << file_name << ":" << endl;
    display_free_data_block(img);

    // Verification que le fichier n'apparait plus en appelant display_dir
    cout << "\nAfter deletion of " << file_name << ":" << endl;
    display_dir(img, 1);
}

void new_directory(image& img, const string& directory_name)
{
    dinode* inodes = (dinode*)(img.data + 32);
    //dirent* entries = nullptr;
    int inumber = 0;

    ////////// Réserver un bloc d'inode //////////

    for (int i = 1; i < (int)NDIRECT + 1; ++i) {
        if (inodes[i].type == 0) {
            inumber = i;
            break;
        }
    }

    if (inumber == 0) {
        cerr << "No free inode found" << endl;
        return;
    }

    ////////// Réserver le premier bloc de données libre //////////

    superblock* sb = (superblock*)(&img.data[1]);
    uint8_t* bitmap = (uint8_t*)(img.data + sb->bmapstart);
    int data_block = 0;

    for (int i = 0; i < (int)sb->nblocks; ++i) {
        if ((bitmap[i / 8] & (1 << (i % 8))) == 0) {
            data_block = i;
            break;
        }
    }

    if (data_block == 0) {
        cerr << "No free data block found" << endl;
        return;
    }

    cout << "Inode " << inumber << " reserved for directory " << directory_name << endl;
    cout << "Data block " << data_block << " reserved for directory " << directory_name << endl;

    ////////// Initialisation du nouveau répertoire //////////

    // Mise à jour de l'inode
    dinode* inode = inodes + inumber;
    inode->type = 1;
    inode->size = BSIZE;
    inode->addrs[0] = data_block;

    // Mise à jour du bloc de données
    dirent* dir = (dirent*)(img.data + inode->addrs[0]);
    dir[0].inum = inumber;
    strcpy(dir[0].name, ".");
    dir[1].inum = 1;
    strcpy(dir[1].name, "..");

    // Effacement des entrées restantes
    for (int i = 2; i < (int)(BSIZE / sizeof(dirent)); ++i) {
        dir[i].inum = 0;
        memset(dir[i].name, 0, DIRSIZ);
    }

    ////////// Mise à jour du répertoire racine //////////

    // Parcours des adresses des blocs de données
    for (int i = 0; i < NDIRECT; ++i) {
        if (inodes[1].addrs[i] != 0) {
            dirent* entries = (dirent*)(img.data + inodes[1].addrs[i]);
            for (int j = 0; j < (int)(BSIZE / sizeof(dirent)); ++j) { // Parcours des entrées du répertoire
                if (entries[j].inum == 0) {
                    entries[j].inum = inumber;
                    strcpy(entries[j].name, directory_name.c_str());
                    break;
                }
            }
        }
    }

    ////////// Affichage des résultats //////////

    // Mise à jour du bitmap
    bitmap[data_block / 8] |= (1 << (data_block % 8));

    // Affichage du tableau bitmap après création
    cout << "\nAfter creation of " << directory_name << ":" << endl;
    display_free_data_block(img);

    // Affichage des inodes après création
    cout << "\nAfter creation of " << directory_name << ":" << endl;
    display_inode(img);

    // Affichage du contenu du répertoire racine après création
    cout << "\nContent of root directory:" << endl;
    display_dir(img, 1);
}

void new_file(image& img, const string& file_name, char* buffer, uint size)
{
    dinode* inodes = (dinode*)(img.data + 32);
    dirent* entries = nullptr;
    int inumber = 0;

    ////////// Réserver un bloc d'inode //////////

    for (int i = 1; i < (int)NDIRECT + 1; ++i) {
        if (inodes[i].type == 0) {
            inumber = i;
            break;
        }
    }

    if (inumber == 0) {
        cerr << "No free inode found" << endl;
        return;
    }

    ////////// Réserver le premier bloc de données libre //////////

    superblock* sb = (superblock*)(&img.data[1]);
    uint8_t* bitmap = (uint8_t*)(img.data + sb->bmapstart);
    int data_block = 0;

    for (int i = 0; i < (int)sb->nblocks; ++i) {
        if ((bitmap[i / 8] & (1 << (i % 8))) == 0) {
            data_block = i;
            break;
        }
    }

    if (data_block == 0) {
        cerr << "No free data block found" << endl;
        return;
    }

    cout << "Inode " << inumber << " reserved for file " << file_name << endl;
    cout << "Data block " << data_block << " reserved for file " << file_name << endl;

    ////////// Initialisation du nouveau fichier //////////

    // Mise à jour de l'inode
    dinode* inode = inodes + inumber;
    inode->type = 2;
    inode->size = size;
    inode->addrs[0] = data_block;

    // Mise à jour du bloc de données
    char* data = (char*)(img.data + inode->addrs[0]);
    for (uint i = 0; i < size; ++i) {
        data[i] = buffer[i];
    }

    // Mise à jour du bitmap
    bitmap[data_block / 8] |= (1 << (data_block % 8));

    ////////// Mise à jour du répertoire racine //////////

    // Parcours des adresses des blocs de données
    for (int i = 0; i < NDIRECT; ++i) {
        if (inodes[1].addrs[i] != 0) {
            entries = (dirent*)(img.data + inodes[1].addrs[i]);
            for (int j = 0; j < (int)(BSIZE / sizeof(dirent)); ++j) { // Parcours des entrées du répertoire
                if (entries[j].inum == 0) {
                    entries[j].inum = inumber;
                    strcpy(entries[j].name, file_name.c_str());
                    break;
                }
            }
        }
    }

    ////////// Affichage des résultats //////////

    // Affichage du tableau bitmap après création
    cout << "\nAfter creation of " << file_name << ":" << endl;
    display_free_data_block(img);

    // Affichage des inodes après création
    cout << "\nAfter creation of " << file_name << ":" << endl;
    display_inode(img);

    // Affichage du contenu du répertoire racine après création
    cout << "\nContent of root directory:" << endl;
    display_dir(img, 1);

    // Affichage du contenu du fichier après création
    cout << "\nContent of " << file_name << ":" << endl;
    display_text_file(img, file_name);
}

int main(int argc, char* argv[])
{
    if (argc == 2) {
        image img = read(argv[1]);

        if (img.data) {
            cout << "Question 1 : Affichage des informations de l'image\n";
            display_info(img);

            cout << "\n\nQuestion 2 : Affichage des inodes\n";
            display_inode(img);

            cout << "\n\nQuestion 3 : Affichage des entrées du répertoire racine\n";
            display_dir(img, 1);

            cout << "\n\nQuestion 5 : Affichage du contenu du fichier README\n";
            display_text_file(img, "README");

            cout << "\n\nQuestion 6 : Affichage du nombre de blocs libres\n";
            delete_file(img, "README");

            //cout << "\n\nQuestion 7 : Création d'un nouveau répertoire\n";
            //new_directory(img, "new_directory");

            cout << "\n\nQuestion 8 : Création d'un nouveau fichier\n";
            char buffer[2100] = "Hello, World!\n";
            new_file(img, "new_file", buffer, 14);

            delete[] img.data;
            return 0;
        }
    }
    return -1;
}

// $ rm -f fs.img && cp fs_vierge.img fs.img && clear && make && ./main fs.img > output.txt
