/* ===== 23e2f5010 ui.ios_toggle:68 ===== */
/* ghidra_name=FUN_23e2f5010 entry=23e2f5010 size=6396 */

/* WARNING: Type propagation algorithm not settling */
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

code * FUN_23e2f5010(longlong param_1,undefined8 param_2,undefined8 *param_3)

{
  longlong lVar1;
  longlong *plVar2;
  longlong *plVar3;
  undefined8 *puVar4;
  longlong *plVar5;
  code *pcVar6;
  int iVar7;
  longlong lVar8;
  longlong *plVar9;
  longlong *plVar10;
  longlong *plVar11;
  longlong *plVar12;
  longlong *plVar13;
  longlong *plVar14;
  longlong *plVar15;
  longlong lVar16;
  undefined4 uVar17;
  undefined4 uVar18;
  longlong *plStack_b0;
  longlong *plStack_a8;
  longlong *plStack_98;
  longlong *plStack_88;
  longlong *plStack_80;
  longlong *plStack_78;
  longlong *plStack_70;
  longlong *plStack_68;
  longlong *plStack_60;
  
  plVar11 = _DAT_23eeb0018;
  plVar2 = (longlong *)*param_3;
  plVar3 = (longlong *)param_3[1];
  if (_DAT_23eeb0018 == (longlong *)0x0) {
LAB_23e2f5059:
    _DAT_23eeb0018 = (longlong *)FUN_23e91f3b0(param_1,_DAT_23eeb0010,DAT_23eeb0078,0x20);
  }
  else {
    lVar8 = *_DAT_23eeb0018;
    if (1 < lVar8) {
      *_DAT_23eeb0018 = lVar8 + -1;
      goto LAB_23e2f5059;
    }
    if (_DAT_23eeb0018[2] != 0) {
      *_DAT_23eeb0018 = lVar8 + -1;
      if (lVar8 + -1 == 0) {
        (**(code **)(plVar11[1] + 0x30))(plVar11);
      }
      goto LAB_23e2f5059;
    }
  }
  plVar5 = _DAT_23eeb0018;
  lVar8 = *(longlong *)(param_1 + 0x38);
  plVar11 = _DAT_23eeb0018 + 9;
  lVar16 = *(longlong *)(lVar8 + 8);
  _DAT_23eeb0018[0xf] = lVar16;
  *(longlong **)(lVar8 + 8) = plVar11;
  if ((lVar16 != 0) &&
     (((*(char *)(lVar16 + 0x45) == '\x01' ||
       ((ulonglong)
        (*(longlong *)(lVar16 + 0x20) + 0xb8 +
        (longlong)*(int *)(*(longlong *)(lVar16 + 0x20) + 0xa8) * 2) <=
        *(ulonglong *)(lVar16 + 0x38))) && (plVar5[0xe] != 0)))) {
    plVar11 = *(longlong **)(lVar16 + 0x28);
    *(longlong **)(plVar5[0xe] + 0x10) = plVar11;
    if (plVar11 != (longlong *)0x0) {
      *plVar11 = *plVar11 + 1;
    }
  }
  *plVar5 = *plVar5 + 1;
  *(undefined4 *)(plVar5 + 8) = 0;
  lVar8 = FUN_23e8f5ad0();
  if (lVar8 == 0) {
    plVar12 = (longlong *)0x0;
    FUN_23e915740(param_1,&plStack_88,_DAT_23eeace68);
    uVar18 = 0x46;
    plStack_b0 = plStack_88;
    plStack_a8 = plStack_80;
    plVar9 = (longlong *)0x0;
    plVar11 = plStack_78;
    goto LAB_23e2f5b00;
  }
  *(undefined4 *)(plVar5 + 5) = 0x46;
  plVar9 = (longlong *)FUN_23e914090(param_1,lVar8,plVar2);
  if (plVar9 == (longlong *)0x0) {
    plStack_b0 = *(longlong **)(param_1 + 0x60);
    plVar11 = *(longlong **)(param_1 + 0x70);
    plVar12 = (longlong *)0x0;
    *(undefined8 *)(param_1 + 0x70) = 0;
    uVar18 = 0x46;
    plStack_a8 = *(longlong **)(param_1 + 0x68);
    *(undefined1 (*) [16])(param_1 + 0x60) = (undefined1  [16])0x0;
    goto LAB_23e2f5b00;
  }
  plVar10 = (longlong *)FUN_23e8bc2f0(plVar9,_DAT_23eeace70);
  if (plVar10 == (longlong *)0x0) {
    plStack_b0 = *(longlong **)(param_1 + 0x60);
    plVar11 = *(longlong **)(param_1 + 0x70);
    plVar12 = (longlong *)0x0;
    *(undefined8 *)(param_1 + 0x70) = 0;
    uVar18 = 0x47;
    plStack_a8 = *(longlong **)(param_1 + 0x68);
    *(undefined1 (*) [16])(param_1 + 0x60) = (undefined1  [16])0x0;
    goto LAB_23e2f5b00;
  }
  lVar8 = FUN_23e8f5ad0();
  if (lVar8 == 0) {
    FUN_23e915740(param_1,&plStack_88,_DAT_23eeace68);
    plStack_b0 = plStack_88;
    plStack_a8 = plStack_80;
    plVar11 = plStack_78;
LAB_23e2f5ade:
    *plVar10 = *plVar10 + -1;
    lVar8 = *plVar10;
    uVar18 = 0x47;
    uVar17 = 0x47;
  }
  else {
    plVar11 = (longlong *)FUN_23e8bc2f0(lVar8,_DAT_23eeace78);
    if (plVar11 == (longlong *)0x0) {
      plStack_b0 = *(longlong **)(param_1 + 0x60);
      plVar11 = *(longlong **)(param_1 + 0x70);
      *(undefined8 *)(param_1 + 0x70) = 0;
      plStack_a8 = *(longlong **)(param_1 + 0x68);
      *(undefined1 (*) [16])(param_1 + 0x60) = (undefined1  [16])0x0;
      goto LAB_23e2f5ade;
    }
    plVar12 = (longlong *)FUN_23e8bc2f0(plVar11,_DAT_23eeace80);
    *plVar11 = *plVar11 + -1;
    if (*plVar11 == 0) {
      (**(code **)(plVar11[1] + 0x30))(plVar11);
    }
    if (plVar12 == (longlong *)0x0) {
      plStack_b0 = *(longlong **)(param_1 + 0x60);
      plVar11 = *(longlong **)(param_1 + 0x70);
      *(undefined8 *)(param_1 + 0x70) = 0;
      plStack_a8 = *(longlong **)(param_1 + 0x68);
      *(undefined1 (*) [16])(param_1 + 0x60) = (undefined1  [16])0x0;
      *plVar10 = *plVar10 + -1;
      if (*plVar10 == 0) {
        plVar12 = (longlong *)0x0;
        (**(code **)(plVar10[1] + 0x30))(plVar10);
        uVar18 = 0x47;
      }
      else {
        plVar12 = (longlong *)0x0;
        uVar18 = 0x47;
      }
      goto LAB_23e2f5b00;
    }
    *(undefined4 *)(plVar5 + 5) = 0x47;
    plVar11 = (longlong *)FUN_23e914090(param_1,plVar10,plVar12);
    *plVar10 = *plVar10 + -1;
    if (*plVar10 == 0) {
      (**(code **)(plVar10[1] + 0x30))(plVar10);
    }
    *plVar12 = *plVar12 + -1;
    if (*plVar12 == 0) {
      (**(code **)(plVar12[1] + 0x30))(plVar12);
    }
    if (plVar11 == (longlong *)0x0) {
      plStack_b0 = *(longlong **)(param_1 + 0x60);
      plVar11 = *(longlong **)(param_1 + 0x70);
      uVar18 = 0x47;
      *(undefined8 *)(param_1 + 0x70) = 0;
      plStack_a8 = *(longlong **)(param_1 + 0x68);
      *(undefined1 (*) [16])(param_1 + 0x60) = (undefined1  [16])0x0;
      plVar12 = (longlong *)0x0;
      goto LAB_23e2f5b00;
    }
    *plVar11 = *plVar11 + -1;
    if (*plVar11 == 0) {
      (**(code **)(plVar11[1] + 0x30))(plVar11);
    }
    *(undefined4 *)(plVar5 + 5) = 0x4a;
    plVar10 = (longlong *)FUN_23e91bfe0(param_1,plVar2,_DAT_23eeace88);
    if (plVar10 == (longlong *)0x0) {
      plStack_b0 = *(longlong **)(param_1 + 0x60);
      plVar11 = *(longlong **)(param_1 + 0x70);
      uVar18 = 0x4a;
      *(undefined8 *)(param_1 + 0x70) = 0;
      plStack_a8 = *(longlong **)(param_1 + 0x68);
      *(undefined1 (*) [16])(param_1 + 0x60) = (undefined1  [16])0x0;
      plVar12 = (longlong *)0x0;
      goto LAB_23e2f5b00;
    }
    iVar7 = FUN_23a35f020(plVar10);
    lVar8 = *plVar10 + -1;
    if (iVar7 == -1) {
      plStack_b0 = *(longlong **)(param_1 + 0x60);
      plVar11 = *(longlong **)(param_1 + 0x70);
      *(undefined8 *)(param_1 + 0x70) = 0;
      plStack_a8 = *(longlong **)(param_1 + 0x68);
      *(undefined1 (*) [16])(param_1 + 0x60) = (undefined1  [16])0x0;
      *plVar10 = lVar8;
      if (lVar8 == 0) {
        plVar12 = (longlong *)0x0;
        (**(code **)(plVar10[1] + 0x30))(plVar10);
        uVar18 = 0x4a;
      }
      else {
        uVar18 = 0x4a;
        plVar12 = (longlong *)0x0;
      }
      goto LAB_23e2f5b00;
    }
    *plVar10 = lVar8;
    if (lVar8 == 0) {
      (**(code **)(plVar10[1] + 0x30))(plVar10);
    }
    if (iVar7 == 0) {
      plVar10 = (longlong *)FUN_23e8bc2f0(plVar9,_DAT_23eeace90);
      if (plVar10 == (longlong *)0x0) {
LAB_23e2f60f0:
        plStack_b0 = *(longlong **)(param_1 + 0x60);
        plVar11 = *(longlong **)(param_1 + 0x70);
        plVar12 = (longlong *)0x0;
        *(undefined8 *)(param_1 + 0x70) = 0;
        uVar18 = 0x4f;
        plStack_a8 = *(longlong **)(param_1 + 0x68);
        *(undefined1 (*) [16])(param_1 + 0x60) = (undefined1  [16])0x0;
        goto LAB_23e2f5b00;
      }
      lVar8 = FUN_23e8f5980();
      if (lVar8 == 0) {
        FUN_23e915740(param_1,&plStack_88,_DAT_23eeace98);
        plStack_b0 = plStack_88;
        plStack_a8 = plStack_80;
        plVar11 = plStack_78;
      }
      else {
        *(undefined4 *)(plVar5 + 5) = 0x4f;
        plVar11 = (longlong *)FUN_23e957a30(param_1,lVar8,_DAT_23eeacea8);
        if (plVar11 != (longlong *)0x0) {
          *(undefined4 *)(plVar5 + 5) = 0x4f;
          plVar12 = (longlong *)FUN_23e914090(param_1,plVar10,plVar11);
          *plVar10 = *plVar10 + -1;
          if (*plVar10 == 0) {
            (**(code **)(plVar10[1] + 0x30))(plVar10);
          }
          *plVar11 = *plVar11 + -1;
          if (*plVar11 == 0) {
            (**(code **)(plVar11[1] + 0x30))(plVar11);
          }
          if (plVar12 == (longlong *)0x0) goto LAB_23e2f60f0;
LAB_23e2f53b3:
          *plVar12 = *plVar12 + -1;
          if (*plVar12 == 0) {
            (**(code **)(plVar12[1] + 0x30))(plVar12);
          }
          plVar10 = (longlong *)FUN_23e8bc2f0(plVar9,_DAT_23eeaceb0);
          if (plVar10 == (longlong *)0x0) {
            plStack_b0 = *(longlong **)(param_1 + 0x60);
            plVar11 = *(longlong **)(param_1 + 0x70);
            plVar12 = (longlong *)0x0;
            *(undefined8 *)(param_1 + 0x70) = 0;
            uVar18 = 0x51;
            plStack_a8 = *(longlong **)(param_1 + 0x68);
            *(undefined1 (*) [16])(param_1 + 0x60) = (undefined1  [16])0x0;
            goto LAB_23e2f5b00;
          }
          lVar8 = *(longlong *)(DAT_23eead078 + 0x20);
          if (*(char *)(lVar8 + 10) == '\0') {
            plVar11 = (longlong *)FUN_23a37a020(DAT_23eead078,_DAT_23eeaceb8);
            if (plVar11 == (longlong *)0x0) goto LAB_23e2f5f30;
            lVar16 = *plVar11;
LAB_23e2f5f24:
            if (lVar16 == 0) goto LAB_23e2f5f30;
          }
          else {
            iVar7 = *(int *)(lVar8 + 0xc);
            if (*(int *)(lVar8 + 0xc) == 0) {
              *(int *)(lVar8 + 0xc) = DAT_23ec14e28;
              iVar7 = DAT_23ec14e28;
              DAT_23ec14e28 = DAT_23ec14e28 + 1;
            }
            if (_DAT_23ec14e20 != iVar7) {
              _DAT_23ec14e20 = iVar7;
              _DAT_23eeb0008 =
                   FUN_23e8cbd60(lVar8,_DAT_23eeaceb8,*(undefined8 *)(_DAT_23eeaceb8 + 0x18));
            }
            if (-1 < _DAT_23eeb0008) {
              lVar1 = lVar8 + 0x20 + (1L << (*(byte *)(lVar8 + 9) & 0x3f));
              lVar16 = *(longlong *)(lVar1 + 8 + _DAT_23eeb0008 * 0x10);
              if (lVar16 != 0) goto LAB_23e2f544c;
              _DAT_23eeb0008 =
                   FUN_23e8cbd60(lVar8,_DAT_23eeaceb8,*(undefined8 *)(_DAT_23eeaceb8 + 0x18));
              if (-1 < _DAT_23eeb0008) {
                lVar16 = *(longlong *)(lVar1 + 8 + _DAT_23eeb0008 * 0x10);
                goto LAB_23e2f5f24;
              }
            }
LAB_23e2f5f30:
            plVar11 = (longlong *)FUN_23a37a020(DAT_23ed6ccc0,_DAT_23eeaceb8);
            if ((plVar11 == (longlong *)0x0) || (lVar16 = *plVar11, lVar16 == 0)) {
              FUN_23e915740(param_1,&plStack_88,_DAT_23eeaceb8);
              plVar11 = plStack_78;
              plStack_b0 = plStack_88;
              *plVar10 = *plVar10 + -1;
              plStack_a8 = plStack_80;
              if (*plVar10 == 0) {
                plVar12 = (longlong *)0x0;
                (**(code **)(plVar10[1] + 0x30))(plVar10);
                uVar18 = 0x51;
              }
              else {
                uVar18 = 0x51;
                plVar12 = (longlong *)0x0;
              }
              goto LAB_23e2f5b00;
            }
          }
LAB_23e2f544c:
          plVar11 = (longlong *)FUN_23e8bc2f0(lVar16,_DAT_23eeacec0);
          if (plVar11 == (longlong *)0x0) {
            plStack_b0 = *(longlong **)(param_1 + 0x60);
            plVar11 = *(longlong **)(param_1 + 0x70);
            *(undefined8 *)(param_1 + 0x70) = 0;
            uVar18 = 0x51;
            uVar17 = 0x51;
            plStack_a8 = *(longlong **)(param_1 + 0x68);
            *(undefined1 (*) [16])(param_1 + 0x60) = (undefined1  [16])0x0;
            *plVar10 = *plVar10 + -1;
            lVar8 = *plVar10;
            goto joined_r0x00023e2f66c4;
          }
          plVar12 = (longlong *)FUN_23e8bc2f0(plVar11,_DAT_23eeacec8);
          *plVar11 = *plVar11 + -1;
          if (*plVar11 == 0) {
            (**(code **)(plVar11[1] + 0x30))(plVar11);
          }
          if (plVar12 == (longlong *)0x0) {
            plStack_b0 = *(longlong **)(param_1 + 0x60);
            plVar11 = *(longlong **)(param_1 + 0x70);
            *(undefined8 *)(param_1 + 0x70) = 0;
            plStack_a8 = *(longlong **)(param_1 + 0x68);
            *(undefined1 (*) [16])(param_1 + 0x60) = (undefined1  [16])0x0;
            *plVar10 = *plVar10 + -1;
            if (*plVar10 == 0) {
              plVar12 = (longlong *)0x0;
              (**(code **)(plVar10[1] + 0x30))(plVar10);
              uVar18 = 0x51;
            }
            else {
              plVar12 = (longlong *)0x0;
              uVar18 = 0x51;
            }
            goto LAB_23e2f5b00;
          }
          *(undefined4 *)(plVar5 + 5) = 0x51;
          plVar11 = (longlong *)FUN_23e914090(param_1,plVar10,plVar12);
          *plVar10 = *plVar10 + -1;
          if (*plVar10 == 0) {
            (**(code **)(plVar10[1] + 0x30))(plVar10);
          }
          *plVar12 = *plVar12 + -1;
          if (*plVar12 == 0) {
            (**(code **)(plVar12[1] + 0x30))(plVar12);
          }
          if (plVar11 == (longlong *)0x0) {
            plStack_b0 = *(longlong **)(param_1 + 0x60);
            plVar11 = *(longlong **)(param_1 + 0x70);
            uVar18 = 0x51;
            *(undefined8 *)(param_1 + 0x70) = 0;
            plStack_a8 = *(longlong **)(param_1 + 0x68);
            *(undefined1 (*) [16])(param_1 + 0x60) = (undefined1  [16])0x0;
            plVar12 = (longlong *)0x0;
            goto LAB_23e2f5b00;
          }
          *plVar11 = *plVar11 + -1;
          if (*plVar11 == 0) {
            (**(code **)(plVar11[1] + 0x30))(plVar11);
          }
          plVar10 = (longlong *)FUN_23e8bc2f0(plVar9,_DAT_23eeaced0);
          plVar11 = DAT_23ed6ccf0;
          if (plVar10 == (longlong *)0x0) {
LAB_23e2f6280:
            plStack_b0 = *(longlong **)(param_1 + 0x60);
            plVar11 = *(longlong **)(param_1 + 0x70);
            plVar12 = (longlong *)0x0;
            *(undefined8 *)(param_1 + 0x70) = 0;
            uVar18 = 0x52;
            plStack_a8 = *(longlong **)(param_1 + 0x68);
            *(undefined1 (*) [16])(param_1 + 0x60) = (undefined1  [16])0x0;
            goto LAB_23e2f5b00;
          }
          plVar15 = (longlong *)FUN_23e8bc2f0(plVar2,DAT_23eeacd38);
          if (plVar15 == (longlong *)0x0) {
            plStack_b0 = *(longlong **)(param_1 + 0x60);
            plVar11 = *(longlong **)(param_1 + 0x70);
            *(undefined8 *)(param_1 + 0x70) = 0;
            uVar18 = 0x52;
            uVar17 = 0x52;
            plStack_a8 = *(longlong **)(param_1 + 0x68);
            *(undefined1 (*) [16])(param_1 + 0x60) = (undefined1  [16])0x0;
            *plVar10 = *plVar10 + -1;
            lVar8 = *plVar10;
            goto joined_r0x00023e2f66c4;
          }
          plVar12 = (longlong *)FUN_23e8bc2f0(plVar2,DAT_23eeacd48);
          if (plVar12 == (longlong *)0x0) {
            plStack_b0 = *(longlong **)(param_1 + 0x60);
            plVar11 = *(longlong **)(param_1 + 0x70);
            *(undefined8 *)(param_1 + 0x70) = 0;
            plStack_a8 = *(longlong **)(param_1 + 0x68);
            *(undefined1 (*) [16])(param_1 + 0x60) = (undefined1  [16])0x0;
            *plVar10 = *plVar10 + -1;
            if (*plVar10 == 0) {
              (**(code **)(plVar10[1] + 0x30))(plVar10);
            }
            *plVar15 = *plVar15 + -1;
            if (*plVar15 == 0) {
              plVar12 = (longlong *)0x0;
              (**(code **)(plVar15[1] + 0x30))(plVar15);
              uVar18 = 0x52;
              goto LAB_23e2f5b00;
            }
          }
          else {
            plVar13 = (longlong *)FUN_23e8bc2f0(plVar2,DAT_23eeacd48);
            pcVar6 = PyLong_Type_exref;
            plStack_98 = plVar12;
            if (plVar13 == (longlong *)0x0) {
              plStack_b0 = *(longlong **)(param_1 + 0x60);
              plVar11 = *(longlong **)(param_1 + 0x70);
              *(undefined8 *)(param_1 + 0x70) = 0;
              plStack_a8 = *(longlong **)(param_1 + 0x68);
              *(undefined1 (*) [16])(param_1 + 0x60) = (undefined1  [16])0x0;
              *plVar10 = *plVar10 + -1;
              if (*plVar10 == 0) {
                (**(code **)(plVar10[1] + 0x30))(plVar10);
              }
              *plVar15 = *plVar15 + -1;
              if (*plVar15 == 0) {
                (**(code **)(plVar15[1] + 0x30))(plVar15);
              }
            }
            else {
              if ((code *)plVar13[1] != PyLong_Type_exref) {
                plStack_98 = (longlong *)FUN_23e8c6820();
                *plVar13 = *plVar13 + -1;
                if (*plVar13 == 0) {
                  (**(code **)(plVar13[1] + 0x30))();
                }
                if (plStack_98 != (longlong *)0x0) goto LAB_23e2f5595;
LAB_23e2f64fb:
                plStack_b0 = *(longlong **)(param_1 + 0x60);
                plVar11 = *(longlong **)(param_1 + 0x70);
                *(undefined8 *)(param_1 + 0x70) = 0;
                plStack_a8 = *(longlong **)(param_1 + 0x68);
                *(undefined1 (*) [16])(param_1 + 0x60) = (undefined1  [16])0x0;
                *plVar10 = *plVar10 + -1;
                if (*plVar10 == 0) {
                  (**(code **)(plVar10[1] + 0x30))(plVar10);
                }
                *plVar15 = *plVar15 + -1;
                plStack_98 = plVar12;
                if (*plVar15 == 0) {
                  (**(code **)(plVar15[1] + 0x30))(plVar15);
                }
LAB_23e2f6547:
                lVar8 = *plStack_98;
                *plStack_98 = lVar8 + -1;
                if (lVar8 + -1 == 0) {
                  plVar12 = (longlong *)0x0;
                  (**(code **)(plStack_98[1] + 0x30))();
                  uVar18 = 0x52;
                }
                else {
                  uVar18 = 0x52;
                  plVar12 = (longlong *)0x0;
                }
                goto LAB_23e2f5b00;
              }
              plStack_98 = (longlong *)
                           (**(code **)(*(longlong *)(PyLong_Type_exref + 0x60) + 0xf0))
                                     (plVar13,DAT_23eeacd60);
              lVar8 = *plVar13 + -1;
              *plVar13 = lVar8;
              if (plStack_98 == (longlong *)0x0) {
                if (lVar8 == 0) {
                  (**(code **)(plVar13[1] + 0x30))();
                }
                goto LAB_23e2f64fb;
              }
              if (lVar8 == 0) {
                (**(code **)(plVar13[1] + 0x30))();
              }
LAB_23e2f5595:
              plVar13 = (longlong *)FUN_23e8bc2f0(plVar2,DAT_23eeacd48);
              if (plVar13 != (longlong *)0x0) {
                if ((code *)plVar13[1] == pcVar6) {
                  plStack_b0 = (longlong *)
                               (**(code **)(*(longlong *)(pcVar6 + 0x60) + 0xf0))
                                         (plVar13,DAT_23eeacd60);
                  lVar8 = *plVar13 + -1;
                  *plVar13 = lVar8;
                  if (plStack_b0 == (longlong *)0x0) {
                    if (lVar8 == 0) {
                      (**(code **)(plVar13[1] + 0x30))();
                    }
                    goto LAB_23e2f6626;
                  }
                  if (lVar8 == 0) {
                    (**(code **)(plVar13[1] + 0x30))();
                  }
                }
                else {
                  plStack_b0 = (longlong *)FUN_23e8c6820();
                  *plVar13 = *plVar13 + -1;
                  if (*plVar13 == 0) {
                    (**(code **)(plVar13[1] + 0x30))();
                  }
                  if (plStack_b0 == (longlong *)0x0) {
LAB_23e2f6626:
                    plStack_b0 = *(longlong **)(param_1 + 0x60);
                    plVar11 = *(longlong **)(param_1 + 0x70);
                    *(undefined8 *)(param_1 + 0x70) = 0;
                    plStack_a8 = *(longlong **)(param_1 + 0x68);
                    *(undefined1 (*) [16])(param_1 + 0x60) = (undefined1  [16])0x0;
                    *plVar10 = *plVar10 + -1;
                    if (*plVar10 == 0) {
                      (**(code **)(plVar10[1] + 0x30))(plVar10);
                    }
                    *plVar15 = *plVar15 + -1;
                    if (*plVar15 == 0) {
                      (**(code **)(plVar15[1] + 0x30))(plVar15);
                    }
                    lVar8 = *plVar12;
                    *plVar12 = lVar8 + -1;
                    if (lVar8 + -1 == 0) {
                      (**(code **)(plVar12[1] + 0x30))();
                    }
                    goto LAB_23e2f6547;
                  }
                }
                *(undefined4 *)(plVar5 + 5) = 0x52;
                plStack_88 = plVar11;
                plStack_80 = plVar11;
                plStack_68 = plStack_98;
                plStack_60 = plStack_b0;
                plStack_78 = plVar15;
                plStack_70 = plVar12;
                plVar11 = (longlong *)FUN_23e96a010(param_1,plVar10,&plStack_88);
                *plVar10 = *plVar10 + -1;
                if (*plVar10 == 0) {
                  (**(code **)(plVar10[1] + 0x30))(plVar10);
                }
                *plVar15 = *plVar15 + -1;
                if (*plVar15 == 0) {
                  (**(code **)(plVar15[1] + 0x30))(plVar15);
                }
                lVar8 = *plVar12;
                *plVar12 = lVar8 + -1;
                if (lVar8 + -1 == 0) {
                  (**(code **)(plVar12[1] + 0x30))();
                }
                lVar8 = *plStack_98;
                *plStack_98 = lVar8 + -1;
                if (lVar8 + -1 == 0) {
                  (**(code **)(plStack_98[1] + 0x30))();
                }
                lVar8 = *plStack_b0;
                *plStack_b0 = lVar8 + -1;
                if (lVar8 + -1 == 0) {
                  (**(code **)(plStack_b0[1] + 0x30))();
                }
                if (plVar11 == (longlong *)0x0) goto LAB_23e2f6280;
                *plVar11 = *plVar11 + -1;
                if (*plVar11 == 0) {
                  (**(code **)(plVar11[1] + 0x30))(plVar11);
                }
                plVar10 = (longlong *)FUN_23e8bc2f0(plVar9,_DAT_23eeace90);
                if (plVar10 == (longlong *)0x0) {
LAB_23e2f65e7:
                  plStack_b0 = *(longlong **)(param_1 + 0x60);
                  plVar11 = *(longlong **)(param_1 + 0x70);
                  plVar12 = (longlong *)0x0;
                  *(undefined8 *)(param_1 + 0x70) = 0;
                  plStack_a8 = *(longlong **)(param_1 + 0x68);
                  *(undefined1 (*) [16])(param_1 + 0x60) = (undefined1  [16])0x0;
                  uVar18 = 0x55;
                  goto LAB_23e2f5b00;
                }
                lVar8 = FUN_23e8f5980();
                if (lVar8 == 0) {
                  FUN_23e915740(param_1,&plStack_88,_DAT_23eeace98);
                  uVar18 = 0x55;
                  uVar17 = 0x55;
                  *plVar10 = *plVar10 + -1;
                  lVar8 = *plVar10;
                  plVar12 = (longlong *)0x0;
                  plStack_b0 = plStack_88;
                  plStack_a8 = plStack_80;
                  plVar11 = plStack_78;
                }
                else {
                  *(undefined4 *)(plVar5 + 5) = 0x55;
                  plVar11 = (longlong *)FUN_23e957a30(param_1,lVar8,_DAT_23eeaced8);
                  if (plVar11 == (longlong *)0x0) {
                    plStack_b0 = *(longlong **)(param_1 + 0x60);
                    plVar11 = *(longlong **)(param_1 + 0x70);
                    *(undefined8 *)(param_1 + 0x70) = 0;
                    uVar18 = 0x55;
                    uVar17 = 0x55;
                    plStack_a8 = *(longlong **)(param_1 + 0x68);
                    *(undefined1 (*) [16])(param_1 + 0x60) = (undefined1  [16])0x0;
                    *plVar10 = *plVar10 + -1;
                    lVar8 = *plVar10;
                    goto joined_r0x00023e2f66c4;
                  }
                  *(undefined4 *)(plVar5 + 5) = 0x55;
                  plVar12 = (longlong *)FUN_23e914090(param_1,plVar10,plVar11);
                  *plVar10 = *plVar10 + -1;
                  if (*plVar10 == 0) {
                    (**(code **)(plVar10[1] + 0x30))(plVar10);
                  }
                  *plVar11 = *plVar11 + -1;
                  if (*plVar11 == 0) {
                    (**(code **)(plVar11[1] + 0x30))(plVar11);
                  }
                  if (plVar12 == (longlong *)0x0) goto LAB_23e2f65e7;
                  *plVar12 = *plVar12 + -1;
                  if (*plVar12 == 0) {
                    (**(code **)(plVar12[1] + 0x30))(plVar12);
                  }
                  plVar10 = (longlong *)FUN_23e8bc2f0(plVar2,DAT_23eeacd48);
                  if (plVar10 == (longlong *)0x0) {
                    plStack_b0 = *(longlong **)(param_1 + 0x60);
                    plVar11 = *(longlong **)(param_1 + 0x70);
                    *(undefined8 *)(param_1 + 0x70) = 0;
                    plStack_a8 = *(longlong **)(param_1 + 0x68);
                    *(undefined1 (*) [16])(param_1 + 0x60) = (undefined1  [16])0x0;
                    plVar12 = (longlong *)0x0;
                    uVar18 = 0x56;
                    goto LAB_23e2f5b00;
                  }
                  plVar11 = (longlong *)FUN_23e8bc2f0(plVar2,DAT_23eeacd58);
                  if (plVar11 == (longlong *)0x0) {
                    plStack_b0 = *(longlong **)(param_1 + 0x60);
                    plVar11 = *(longlong **)(param_1 + 0x70);
                    *(undefined8 *)(param_1 + 0x70) = 0;
                    plStack_a8 = *(longlong **)(param_1 + 0x68);
                    *(undefined1 (*) [16])(param_1 + 0x60) = (undefined1  [16])0x0;
                    *plVar10 = *plVar10 + -1;
                    if (*plVar10 == 0) {
                      plVar12 = (longlong *)0x0;
                      FUN_23a334bc0(plVar10);
                      uVar18 = 0x56;
                    }
                    else {
                      plVar12 = (longlong *)0x0;
                      uVar18 = 0x56;
                    }
                    goto LAB_23e2f5b00;
                  }
                  plVar15 = (longlong *)FUN_23e8c6640(plVar10,plVar11);
                  *plVar10 = *plVar10 + -1;
                  if (*plVar10 == 0) {
                    (**(code **)(plVar10[1] + 0x30))(plVar10);
                  }
                  *plVar11 = *plVar11 + -1;
                  if (*plVar11 == 0) {
                    (**(code **)(plVar11[1] + 0x30))(plVar11);
                  }
                  if (plVar15 == (longlong *)0x0) {
                    plStack_b0 = *(longlong **)(param_1 + 0x60);
                    plVar11 = *(longlong **)(param_1 + 0x70);
                    plVar12 = (longlong *)0x0;
                    *(undefined8 *)(param_1 + 0x70) = 0;
                    plStack_a8 = *(longlong **)(param_1 + 0x68);
                    *(undefined1 (*) [16])(param_1 + 0x60) = (undefined1  [16])0x0;
                    uVar18 = 0x56;
                    goto LAB_23e2f5b00;
                  }
                  if ((code *)plVar15[1] == pcVar6) {
                    plVar12 = (longlong *)
                              (**(code **)(*(longlong *)(pcVar6 + 0x60) + 0xe8))
                                        (plVar15,DAT_23eeacd60);
                    lVar8 = *plVar15 + -1;
                    *plVar15 = lVar8;
                    if (plVar12 == (longlong *)0x0) {
                      if (lVar8 == 0) {
                        (**(code **)(plVar15[1] + 0x30))(plVar15);
                      }
                      goto LAB_23e2f6888;
                    }
                    if (lVar8 == 0) {
                      (**(code **)(plVar15[1] + 0x30))(plVar15);
                    }
                  }
                  else {
                    plVar12 = (longlong *)FUN_23e8c1be0(plVar15);
                    *plVar15 = *plVar15 + -1;
                    if (*plVar15 == 0) {
                      (**(code **)(plVar15[1] + 0x30))(plVar15);
                    }
                    if (plVar12 == (longlong *)0x0) {
LAB_23e2f6888:
                      plStack_b0 = *(longlong **)(param_1 + 0x60);
                      plVar11 = *(longlong **)(param_1 + 0x70);
                      plVar12 = (longlong *)0x0;
                      *(undefined8 *)(param_1 + 0x70) = 0;
                      plStack_a8 = *(longlong **)(param_1 + 0x68);
                      *(undefined1 (*) [16])(param_1 + 0x60) = (undefined1  [16])0x0;
                      uVar18 = 0x56;
                      goto LAB_23e2f5b00;
                    }
                  }
                  plVar10 = (longlong *)FUN_23e8bc2f0(plVar9,_DAT_23eeacee0);
                  if (plVar10 == (longlong *)0x0) {
LAB_23e2f6849:
                    plStack_b0 = *(longlong **)(param_1 + 0x60);
                    plVar11 = *(longlong **)(param_1 + 0x70);
                    *(undefined8 *)(param_1 + 0x70) = 0;
                    plStack_a8 = *(longlong **)(param_1 + 0x68);
                    *(undefined1 (*) [16])(param_1 + 0x60) = (undefined1  [16])0x0;
                    uVar18 = 0x57;
                    goto LAB_23e2f5b00;
                  }
                  plVar11 = (longlong *)FUN_23e8bc2f0(plVar2,DAT_23eeacdc0);
                  if (plVar11 != (longlong *)0x0) {
                    plVar15 = (longlong *)PyNumber_Long(plVar11);
                    *plVar11 = *plVar11 + -1;
                    if (*plVar11 == 0) {
                      (**(code **)(plVar11[1] + 0x30))(plVar11);
                    }
                    if (plVar15 != (longlong *)0x0) {
                      plVar13 = (longlong *)FUN_23e8bc2f0(plVar2);
                      if (plVar13 == (longlong *)0x0) {
                        plStack_b0 = *(longlong **)(param_1 + 0x60);
                        plVar11 = *(longlong **)(param_1 + 0x70);
                        *(undefined8 *)(param_1 + 0x70) = 0;
                        plStack_a8 = *(longlong **)(param_1 + 0x68);
                        *(undefined1 (*) [16])(param_1 + 0x60) = (undefined1  [16])0x0;
                        *plVar10 = *plVar10 + -1;
                        if (*plVar10 == 0) {
                          FUN_23a334bc0(plVar10);
                        }
                        *plVar15 = *plVar15 + -1;
                        uVar18 = 0x57;
                        if (*plVar15 == 0) {
                          FUN_23a334bc0(plVar15);
                          uVar18 = 0x57;
                        }
                        goto LAB_23e2f5b00;
                      }
                      plVar11 = (longlong *)FUN_23e8bc2f0(plVar2,DAT_23eeacd58);
                      if (plVar11 == (longlong *)0x0) {
                        plStack_b0 = *(longlong **)(param_1 + 0x60);
                        plVar11 = *(longlong **)(param_1 + 0x70);
                        plStack_a8 = *(longlong **)(param_1 + 0x68);
                        *(undefined1 (*) [16])(param_1 + 0x60) = (undefined1  [16])0x0;
                        *(undefined8 *)(param_1 + 0x70) = 0;
                        *plVar10 = *plVar10 + -1;
                        if (*plVar10 == 0) {
                          FUN_23a334bc0(plVar10);
                        }
                        *plVar15 = *plVar15 + -1;
                        if (*plVar15 == 0) {
                          FUN_23a334bc0(plVar15);
                        }
                        *plVar13 = *plVar13 + -1;
                        uVar18 = 0x57;
                        if (*plVar13 == 0) {
                          FUN_23a334bc0(plVar13);
                          uVar18 = 0x57;
                        }
                        goto LAB_23e2f5b00;
                      }
                      *(undefined4 *)(plVar5 + 5) = 0x57;
                      plStack_88 = plVar15;
                      plStack_80 = plVar12;
                      plStack_78 = plVar13;
                      plStack_70 = plVar11;
                      plVar14 = (longlong *)FUN_23e9583d0(param_1,plVar10,&plStack_88);
                      *plVar10 = *plVar10 + -1;
                      if (*plVar10 == 0) {
                        (**(code **)(plVar10[1] + 0x30))(plVar10);
                      }
                      *plVar15 = *plVar15 + -1;
                      if (*plVar15 == 0) {
                        (**(code **)(plVar15[1] + 0x30))(plVar15);
                      }
                      *plVar13 = *plVar13 + -1;
                      if (*plVar13 == 0) {
                        (**(code **)(plVar13[1] + 0x30))(plVar13);
                      }
                      *plVar11 = *plVar11 + -1;
                      if (*plVar11 == 0) {
                        (**(code **)(plVar11[1] + 0x30))(plVar11);
                      }
                      if (plVar14 != (longlong *)0x0) {
                        *plVar14 = *plVar14 + -1;
                        if (*plVar14 == 0) {
                          (**(code **)(plVar14[1] + 0x30))(plVar14);
                        }
                        lVar8 = *(longlong *)(*(longlong *)(param_1 + 0x38) + 8);
                        plVar11 = *(longlong **)(lVar8 + 0x28);
                        plVar5 = (longlong *)plVar11[2];
                        *(undefined8 *)(*(longlong *)(param_1 + 0x38) + 8) =
                             *(undefined8 *)(lVar8 + 0x30);
                        *(undefined4 *)(plVar11 + 8) = 0xffffffff;
                        if (plVar5 != (longlong *)0x0) {
                          plVar11[2] = 0;
                          *plVar5 = *plVar5 + -1;
                          if (*plVar5 == 0) {
                            (**(code **)(plVar5[1] + 0x30))();
                          }
                        }
                        *plVar11 = *plVar11 + -1;
                        if (*plVar11 == 0) {
                          (**(code **)(plVar11[1] + 0x30))(plVar11);
                        }
                        plVar11[0xf] = 0;
                        pcVar6 = _Py_NoneStruct_exref;
                        *(longlong *)_Py_NoneStruct_exref = *(longlong *)_Py_NoneStruct_exref + 1;
                        *plVar9 = *plVar9 + -1;
                        if (*plVar9 == 0) {
                          (**(code **)(plVar9[1] + 0x30))(plVar9);
                        }
                        *plVar12 = *plVar12 + -1;
                        if (*plVar12 == 0) {
                          (**(code **)(plVar12[1] + 0x30))(plVar12);
                        }
                        *plVar2 = *plVar2 + -1;
                        if (*plVar2 == 0) {
                          (**(code **)(plVar2[1] + 0x30))(plVar2);
                        }
                        *plVar3 = *plVar3 + -1;
                        if (*plVar3 != 0) {
                          return pcVar6;
                        }
                        (**(code **)(plVar3[1] + 0x30))(plVar3);
                        return pcVar6;
                      }
                      goto LAB_23e2f6849;
                    }
                  }
                  plStack_b0 = *(longlong **)(param_1 + 0x60);
                  plVar11 = *(longlong **)(param_1 + 0x70);
                  *(undefined8 *)(param_1 + 0x70) = 0;
                  uVar18 = 0x57;
                  uVar17 = 0x57;
                  plStack_a8 = *(longlong **)(param_1 + 0x68);
                  *(undefined1 (*) [16])(param_1 + 0x60) = (undefined1  [16])0x0;
                  *plVar10 = *plVar10 + -1;
                  lVar8 = *plVar10;
                }
                if (lVar8 == 0) {
                  FUN_23a334bc0(plVar10);
                  uVar18 = uVar17;
                }
                goto LAB_23e2f5b00;
              }
              plStack_b0 = *(longlong **)(param_1 + 0x60);
              plVar11 = *(longlong **)(param_1 + 0x70);
              *(undefined8 *)(param_1 + 0x70) = 0;
              plStack_a8 = *(longlong **)(param_1 + 0x68);
              *(undefined1 (*) [16])(param_1 + 0x60) = (undefined1  [16])0x0;
              *plVar10 = *plVar10 + -1;
              if (*plVar10 == 0) {
                (**(code **)(plVar10[1] + 0x30))(plVar10);
              }
              *plVar15 = *plVar15 + -1;
              if (*plVar15 == 0) {
                (**(code **)(plVar15[1] + 0x30))(plVar15);
              }
              lVar8 = *plVar12;
              *plVar12 = lVar8 + -1;
              if (lVar8 + -1 == 0) {
                (**(code **)(plVar12[1] + 0x30))();
              }
            }
            lVar8 = *plStack_98;
            *plStack_98 = lVar8 + -1;
            if (lVar8 + -1 == 0) {
              plVar12 = (longlong *)0x0;
              (**(code **)(plStack_98[1] + 0x30))();
              uVar18 = 0x52;
              goto LAB_23e2f5b00;
            }
          }
          plVar12 = (longlong *)0x0;
          uVar18 = 0x52;
          goto LAB_23e2f5b00;
        }
        plStack_b0 = *(longlong **)(param_1 + 0x60);
        plVar11 = *(longlong **)(param_1 + 0x70);
        *(undefined8 *)(param_1 + 0x70) = 0;
        plStack_a8 = *(longlong **)(param_1 + 0x68);
        *(undefined1 (*) [16])(param_1 + 0x60) = (undefined1  [16])0x0;
      }
      *plVar10 = *plVar10 + -1;
      lVar8 = *plVar10;
      uVar18 = 0x4f;
      uVar17 = 0x4f;
    }
    else {
      plVar10 = (longlong *)FUN_23e8bc2f0(plVar9,_DAT_23eeace90);
      if (plVar10 == (longlong *)0x0) {
LAB_23e2f52b5:
        plStack_b0 = *(longlong **)(param_1 + 0x60);
        plVar11 = *(longlong **)(param_1 + 0x70);
        plVar12 = (longlong *)0x0;
        *(undefined8 *)(param_1 + 0x70) = 0;
        plStack_a8 = *(longlong **)(param_1 + 0x68);
        *(undefined1 (*) [16])(param_1 + 0x60) = (undefined1  [16])0x0;
        uVar18 = 0x4c;
        goto LAB_23e2f5b00;
      }
      lVar8 = FUN_23e8f5980();
      if (lVar8 == 0) {
        FUN_23e915740(param_1,&plStack_88,_DAT_23eeace98);
        plStack_b0 = plStack_88;
        plStack_a8 = plStack_80;
        plVar11 = plStack_78;
      }
      else {
        *(undefined4 *)(plVar5 + 5) = 0x4c;
        plVar11 = (longlong *)FUN_23e94bb80(param_1,lVar8,_DAT_23eeacea0);
        if (plVar11 != (longlong *)0x0) {
          *(undefined4 *)(plVar5 + 5) = 0x4c;
          plVar12 = (longlong *)FUN_23e914090(param_1,plVar10,plVar11);
          *plVar10 = *plVar10 + -1;
          if (*plVar10 == 0) {
            (**(code **)(plVar10[1] + 0x30))(plVar10);
          }
          *plVar11 = *plVar11 + -1;
          if (*plVar11 == 0) {
            (**(code **)(plVar11[1] + 0x30))(plVar11);
          }
          if (plVar12 != (longlong *)0x0) goto LAB_23e2f53b3;
          goto LAB_23e2f52b5;
        }
        plStack_b0 = *(longlong **)(param_1 + 0x60);
        plVar11 = *(longlong **)(param_1 + 0x70);
        *(undefined8 *)(param_1 + 0x70) = 0;
        plStack_a8 = *(longlong **)(param_1 + 0x68);
        *(undefined1 (*) [16])(param_1 + 0x60) = (undefined1  [16])0x0;
      }
      *plVar10 = *plVar10 + -1;
      lVar8 = *plVar10;
      uVar18 = 0x4c;
      uVar17 = 0x4c;
    }
  }
joined_r0x00023e2f66c4:
  plVar12 = (longlong *)0x0;
  if (lVar8 == 0) {
    plVar12 = (longlong *)0x0;
    (**(code **)(plVar10[1] + 0x30))(plVar10);
    uVar18 = uVar17;
  }
LAB_23e2f5b00:
  plVar10 = DAT_23ed6a4f8;
  if (plVar11 == (longlong *)0x0) {
    if (DAT_23ed6a4f8 == (longlong *)0x0) {
      plVar15 = (longlong *)FUN_23a33a530(PyTraceBack_Type_exref);
    }
    else {
      plVar11 = (longlong *)*DAT_23ed6a4f8;
      *DAT_23ed6a4f8 = 1;
      DAT_23ed6a4f8 = plVar11;
      DAT_23ed6a4f0 = DAT_23ed6a4f0 + -1;
      plVar15 = plVar10;
    }
    pcVar6 = _PyRuntime_exref;
    plVar15[2] = 0;
    plVar15[3] = (longlong)plVar5;
    *plVar5 = *plVar5 + 1;
    lVar8 = *(longlong *)(pcVar6 + 0x1f8);
    *(undefined4 *)((longlong)plVar15 + 0x24) = uVar18;
    lVar8 = *(longlong *)(lVar8 + 0x10);
    *(undefined4 *)(plVar15 + 4) = 0xffffffff;
    lVar8 = *(longlong *)(lVar8 + 0x2e8);
    lVar16 = plVar15[-1];
    puVar4 = *(undefined8 **)(lVar8 + 8);
    *puVar4 = plVar15 + -2;
    plVar15[-2] = lVar8;
    plVar15[-1] = (ulonglong)((uint)lVar16 & 3) | (ulonglong)puVar4;
    *(longlong **)(lVar8 + 8) = plVar15 + -2;
  }
  else {
    plVar15 = plVar11;
    if ((longlong *)plVar11[3] != plVar5) {
      if (DAT_23ed6a4f8 == (longlong *)0x0) {
        plVar15 = (longlong *)FUN_23a33a530(PyTraceBack_Type_exref);
      }
      else {
        plVar15 = (longlong *)*DAT_23ed6a4f8;
        *DAT_23ed6a4f8 = 1;
        DAT_23ed6a4f8 = plVar15;
        DAT_23ed6a4f0 = DAT_23ed6a4f0 + -1;
        plVar15 = plVar10;
      }
      pcVar6 = _PyRuntime_exref;
      plVar15[3] = (longlong)plVar5;
      *plVar5 = *plVar5 + 1;
      lVar8 = *(longlong *)(pcVar6 + 0x1f8);
      *(undefined4 *)((longlong)plVar15 + 0x24) = uVar18;
      *(undefined4 *)(plVar15 + 4) = 0xffffffff;
      lVar8 = *(longlong *)(*(longlong *)(lVar8 + 0x10) + 0x2e8);
      lVar16 = plVar15[-1];
      puVar4 = *(undefined8 **)(lVar8 + 8);
      *puVar4 = plVar15 + -2;
      plVar15[-2] = lVar8;
      plVar15[-1] = (ulonglong)((uint)lVar16 & 3) | (ulonglong)puVar4;
      lVar16 = *plVar11;
      *(longlong **)(lVar8 + 8) = plVar15 + -2;
      plVar15[2] = (longlong)plVar11;
      if (lVar16 == 0) {
        (**(code **)(plVar11[1] + 0x30))(plVar11);
      }
    }
  }
  FUN_23e8bba40(plVar5,&DAT_23ec5b359,plVar2,plVar3,plVar9,plVar12);
  if (_DAT_23eeb0018 == plVar5) {
    *plVar5 = *plVar5 + -1;
    if (*plVar5 == 0) {
      (**(code **)(plVar5[1] + 0x30))(plVar5);
    }
    _DAT_23eeb0018 = (longlong *)0x0;
  }
  lVar8 = *(longlong *)(*(longlong *)(param_1 + 0x38) + 8);
  plVar11 = *(longlong **)(lVar8 + 0x28);
  plVar5 = (longlong *)plVar11[2];
  *(undefined8 *)(*(longlong *)(param_1 + 0x38) + 8) = *(undefined8 *)(lVar8 + 0x30);
  *(undefined4 *)(plVar11 + 8) = 0xffffffff;
  if (plVar5 != (longlong *)0x0) {
    plVar11[2] = 0;
    *plVar5 = *plVar5 + -1;
    if (*plVar5 == 0) {
      (**(code **)(plVar5[1] + 0x30))();
    }
  }
  *plVar11 = *plVar11 + -1;
  if (*plVar11 == 0) {
    (**(code **)(plVar11[1] + 0x30))(plVar11);
  }
  plVar11[0xf] = 0;
  if ((plVar9 != (longlong *)0x0) && (*plVar9 = *plVar9 + -1, *plVar9 == 0)) {
    (**(code **)(plVar9[1] + 0x30))(plVar9);
  }
  if ((plVar12 != (longlong *)0x0) && (*plVar12 = *plVar12 + -1, *plVar12 == 0)) {
    (**(code **)(plVar12[1] + 0x30))(plVar12);
  }
  *plVar2 = *plVar2 + -1;
  if (*plVar2 == 0) {
    (**(code **)(plVar2[1] + 0x30))(plVar2);
  }
  *plVar3 = *plVar3 + -1;
  if (*plVar3 == 0) {
    (**(code **)(plVar3[1] + 0x30))(plVar3);
  }
  FUN_23a33aa70(param_1,plStack_b0,plStack_a8,plVar15);
  return (code *)0x0;
}
