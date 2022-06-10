#include "User.h"
#include "Board.h"

User::User(Id _id) : id(_id) {}

bool User::CheckWin(Cells& cells)
{
    if ((IsCellForYou(cells[0][0])) &&
        ((IsCellForYou(cells[0][1]) && IsCellForYou(cells[0][2])) ||
            (IsCellForYou(cells[1][0]) && IsCellForYou(cells[2][0])) ||
            (IsCellForYou(cells[1][1]) && IsCellForYou(cells[2][2]))))
        return true;
    if ((IsCellForYou(cells[1][1])) &&
        ((IsCellForYou(cells[1][0]) && IsCellForYou(cells[1][2])) ||
            (IsCellForYou(cells[0][1]) && IsCellForYou(cells[2][1])) ||
            (IsCellForYou(cells[0][2]) && IsCellForYou(cells[2][0]))))
        return true;
    if ((IsCellForYou(cells[2][2])) &&
        ((IsCellForYou(cells[2][1]) && IsCellForYou(cells[2][0])) ||
            (IsCellForYou(cells[1][2]) && IsCellForYou(cells[0][2]))))
        return true;
    return false;
}

bool User::IsCellForYou(Cell& cell)
{
    return cell.PutPieces && cell.PutPieces->id == this->id;
}
