#define V2 ImVec2
#define S sinf
#define C cosf
#define I int
#define F float
#define CL(x,l,h) (((x)>(h))?(h):(((x)<(l))?(l):(x)))
#define PI 3.1415926535
#define CO(c,b) (int(c*255)<<b)
void FX(ImDrawList* d, V2 a, V2 b, V2 s, ImVec4 m, float t)
{
    t *= 3;
    F ix = s.x / 320;
    F iy = s.y / 180;
    F sz = s.x / 15;
    for (F x = a.x; x < b.x; x += ix)
        for (F y = a.y; y < b.y; y += iy) {
            F v = 0;
            v += S((x / sz + t));
            v += S((y / sz + t) / 2.0f);
            v += S((x / sz + y / sz + t) / 2.0f);
            F cx = x / sz / 10 + 0.3 * S(t / 3.0);
            F cy = y / sz / 10 + 0.3f * C(t / 2.0);
            v += S(sqrt(100 * (cx * cx + cy * cy + 1)) + t);
            v = CL(v / 2, 0, 1);
            F r = S(v * PI) * .5f + .5f;
            F g = S(v * PI + PI / 3) * .5f + .5f;
            F b = S(v * PI + PI) * .5f + .5f;
            d->AddQuadFilled({ x,y }, { x + ix,y }, { x + ix,y + iy }, { x,y + iy }, 0xff000000 | CO(b, 16) | CO(g, 8) | CO(r, 0));
        }
}