using V = ImVec2; using I = int; using F = float; using B = bool;
#define T static
#define W 320
#define H 180
#define FR(i,m) for(I i=0;i<m;++i)
#define A d->AddRectFilled
struct B2 { V l, h; B a = 1; I c = ~0; B in(V p) { return(p.x > l.x && p.x < h.x) && (p.y > l.y && p.y < h.y); } };
void FX(ImDrawList* d, V a, V b, V s, ImVec4 m, float t) { T B re = 1; T F cx, cy, r, vx, vy; T F lt = t; T F dt = 0; T F bw = W / 10; T F bh = H / 12; T B2 br[60]; T B2 p{ {0,b.y - 5},{0,b.y} }; if (re) { cx = a.x + W / 2; cy = a.y + H - 8; r = 3; vx = -1; vy = -3; FR(i, 6)FR(j, 10) { B2& b = br[j + i * 10]; b.a = 1; b.l = { a.x + j * bw,a.y + i * bh }; b.h = { a.x + (j + 1) * bw,a.y + (i + 1) * bh }; b.c = 255 << 24 | rand(); }re = 0; }FR(i, 60) { B2& b = br[i]; if (!b.a)continue; if (!b.in({ cx,cy }))continue; b.a = 0; F ol = cx - b.l.x; F or = b.h.x - cx; F ot = cy - b.l.y; F ob = b.h.y - cy; F ox = min(ol, or ); F oy = min(ot, ob); B lo = ol < ob; B to = ot < ob; ox < oy ? vx = -vx : vy = -vy; }dt = t - lt; lt = t; p.l.x = a.x + m.x * s.x - 20; p.h.x = p.l.x + 40; if (p.in({ cx,cy }))vy = -vy; FR(i, 60) { B2& b = br[i]; if (b.a)A(b.l, b.h, b.c); }A(p.l, p.h, ~0); d->AddCircleFilled({ cx,cy }, r, ~0); cx += vx * dt * 30; cy += vy * dt * 30; if (cx<a.x || cx>b.x)vx = -vx; if (cy < a.y)vy = -vy; if (!m.w)re = 1; }