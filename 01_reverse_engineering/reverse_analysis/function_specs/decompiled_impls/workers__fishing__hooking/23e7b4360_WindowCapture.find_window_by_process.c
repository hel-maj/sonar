/* ===== 23e7b4360 workers.fishing.hooking:194 ===== */
/* ghidra_name=FUN_23e7b4360 entry=23e7b4360 size=8547 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

longlong * FUN_23e7b4360(longlong param_1,undefined8 param_2,undefined8 *param_3)

{
  longlong *plVar1;
  longlong *plVar2;
  longlong lVar3;
  undefined8 *puVar4;
  longlong *plVar5;
  longlong *plVar6;
  char cVar7;
  int iVar8;
  int iVar9;
  longlong *plVar10;
  longlong lVar11;
  longlong *plVar12;
  longlong *plVar13;
  longlong *plVar14;
  longlong *plVar15;
  longlong *plVar16;
  longlong *plVar17;
  code *pcVar18;
  longlong lVar19;
  longlong lVar20;
  longlong lVar21;
  bool bVar22;
  undefined8 uVar23;
  undefined8 uVar24;
  longlong *plStack_c8;
  longlong *plStack_c0;
  longlong *plStack_b8;
  undefined4 uStack_a8;
  undefined1 auStack_98 [16];
  longlong *plStack_88;
  longlong *plStack_78;
  longlong *plStack_70;
  longlong *plStack_68;
  
  plVar10 = _DAT_23eedaac0;
  plVar1 = (longlong *)param_3[1];
  plVar2 = (longlong *)*param_3;
  plStack_88 = (longlong *)0x0;
  auStack_98._0_8_ = 0;
  auStack_98._8_8_ = 0;
  if (_DAT_23eedaac0 == (longlong *)0x0) {
LAB_23e7b43c6:
    _DAT_23eedaac0 = (longlong *)FUN_23e91f3b0(param_1,_DAT_23eedaab8,DAT_23eedab78,0x54);
  }
  else {
    lVar11 = *_DAT_23eedaac0;
    if (1 < lVar11) {
      *_DAT_23eedaac0 = lVar11 + -1;
      goto LAB_23e7b43c6;
    }
    if (_DAT_23eedaac0[2] != 0) {
      *_DAT_23eedaac0 = lVar11 + -1;
      if (lVar11 + -1 == 0) {
        (**(code **)(plVar10[1] + 0x30))(plVar10);
      }
      goto LAB_23e7b43c6;
    }
  }
  plVar5 = _DAT_23eedaac0;
  lVar11 = *(longlong *)(param_1 + 0x38);
  plVar10 = _DAT_23eedaac0 + 9;
  lVar3 = *(longlong *)(lVar11 + 8);
  _DAT_23eedaac0[0xf] = lVar3;
  *(longlong **)(lVar11 + 8) = plVar10;
  if ((lVar3 != 0) &&
     (((*(char *)(lVar3 + 0x45) == '\x01' ||
       ((ulonglong)
        (*(longlong *)(lVar3 + 0x20) + 0xb8 +
        (longlong)*(int *)(*(longlong *)(lVar3 + 0x20) + 0xa8) * 2) <= *(ulonglong *)(lVar3 + 0x38))
       ) && (plVar5[0xe] != 0)))) {
    plVar10 = *(longlong **)(lVar3 + 0x28);
    *(longlong **)(plVar5[0xe] + 0x10) = plVar10;
    if (plVar10 != (longlong *)0x0) {
      *plVar10 = *plVar10 + 1;
    }
  }
  *plVar5 = *plVar5 + 1;
  uVar23 = _DAT_23eed7b30;
  *(undefined4 *)(plVar5 + 8) = 0;
  plVar10 = (longlong *)FUN_23e8bc2f0(plVar2,uVar23);
  if (plVar10 == (longlong *)0x0) {
    auStack_98._0_8_ = *(undefined8 *)(param_1 + 0x60);
    auStack_98._8_8_ = *(undefined8 *)(param_1 + 0x68);
    plStack_88 = *(longlong **)(param_1 + 0x70);
    plVar15 = (longlong *)0x0;
    plVar14 = (longlong *)0x0;
    *(undefined8 *)(param_1 + 0x70) = 0;
    plVar12 = (longlong *)0x0;
    plVar13 = (longlong *)0x0;
    uStack_a8 = 0xc9;
    iVar8 = 2;
    plStack_b8 = (longlong *)0x0;
    plStack_c0 = (longlong *)0x0;
    plStack_c8 = (longlong *)0x0;
    *(undefined1 (*) [16])(param_1 + 0x60) = (undefined1  [16])0x0;
    plVar10 = (longlong *)0x0;
    goto LAB_23e7b4f5e;
  }
  plStack_78 = plVar10;
  if ((code *)plVar10[1] == PyLong_Type_exref) {
    lVar11 = plVar10[2];
    lVar3 = *plVar10;
    lVar21 = *(longlong *)(DAT_23ed6ccf8 + 0x10);
    if (lVar11 < 0) {
      lVar19 = -lVar11;
      lVar20 = lVar21;
      if (lVar11 == -1 || lVar19 < 1) {
        if (lVar21 < 0) {
          lVar20 = -lVar21;
          if (lVar21 == -1 || lVar20 < 1) {
            iVar8 = -(int)plVar10[3];
            goto LAB_23e7b5cda;
          }
          if (lVar3 != 1) goto LAB_23e7b5780;
LAB_23e7b5751:
          plVar12 = (longlong *)FUN_23e8be680(plVar10,DAT_23ed6ccf8 + 0x18,lVar20);
          lVar11 = -plVar12[2];
          if (-1 < lVar11) {
            lVar11 = plVar12[2];
          }
          plVar12[2] = lVar11;
          goto LAB_23e7b44a5;
        }
        if (lVar21 < 2) {
          iVar8 = -(int)plVar10[3];
          goto LAB_23e7b57aa;
        }
        if (lVar3 != 1) goto LAB_23e7b54f5;
      }
      else {
        lVar20 = -lVar21;
        if (-lVar21 < 0) {
          lVar20 = lVar21;
        }
        if (lVar3 != 1) {
          if (lVar21 < 0) {
LAB_23e7b5780:
            plVar12 = (longlong *)FUN_23e8be550(plVar10 + 3,lVar19,DAT_23ed6ccf8 + 0x18,lVar20);
            plVar12[2] = -plVar12[2];
          }
          else {
LAB_23e7b54f5:
            plVar12 = (longlong *)FUN_23e8be900(DAT_23ed6ccf8 + 0x18,lVar20,plVar10 + 3,lVar19);
          }
          goto LAB_23e7b4e76;
        }
        if (lVar21 < 0) goto LAB_23e7b5751;
      }
      plVar12 = (longlong *)FUN_23e8beb80(plVar10,DAT_23ed6ccf8 + 0x18,lVar20,0xffffffff);
    }
    else {
      if (lVar11 < 2) {
        if (lVar21 < 0) {
          lVar20 = -lVar21;
          if (lVar21 != -1 && 0 < lVar20) {
            if (lVar3 == 1) goto LAB_23e7b5e6f;
            goto LAB_23e7b5582;
          }
          iVar8 = 0;
          if (lVar11 != 0) {
            iVar8 = (int)plVar10[3];
          }
LAB_23e7b5cda:
          iVar8 = iVar8 - *(int *)(DAT_23ed6ccf8 + 0x18);
        }
        else {
          if (1 < lVar21) {
            if (lVar3 == 1) goto LAB_23e7b5b65;
            goto LAB_23e7b4e63;
          }
          iVar8 = 0;
          if (lVar11 != 0) {
            iVar8 = (int)plVar10[3];
          }
LAB_23e7b57aa:
          if (lVar21 != 0) {
            iVar8 = iVar8 + *(int *)(DAT_23ed6ccf8 + 0x18);
          }
        }
        if (lVar3 == 1) {
          FUN_23e8be320(&plStack_78,iVar8);
          plVar12 = plStack_78;
          goto LAB_23e7b44a5;
        }
        plVar12 = (longlong *)FUN_23e8bb5f0();
      }
      else {
        lVar20 = -lVar21;
        if (-lVar21 < 0) {
          lVar20 = lVar21;
        }
        if (lVar3 == 1) {
          bVar22 = lVar21 < 0;
          lVar21 = lVar20;
          if (bVar22) {
LAB_23e7b5e6f:
            plVar12 = (longlong *)FUN_23e8beb80(plVar10,DAT_23ed6ccf8 + 0x18,lVar20,1);
          }
          else {
LAB_23e7b5b65:
            plVar12 = (longlong *)FUN_23e8be680(plVar10,DAT_23ed6ccf8 + 0x18,lVar21);
          }
          goto LAB_23e7b44a5;
        }
        bVar22 = lVar21 < 0;
        lVar21 = lVar20;
        if (bVar22) {
LAB_23e7b5582:
          plVar12 = (longlong *)FUN_23e8be900(plVar10 + 3,lVar11,DAT_23ed6ccf8 + 0x18,lVar20);
          goto LAB_23e7b4e76;
        }
LAB_23e7b4e63:
        plVar12 = (longlong *)FUN_23e8be550(plVar10 + 3,lVar11,DAT_23ed6ccf8 + 0x18,lVar21);
        if (plVar12 == (longlong *)0x0) goto LAB_23e7b4ec0;
      }
LAB_23e7b4e76:
      *plVar10 = *plVar10 + -1;
      if (*plVar10 == 0) {
        (**(code **)(plVar10[1] + 0x30))(plVar10);
      }
    }
LAB_23e7b44a5:
    cVar7 = FUN_23e8d9ac0(plVar2,_DAT_23eed7b30,plVar12);
    if (cVar7 != '\0') {
      *plVar12 = *plVar12 + -1;
      if (*plVar12 == 0) {
        (**(code **)(plVar12[1] + 0x30))(plVar12);
      }
      lVar11 = FUN_23e8dedb0();
      if (lVar11 == 0) {
        FUN_23e915740(param_1,auStack_98,_DAT_23eed7b38);
        plVar10 = (longlong *)0x0;
      }
      else {
        *(undefined4 *)(plVar5 + 5) = 0xca;
        plVar10 = (longlong *)FUN_23e91bfe0(param_1,lVar11);
        if (plVar10 != (longlong *)0x0) {
          plVar12 = (longlong *)FUN_23e8bc2f0(plVar2,_DAT_23eed7b40);
          if (plVar12 == (longlong *)0x0) {
            auStack_98._0_8_ = *(undefined8 *)(param_1 + 0x60);
            plStack_88 = *(longlong **)(param_1 + 0x70);
            plVar15 = (longlong *)0x0;
            plVar14 = (longlong *)0x0;
            *(undefined8 *)(param_1 + 0x70) = 0;
            plVar13 = (longlong *)0x0;
            uStack_a8 = 0xcb;
            iVar8 = 2;
            plStack_b8 = (longlong *)0x0;
            plStack_c0 = (longlong *)0x0;
            plStack_c8 = (longlong *)0x0;
            *(undefined1 (*) [16])(param_1 + 0x60) = (undefined1  [16])0x0;
            plVar12 = (longlong *)0x0;
            auStack_98._8_8_ = *(undefined8 *)(param_1 + 0x68);
            goto LAB_23e7b4f5e;
          }
          plVar13 = (longlong *)FUN_23e8c6640(plVar10,plVar12);
          *plVar12 = *plVar12 + -1;
          if (*plVar12 == 0) {
            (**(code **)(plVar12[1] + 0x30))(plVar12);
          }
          if (plVar13 == (longlong *)0x0) {
            auStack_98._0_8_ = *(undefined8 *)(param_1 + 0x60);
            plStack_88 = *(longlong **)(param_1 + 0x70);
            plVar15 = (longlong *)0x0;
            plVar14 = (longlong *)0x0;
            *(undefined8 *)(param_1 + 0x70) = 0;
            plVar12 = (longlong *)0x0;
            uStack_a8 = 0xcb;
            iVar8 = 2;
            plStack_b8 = (longlong *)0x0;
            plStack_c0 = (longlong *)0x0;
            plStack_c8 = (longlong *)0x0;
            *(undefined1 (*) [16])(param_1 + 0x60) = (undefined1  [16])0x0;
            auStack_98._8_8_ = *(undefined8 *)(param_1 + 0x68);
            goto LAB_23e7b4f5e;
          }
          iVar8 = FUN_23e97d950(plVar13,DAT_23ed6cd18);
          if (iVar8 == -1) {
            auStack_98._0_8_ = *(undefined8 *)(param_1 + 0x60);
            auStack_98._8_8_ = *(undefined8 *)(param_1 + 0x68);
            plStack_88 = *(longlong **)(param_1 + 0x70);
            uStack_a8 = 0xcc;
            *(undefined8 *)(param_1 + 0x70) = 0;
            *(undefined1 (*) [16])(param_1 + 0x60) = (undefined1  [16])0x0;
          }
          else if (iVar8 == 1) {
            plVar12 = (longlong *)FUN_23e8bc2f0(plVar2,_DAT_23eed7b30);
            if (plVar12 == (longlong *)0x0) {
              auStack_98._0_8_ = *(undefined8 *)(param_1 + 0x60);
              plStack_88 = *(longlong **)(param_1 + 0x70);
              plVar15 = (longlong *)0x0;
              plVar14 = (longlong *)0x0;
              *(undefined8 *)(param_1 + 0x70) = 0;
              uStack_a8 = 0xcd;
              iVar8 = 2;
              plStack_b8 = (longlong *)0x0;
              plStack_c0 = (longlong *)0x0;
              plStack_c8 = (longlong *)0x0;
              *(undefined1 (*) [16])(param_1 + 0x60) = (undefined1  [16])0x0;
              plVar12 = (longlong *)0x0;
              auStack_98._8_8_ = *(undefined8 *)(param_1 + 0x68);
              goto LAB_23e7b4f5e;
            }
            plVar14 = (longlong *)FUN_23e8c6f80(plVar12,plVar13);
            *plVar12 = *plVar12 + -1;
            if (*plVar12 == 0) {
              (**(code **)(plVar12[1] + 0x30))(plVar12);
            }
            if (plVar14 == (longlong *)0x0) {
              auStack_98._0_8_ = *(undefined8 *)(param_1 + 0x60);
              plStack_88 = *(longlong **)(param_1 + 0x70);
              plVar15 = (longlong *)0x0;
              plVar12 = (longlong *)0x0;
              *(undefined8 *)(param_1 + 0x70) = 0;
              uStack_a8 = 0xcd;
              iVar8 = 2;
              plStack_b8 = (longlong *)0x0;
              plStack_c0 = (longlong *)0x0;
              plStack_c8 = (longlong *)0x0;
              *(undefined1 (*) [16])(param_1 + 0x60) = (undefined1  [16])0x0;
              plVar14 = (longlong *)0x0;
              auStack_98._8_8_ = *(undefined8 *)(param_1 + 0x68);
              goto LAB_23e7b4f5e;
            }
            cVar7 = FUN_23e8d9ac0(plVar2,_DAT_23eed7b48,plVar14);
            *plVar14 = *plVar14 + -1;
            if (*plVar14 == 0) {
              (**(code **)(plVar14[1] + 0x30))(plVar14);
            }
            if (cVar7 == '\0') {
              auStack_98._0_8_ = *(undefined8 *)(param_1 + 0x60);
              auStack_98._8_8_ = *(undefined8 *)(param_1 + 0x68);
              plStack_88 = *(longlong **)(param_1 + 0x70);
              uStack_a8 = 0xcd;
              *(undefined8 *)(param_1 + 0x70) = 0;
              *(undefined1 (*) [16])(param_1 + 0x60) = (undefined1  [16])0x0;
            }
            else {
              cVar7 = FUN_23e8d9ac0(plVar2,_DAT_23eed7b30,DAT_23ed6ccf0);
              if (cVar7 == '\0') {
                auStack_98._0_8_ = *(undefined8 *)(param_1 + 0x60);
                auStack_98._8_8_ = *(undefined8 *)(param_1 + 0x68);
                plStack_88 = *(longlong **)(param_1 + 0x70);
                uStack_a8 = 0xce;
                *(undefined8 *)(param_1 + 0x70) = 0;
                *(undefined1 (*) [16])(param_1 + 0x60) = (undefined1  [16])0x0;
              }
              else {
                cVar7 = FUN_23e8d9ac0(plVar2,_DAT_23eed7b40,plVar10);
                if (cVar7 != '\0') goto LAB_23e7b4568;
                plStack_88 = *(longlong **)(param_1 + 0x70);
                auStack_98._0_8_ = *(undefined8 *)(param_1 + 0x60);
                auStack_98._8_8_ = *(undefined8 *)(param_1 + 0x68);
                uStack_a8 = 0xcf;
                *(undefined8 *)(param_1 + 0x70) = 0;
                *(undefined1 (*) [16])(param_1 + 0x60) = (undefined1  [16])0x0;
              }
            }
          }
          else {
LAB_23e7b4568:
            plVar12 = (longlong *)FUN_23e8bc2f0(plVar2,_DAT_23eed7af8);
            if (plVar12 == (longlong *)0x0) {
              auStack_98._0_8_ = *(undefined8 *)(param_1 + 0x60);
              plStack_88 = *(longlong **)(param_1 + 0x70);
              plVar15 = (longlong *)0x0;
              plVar14 = (longlong *)0x0;
              *(undefined8 *)(param_1 + 0x70) = 0;
              uStack_a8 = 0xd2;
              iVar8 = 2;
              plStack_b8 = (longlong *)0x0;
              plStack_c0 = (longlong *)0x0;
              plStack_c8 = (longlong *)0x0;
              *(undefined1 (*) [16])(param_1 + 0x60) = (undefined1  [16])0x0;
              plVar12 = (longlong *)0x0;
              auStack_98._8_8_ = *(undefined8 *)(param_1 + 0x68);
              goto LAB_23e7b4f5e;
            }
            iVar8 = FUN_23e97c060(plVar10,plVar12);
            *plVar12 = *plVar12 + -1;
            if (*plVar12 == 0) {
              (**(code **)(plVar12[1] + 0x30))(plVar12);
            }
            if (iVar8 == -1) {
              auStack_98._0_8_ = *(undefined8 *)(param_1 + 0x60);
              auStack_98._8_8_ = *(undefined8 *)(param_1 + 0x68);
              plStack_88 = *(longlong **)(param_1 + 0x70);
              uStack_a8 = 0xd2;
              *(undefined8 *)(param_1 + 0x70) = 0;
              *(undefined1 (*) [16])(param_1 + 0x60) = (undefined1  [16])0x0;
            }
            else {
              if (iVar8 == 1) {
                plVar14 = (longlong *)FUN_23e8bc2f0(plVar2,_DAT_23eed7af8);
                plVar12 = (longlong *)0x0;
                if (plVar14 != (longlong *)0x0) {
                  plVar15 = (longlong *)FUN_23e8c6640(plVar14,plVar10);
                  *plVar14 = *plVar14 + -1;
                  if (*plVar14 == 0) {
                    (**(code **)(plVar14[1] + 0x30))(plVar14);
                  }
                  if (plVar15 == (longlong *)0x0) {
                    auStack_98._0_8_ = *(undefined8 *)(param_1 + 0x60);
                    plStack_88 = *(longlong **)(param_1 + 0x70);
                    plVar15 = (longlong *)0x0;
                    plVar12 = (longlong *)0x0;
                    *(undefined8 *)(param_1 + 0x70) = 0;
                    uStack_a8 = 0xd4;
                    iVar8 = 2;
                    plStack_b8 = (longlong *)0x0;
                    plStack_c0 = (longlong *)0x0;
                    plStack_c8 = (longlong *)0x0;
                    *(undefined1 (*) [16])(param_1 + 0x60) = (undefined1  [16])0x0;
                    plVar14 = (longlong *)0x0;
                    auStack_98._8_8_ = *(undefined8 *)(param_1 + 0x68);
                    goto LAB_23e7b4f5e;
                  }
                  plVar12 = (longlong *)PyNumber_Long(plVar15);
                  *plVar15 = *plVar15 + -1;
                  if (*plVar15 == 0) {
                    (**(code **)(plVar15[1] + 0x30))(plVar15);
                  }
                  plVar14 = DAT_23ed6cd08;
                  if (plVar12 != (longlong *)0x0) {
                    lVar11 = *(longlong *)(param_1 + 0x10);
                    plVar16 = *(longlong **)(lVar11 + 0xe50);
                    if (plVar16 == (longlong *)0x0) {
                      plVar16 = (longlong *)FUN_23e916a20(PyTuple_Type_exref,8);
                    }
                    else {
                      lVar3 = plVar16[3];
                      *(int *)(lVar11 + 0xed4) = *(int *)(lVar11 + 0xed4) + -1;
                      *(longlong *)(lVar11 + 0xe50) = lVar3;
                      *plVar16 = 1;
                    }
                    pcVar18 = _PyRuntime_exref;
                    *(undefined1 (*) [16])(plVar16 + 3) = (undefined1  [16])0x0;
                    *(undefined1 (*) [16])(plVar16 + 7) = (undefined1  [16])0x0;
                    *(undefined1 (*) [16])(plVar16 + 5) = (undefined1  [16])0x0;
                    *(undefined1 (*) [16])(plVar16 + 9) = (undefined1  [16])0x0;
                    lVar11 = *(longlong *)
                              (*(longlong *)(*(longlong *)(pcVar18 + 0x1f8) + 0x10) + 0x2e8);
                    lVar3 = plVar16[-1];
                    puVar4 = *(undefined8 **)(lVar11 + 8);
                    *puVar4 = plVar16 + -2;
                    plVar16[-2] = lVar11;
                    plVar16[-1] = (ulonglong)((uint)lVar3 & 3) | (ulonglong)puVar4;
                    *(longlong **)(lVar11 + 8) = plVar16 + -2;
                    *plVar14 = *plVar14 + 1;
                    plVar16[3] = (longlong)plVar14;
                    plVar14 = DAT_23ed6cd08;
                    *DAT_23ed6cd08 = *DAT_23ed6cd08 + 1;
                    plVar16[4] = (longlong)plVar14;
                    pcVar18 = _Py_FalseStruct_exref;
                    plVar16[7] = (longlong)_Py_FalseStruct_exref;
                    *(longlong *)pcVar18 = *(longlong *)pcVar18 + 3;
                    plVar16[5] = (longlong)pcVar18;
                    plVar16[6] = (longlong)pcVar18;
                    plVar14 = DAT_23ed6cd28;
                    *DAT_23ed6cd28 = *DAT_23ed6cd28 + 1;
                    plVar16[8] = (longlong)plVar14;
                    lVar11 = FUN_23e8bc2f0(plVar2,_DAT_23eed7b48);
                    if (lVar11 == 0) {
                      auStack_98._0_8_ = *(undefined8 *)(param_1 + 0x60);
                      auStack_98._8_8_ = *(undefined8 *)(param_1 + 0x68);
                      plStack_88 = *(longlong **)(param_1 + 0x70);
                      *(undefined8 *)(param_1 + 0x70) = 0;
                      *(undefined1 (*) [16])(param_1 + 0x60) = (undefined1  [16])0x0;
                      *plVar16 = *plVar16 + -1;
                      if (*plVar16 == 0) {
                        (**(code **)(plVar16[1] + 0x30))(plVar16);
                      }
                      plVar15 = (longlong *)0x0;
                      uStack_a8 = 0xd5;
                      iVar8 = 2;
                      plStack_b8 = (longlong *)0x0;
                      plStack_c0 = (longlong *)0x0;
                      plStack_c8 = (longlong *)0x0;
                      plVar14 = (longlong *)0x0;
                      goto LAB_23e7b4f5e;
                    }
                    plVar16[9] = lVar11;
                    plVar15 = (longlong *)0x0;
                    plVar14 = (longlong *)0x0;
                    *plVar12 = *plVar12 + 1;
                    plStack_b8 = (longlong *)0x0;
                    plVar16[10] = (longlong)plVar12;
                    plStack_c0 = (longlong *)0x0;
                    plStack_c8 = (longlong *)0x0;
                    goto LAB_23e7b4bf0;
                  }
                }
                auStack_98._0_8_ = *(undefined8 *)(param_1 + 0x60);
                plStack_88 = *(longlong **)(param_1 + 0x70);
                plVar15 = (longlong *)0x0;
                plVar14 = (longlong *)0x0;
                *(undefined8 *)(param_1 + 0x70) = 0;
                uStack_a8 = 0xd4;
                iVar8 = 2;
                plStack_b8 = (longlong *)0x0;
                plStack_c0 = (longlong *)0x0;
                plStack_c8 = (longlong *)0x0;
                *(undefined1 (*) [16])(param_1 + 0x60) = (undefined1  [16])0x0;
                auStack_98._8_8_ = *(undefined8 *)(param_1 + 0x68);
                goto LAB_23e7b4f5e;
              }
              plVar12 = (longlong *)FUN_23e8bc2f0(plVar2,_DAT_23eed7bf8);
              if (plVar12 == (longlong *)0x0) goto LAB_23e7b57d0;
              plVar14 = (longlong *)FUN_23e8bc2f0(plVar2,_DAT_23eed7b18);
              if (plVar14 == (longlong *)0x0) {
                auStack_98._0_8_ = *(undefined8 *)(param_1 + 0x60);
                auStack_98._8_8_ = *(undefined8 *)(param_1 + 0x68);
                plStack_88 = *(longlong **)(param_1 + 0x70);
                *(undefined8 *)(param_1 + 0x70) = 0;
                *(undefined1 (*) [16])(param_1 + 0x60) = (undefined1  [16])0x0;
                *plVar12 = *plVar12 + -1;
                plVar15 = plStack_88;
                uVar23 = auStack_98._0_8_;
                uVar24 = auStack_98._8_8_;
                if (*plVar12 == 0) {
                  (**(code **)(plVar12[1] + 0x30))(plVar12);
                  plVar15 = plStack_88;
                  uVar23 = auStack_98._0_8_;
                  uVar24 = auStack_98._8_8_;
                }
              }
              else {
                plVar15 = (longlong *)FUN_23e8bc2f0(plVar2,_DAT_23eed7ae0);
                if (plVar15 == (longlong *)0x0) {
                  auStack_98._0_8_ = *(undefined8 *)(param_1 + 0x60);
                  auStack_98._8_8_ = *(undefined8 *)(param_1 + 0x68);
                  plStack_88 = *(longlong **)(param_1 + 0x70);
                  *(undefined8 *)(param_1 + 0x70) = 0;
                  *(undefined1 (*) [16])(param_1 + 0x60) = (undefined1  [16])0x0;
                  *plVar12 = *plVar12 + -1;
                  if (*plVar12 == 0) {
                    (**(code **)(plVar12[1] + 0x30))(plVar12);
                  }
                  *plVar14 = *plVar14 + -1;
                  plVar15 = plStack_88;
                  uVar23 = auStack_98._0_8_;
                  uVar24 = auStack_98._8_8_;
                  if (*plVar14 == 0) {
                    (**(code **)(plVar14[1] + 0x30))(plVar14);
                    plVar15 = plStack_88;
                    uVar23 = auStack_98._0_8_;
                    uVar24 = auStack_98._8_8_;
                  }
                }
                else {
                  *(undefined4 *)(plVar5 + 5) = 0xd8;
                  plStack_78 = plVar1;
                  plStack_70 = plVar14;
                  plStack_68 = plVar15;
                  plVar16 = (longlong *)FUN_23e956150(param_1,plVar12,&plStack_78);
                  *plVar12 = *plVar12 + -1;
                  if (*plVar12 == 0) {
                    (**(code **)(plVar12[1] + 0x30))(plVar12);
                  }
                  *plVar14 = *plVar14 + -1;
                  if (*plVar14 == 0) {
                    (**(code **)(plVar14[1] + 0x30))(plVar14);
                  }
                  *plVar15 = *plVar15 + -1;
                  if (*plVar15 == 0) {
                    (**(code **)(plVar15[1] + 0x30))(plVar15);
                  }
                  if (plVar16 != (longlong *)0x0) {
                    plVar12 = (longlong *)FUN_23a388310(plVar16);
                    *plVar16 = *plVar16 + -1;
                    if (*plVar16 == 0) {
                      (**(code **)(plVar16[1] + 0x30))(plVar16);
                    }
                    if (plVar12 != (longlong *)0x0) {
                      plVar14 = (longlong *)(**(code **)(plVar12[1] + 0xe0))(plVar12);
                      if ((plVar14 == (longlong *)0x0) &&
                         (plVar14 = (longlong *)FUN_23a3c1b70(param_1,auStack_98,0,2),
                         plVar14 == (longlong *)0x0)) {
                        plStack_c8 = (longlong *)0x0;
                      }
                      else {
                        plStack_c8 = (longlong *)(**(code **)(plVar12[1] + 0xe0))(plVar12);
                        if (((plStack_c8 != (longlong *)0x0) ||
                            (plStack_c8 = (longlong *)FUN_23a3c1b70(param_1,auStack_98,1,2),
                            plStack_c8 != (longlong *)0x0)) &&
                           (cVar7 = FUN_23a3884a0(param_1,auStack_98,plVar12,2), cVar7 != '\0')) {
                          *plVar12 = *plVar12 + -1;
                          if (*plVar12 == 0) {
                            (**(code **)(plVar12[1] + 0x30))(plVar12);
                          }
                          if (*plVar14 == 0) {
                            (**(code **)(plVar14[1] + 0x30))(plVar14);
                          }
                          if (*plStack_c8 == 0) {
                            (**(code **)(plStack_c8[1] + 0x30))();
                          }
                          plVar12 = (longlong *)FUN_23e8bc2f0(plVar2,_DAT_23eed7bf8);
                          if (plVar12 == (longlong *)0x0) goto LAB_23e7b5f39;
                          plVar15 = (longlong *)FUN_23e8bc2f0(plVar2,_DAT_23eed7b20);
                          if (plVar15 == (longlong *)0x0) {
                            auStack_98._0_8_ = *(undefined8 *)(param_1 + 0x60);
                            auStack_98._8_8_ = *(undefined8 *)(param_1 + 0x68);
                            plStack_88 = *(longlong **)(param_1 + 0x70);
                            *(undefined8 *)(param_1 + 0x70) = 0;
                            *(undefined1 (*) [16])(param_1 + 0x60) = (undefined1  [16])0x0;
                            *plVar12 = *plVar12 + -1;
                            plVar16 = plStack_88;
                            uVar23 = auStack_98._0_8_;
                            uVar24 = auStack_98._8_8_;
                            if (*plVar12 == 0) {
                              (**(code **)(plVar12[1] + 0x30))(plVar12);
                              plVar16 = plStack_88;
                              uVar23 = auStack_98._0_8_;
                              uVar24 = auStack_98._8_8_;
                            }
                          }
                          else {
                            plVar16 = (longlong *)FUN_23e8bc2f0(plVar2,_DAT_23eed7ae8);
                            if (plVar16 == (longlong *)0x0) {
                              auStack_98._0_8_ = *(undefined8 *)(param_1 + 0x60);
                              auStack_98._8_8_ = *(undefined8 *)(param_1 + 0x68);
                              plStack_88 = *(longlong **)(param_1 + 0x70);
                              *(undefined8 *)(param_1 + 0x70) = 0;
                              *(undefined1 (*) [16])(param_1 + 0x60) = (undefined1  [16])0x0;
                              *plVar12 = *plVar12 + -1;
                              if (*plVar12 == 0) {
                                (**(code **)(plVar12[1] + 0x30))(plVar12);
                              }
                              *plVar15 = *plVar15 + -1;
                              plVar16 = plStack_88;
                              uVar23 = auStack_98._0_8_;
                              uVar24 = auStack_98._8_8_;
                              if (*plVar15 == 0) {
                                (**(code **)(plVar15[1] + 0x30))(plVar15);
                                plVar16 = plStack_88;
                                uVar23 = auStack_98._0_8_;
                                uVar24 = auStack_98._8_8_;
                              }
                            }
                            else {
                              *(undefined4 *)(plVar5 + 5) = 0xd9;
                              plStack_78 = plVar1;
                              plStack_70 = plVar15;
                              plStack_68 = plVar16;
                              plVar17 = (longlong *)FUN_23e956150(param_1,plVar12,&plStack_78);
                              *plVar12 = *plVar12 + -1;
                              if (*plVar12 == 0) {
                                (**(code **)(plVar12[1] + 0x30))(plVar12);
                              }
                              *plVar15 = *plVar15 + -1;
                              if (*plVar15 == 0) {
                                (**(code **)(plVar15[1] + 0x30))(plVar15);
                              }
                              *plVar16 = *plVar16 + -1;
                              if (*plVar16 == 0) {
                                (**(code **)(plVar16[1] + 0x30))(plVar16);
                              }
                              if (plVar17 != (longlong *)0x0) {
                                plVar12 = (longlong *)FUN_23a388310(plVar17);
                                *plVar17 = *plVar17 + -1;
                                if (*plVar17 == 0) {
                                  (**(code **)(plVar17[1] + 0x30))(plVar17);
                                }
                                if (plVar12 != (longlong *)0x0) {
                                  plVar15 = (longlong *)(**(code **)(plVar12[1] + 0xe0))(plVar12);
                                  if ((plVar15 == (longlong *)0x0) &&
                                     (plVar15 = (longlong *)FUN_23a3c1b70(param_1,auStack_98,0,2),
                                     plVar15 == (longlong *)0x0)) {
                                    plStack_c0 = (longlong *)0x0;
                                  }
                                  else {
                                    plStack_c0 = (longlong *)
                                                 (**(code **)(plVar12[1] + 0xe0))(plVar12);
                                    if (((plStack_c0 != (longlong *)0x0) ||
                                        (plStack_c0 = (longlong *)
                                                      FUN_23a3c1b70(param_1,auStack_98,1,2),
                                        plStack_c0 != (longlong *)0x0)) &&
                                       (cVar7 = FUN_23a3884a0(param_1,auStack_98,plVar12,2),
                                       cVar7 != '\0')) {
                                      *plVar12 = *plVar12 + -1;
                                      if (*plVar12 == 0) {
                                        (**(code **)(plVar12[1] + 0x30))(plVar12);
                                      }
                                      if (*plVar15 == 0) {
                                        (**(code **)(plVar15[1] + 0x30))(plVar15);
                                      }
                                      if (*plStack_c0 == 0) {
                                        (**(code **)(plStack_c0[1] + 0x30))();
                                      }
                                      plVar12 = DAT_23ed6cd28;
                                      *DAT_23ed6cd28 = *DAT_23ed6cd28 + 1;
                                      plStack_b8 = plVar12;
                                      iVar8 = FUN_23a35f020(plStack_c8);
                                      if (iVar8 == -1) {
                                        auStack_98._0_8_ = *(undefined8 *)(param_1 + 0x60);
                                        plStack_88 = *(longlong **)(param_1 + 0x70);
                                        iVar8 = 0;
                                        *(undefined8 *)(param_1 + 0x70) = 0;
                                        uStack_a8 = 0xdf;
                                        plVar12 = (longlong *)0x0;
                                        *(undefined1 (*) [16])(param_1 + 0x60) =
                                             (undefined1  [16])0x0;
                                        auStack_98._8_8_ = *(undefined8 *)(param_1 + 0x68);
                                        goto LAB_23e7b4f5e;
                                      }
                                      if (iVar8 == 0) {
                                        iVar9 = FUN_23a35f020(plStack_c0);
                                        iVar8 = 0;
                                        if (iVar9 == -1) {
                                          auStack_98._0_8_ = *(undefined8 *)(param_1 + 0x60);
                                          plStack_88 = *(longlong **)(param_1 + 0x70);
                                          uStack_a8 = 0xdf;
                                          *(undefined8 *)(param_1 + 0x70) = 0;
                                          plVar12 = (longlong *)0x0;
                                          *(undefined1 (*) [16])(param_1 + 0x60) =
                                               (undefined1  [16])0x0;
                                          auStack_98._8_8_ = *(undefined8 *)(param_1 + 0x68);
                                          goto LAB_23e7b4f5e;
                                        }
                                        if (iVar9 == 1) goto LAB_23e7b49ad;
                                      }
                                      else {
LAB_23e7b49ad:
                                        lVar11 = FUN_23e8def00();
                                        if (lVar11 == 0) {
                                          FUN_23e915740(param_1,auStack_98,_DAT_23eed7b00);
                                          uStack_a8 = 0xe0;
                                          iVar8 = 0;
                                          plVar12 = (longlong *)0x0;
                                          goto LAB_23e7b4f5e;
                                        }
                                        *(undefined4 *)(plVar5 + 5) = 0xe0;
                                        plVar16 = (longlong *)
                                                  FUN_23e915840(param_1,lVar11,_DAT_23eed7c00);
                                        if (plVar16 == (longlong *)0x0) {
                                          auStack_98._0_8_ = *(undefined8 *)(param_1 + 0x60);
                                          plStack_88 = *(longlong **)(param_1 + 0x70);
                                          iVar8 = 0;
                                          *(undefined8 *)(param_1 + 0x70) = 0;
                                          uStack_a8 = 0xe0;
                                          *(undefined1 (*) [16])(param_1 + 0x60) =
                                               (undefined1  [16])0x0;
                                          plVar12 = (longlong *)0x0;
                                          auStack_98._8_8_ = *(undefined8 *)(param_1 + 0x68);
                                          goto LAB_23e7b4f5e;
                                        }
                                        *plVar16 = *plVar16 + -1;
                                        if (*plVar16 == 0) {
                                          FUN_23a334bc0(plVar16);
                                        }
                                        plVar16 = (longlong *)FUN_23e8bfe00(plVar10,_DAT_23eed7c10);
                                        if (plVar16 == (longlong *)0x0) {
                                          auStack_98._0_8_ = *(undefined8 *)(param_1 + 0x60);
                                          plStack_88 = *(longlong **)(param_1 + 0x70);
                                          iVar8 = 1;
                                          *(undefined8 *)(param_1 + 0x70) = 0;
                                          uStack_a8 = 0xe2;
                                          *(undefined1 (*) [16])(param_1 + 0x60) =
                                               (undefined1  [16])0x0;
                                          plVar12 = (longlong *)0x0;
                                          auStack_98._8_8_ = *(undefined8 *)(param_1 + 0x68);
                                          goto LAB_23e7b4f5e;
                                        }
                                        cVar7 = FUN_23e8d9ac0(plVar2,_DAT_23eed7af8);
                                        *plVar16 = *plVar16 + -1;
                                        if (*plVar16 == 0) {
                                          FUN_23a334bc0(plVar16);
                                        }
                                        if (cVar7 == '\0') {
                                          auStack_98._0_8_ = *(undefined8 *)(param_1 + 0x60);
                                          plStack_88 = *(longlong **)(param_1 + 0x70);
                                          plVar12 = (longlong *)0x0;
                                          *(undefined8 *)(param_1 + 0x70) = 0;
                                          uStack_a8 = 0xe2;
                                          iVar8 = 1;
                                          *(undefined1 (*) [16])(param_1 + 0x60) =
                                               (undefined1  [16])0x0;
                                          auStack_98._8_8_ = *(undefined8 *)(param_1 + 0x68);
                                          goto LAB_23e7b4f5e;
                                        }
                                        iVar8 = FUN_23a35f020();
                                        if (iVar8 == -1) {
                                          auStack_98._0_8_ = *(undefined8 *)(param_1 + 0x60);
                                          plStack_88 = *(longlong **)(param_1 + 0x70);
                                          plVar12 = (longlong *)0x0;
                                          *(undefined8 *)(param_1 + 0x70) = 0;
                                          uStack_a8 = 0xe3;
                                          iVar8 = 1;
                                          *(undefined1 (*) [16])(param_1 + 0x60) =
                                               (undefined1  [16])0x0;
                                          auStack_98._8_8_ = *(undefined8 *)(param_1 + 0x68);
                                          goto LAB_23e7b4f5e;
                                        }
                                        plStack_b8 = _DAT_23eed7c20;
                                        if (iVar8 != 0) {
                                          plStack_b8 = _DAT_23eed7c18;
                                        }
                                        *plStack_b8 = *plStack_b8 + 1;
                                        lVar11 = *plVar12;
                                        *plVar12 = lVar11 + -1;
                                        if (lVar11 + -1 == 0) {
                                          FUN_23a334bc0(plVar12);
                                        }
                                        iVar8 = 1;
                                      }
                                      lVar11 = *(longlong *)(param_1 + 0x10);
                                      plVar16 = *(longlong **)(lVar11 + 0xe50);
                                      if (plVar16 == (longlong *)0x0) {
                                        plVar16 = (longlong *)FUN_23e916a20(PyTuple_Type_exref,8);
                                      }
                                      else {
                                        lVar3 = plVar16[3];
                                        *(int *)(lVar11 + 0xed4) = *(int *)(lVar11 + 0xed4) + -1;
                                        *(longlong *)(lVar11 + 0xe50) = lVar3;
                                        *plVar16 = 1;
                                      }
                                      pcVar18 = _PyRuntime_exref;
                                      *(undefined1 (*) [16])(plVar16 + 3) = (undefined1  [16])0x0;
                                      *(undefined1 (*) [16])(plVar16 + 5) = (undefined1  [16])0x0;
                                      *(undefined1 (*) [16])(plVar16 + 7) = (undefined1  [16])0x0;
                                      *(undefined1 (*) [16])(plVar16 + 9) = (undefined1  [16])0x0;
                                      lVar11 = *(longlong *)
                                                (*(longlong *)
                                                  (*(longlong *)(pcVar18 + 0x1f8) + 0x10) + 0x2e8);
                                      lVar3 = plVar16[-1];
                                      puVar4 = *(undefined8 **)(lVar11 + 8);
                                      *puVar4 = plVar16 + -2;
                                      plVar16[-2] = lVar11;
                                      plVar16[-1] = (ulonglong)((uint)lVar3 & 3) | (ulonglong)puVar4
                                      ;
                                      *(longlong **)(lVar11 + 8) = plVar16 + -2;
                                      *plVar14 = *plVar14 + 1;
                                      plVar16[3] = (longlong)plVar14;
                                      *plVar15 = *plVar15 + 1;
                                      plVar16[4] = (longlong)plVar15;
                                      *plStack_c8 = *plStack_c8 + 1;
                                      plVar16[5] = (longlong)plStack_c8;
                                      *plStack_c0 = *plStack_c0 + 1;
                                      plVar16[6] = (longlong)plStack_c0;
                                      pcVar18 = _Py_TrueStruct_exref;
                                      if (iVar8 != 1) {
                                        pcVar18 = _Py_FalseStruct_exref;
                                      }
                                      *(longlong *)pcVar18 = *(longlong *)pcVar18 + 1;
                                      plVar16[7] = (longlong)pcVar18;
                                      uVar23 = _DAT_23eed7b48;
                                      *plStack_b8 = *plStack_b8 + 1;
                                      plVar16[8] = (longlong)plStack_b8;
                                      lVar11 = FUN_23e8bc2f0(plVar2,uVar23);
                                      if (lVar11 != 0) {
                                        plVar16[9] = lVar11;
                                        plVar5 = DAT_23ed6ccf0;
                                        plVar12 = (longlong *)0x0;
                                        *DAT_23ed6ccf0 = *DAT_23ed6ccf0 + 1;
                                        plVar16[10] = (longlong)plVar5;
LAB_23e7b4bf0:
                                        lVar11 = *(longlong *)(*(longlong *)(param_1 + 0x38) + 8);
                                        plVar5 = *(longlong **)(lVar11 + 0x28);
                                        plVar17 = (longlong *)plVar5[2];
                                        *(undefined8 *)(*(longlong *)(param_1 + 0x38) + 8) =
                                             *(undefined8 *)(lVar11 + 0x30);
                                        *(undefined4 *)(plVar5 + 8) = 0xffffffff;
                                        if (plVar17 != (longlong *)0x0) {
                                          plVar5[2] = 0;
                                          *plVar17 = *plVar17 + -1;
                                          if (*plVar17 == 0) {
                                            (**(code **)(plVar17[1] + 0x30))();
                                          }
                                        }
                                        *plVar5 = *plVar5 + -1;
                                        if (*plVar5 == 0) {
                                          (**(code **)(plVar5[1] + 0x30))(plVar5);
                                        }
                                        plVar5[0xf] = 0;
                                        *plVar10 = *plVar10 + -1;
                                        if (*plVar10 == 0) {
                                          (**(code **)(plVar10[1] + 0x30))(plVar10);
                                        }
                                        *plVar13 = *plVar13 + -1;
                                        if (*plVar13 == 0) {
                                          (**(code **)(plVar13[1] + 0x30))(plVar13);
                                        }
                                        if ((plVar12 != (longlong *)0x0) &&
                                           (*plVar12 = *plVar12 + -1, *plVar12 == 0)) {
                                          (**(code **)(plVar12[1] + 0x30))(plVar12);
                                        }
                                        if ((plVar14 != (longlong *)0x0) &&
                                           (*plVar14 = *plVar14 + -1, *plVar14 == 0)) {
                                          (**(code **)(plVar14[1] + 0x30))(plVar14);
                                        }
                                        if ((plStack_c8 != (longlong *)0x0) &&
                                           (lVar11 = *plStack_c8, *plStack_c8 = lVar11 + -1,
                                           lVar11 + -1 == 0)) {
                                          (**(code **)(plStack_c8[1] + 0x30))(plStack_c8);
                                        }
                                        if ((plVar15 != (longlong *)0x0) &&
                                           (*plVar15 = *plVar15 + -1, *plVar15 == 0)) {
                                          (**(code **)(plVar15[1] + 0x30))(plVar15);
                                        }
                                        if ((plStack_c0 != (longlong *)0x0) &&
                                           (lVar11 = *plStack_c0, *plStack_c0 = lVar11 + -1,
                                           lVar11 + -1 == 0)) {
                                          (**(code **)(plStack_c0[1] + 0x30))(plStack_c0);
                                        }
                                        if ((plStack_b8 != (longlong *)0x0) &&
                                           (lVar11 = *plStack_b8, *plStack_b8 = lVar11 + -1,
                                           lVar11 + -1 == 0)) {
                                          (**(code **)(plStack_b8[1] + 0x30))(plStack_b8);
                                        }
                                        *plVar2 = *plVar2 + -1;
                                        if (*plVar2 == 0) {
                                          (**(code **)(plVar2[1] + 0x30))(plVar2);
                                        }
                                        lVar11 = *plVar1;
                                        *plVar1 = lVar11 + -1;
                                        if (lVar11 + -1 != 0) {
                                          return plVar16;
                                        }
                                        (**(code **)(plVar1[1] + 0x30))(plVar1);
                                        return plVar16;
                                      }
                                      auStack_98._0_8_ = *(undefined8 *)(param_1 + 0x60);
                                      auStack_98._8_8_ = *(undefined8 *)(param_1 + 0x68);
                                      plStack_88 = *(longlong **)(param_1 + 0x70);
                                      uStack_a8 = 0xe5;
                                      *(undefined8 *)(param_1 + 0x70) = 0;
                                      *(undefined1 (*) [16])(param_1 + 0x60) = (undefined1  [16])0x0
                                      ;
                                      *plVar16 = *plVar16 + -1;
                                      plVar12 = (longlong *)0x0;
                                      if (*plVar16 == 0) {
                                        FUN_23a334bc0(plVar16);
                                        uStack_a8 = 0xe5;
                                      }
                                      goto LAB_23e7b4f5e;
                                    }
                                  }
                                  plVar16 = plStack_88;
                                  uVar24 = auStack_98._8_8_;
                                  uVar23 = auStack_98._0_8_;
                                  plStack_88 = (longlong *)0x0;
                                  auStack_98 = (undefined1  [16])0x0;
                                  *plVar12 = *plVar12 + -1;
                                  if (*plVar12 == 0) {
                                    (**(code **)(plVar12[1] + 0x30))(plVar12);
                                  }
                                  plStack_88 = (longlong *)0x0;
                                  auStack_98._0_8_ = 0;
                                  auStack_98._8_8_ = 0;
                                  if ((plVar15 != (longlong *)0x0) &&
                                     (*plVar15 = *plVar15 + -1, *plVar15 == 0)) {
                                    (**(code **)(plVar15[1] + 0x30))(plVar15);
                                  }
                                  if ((plStack_c0 != (longlong *)0x0) &&
                                     (lVar11 = *plStack_c0, *plStack_c0 = lVar11 + -1,
                                     lVar11 + -1 == 0)) {
                                    (**(code **)(plStack_c0[1] + 0x30))();
                                  }
                                  goto LAB_23e7b5f52;
                                }
                              }
LAB_23e7b5f39:
                              plVar16 = *(longlong **)(param_1 + 0x70);
                              *(undefined8 *)(param_1 + 0x70) = 0;
                              uVar23 = *(undefined8 *)(param_1 + 0x60);
                              *(undefined1 (*) [16])(param_1 + 0x60) = (undefined1  [16])0x0;
                              uVar24 = *(undefined8 *)(param_1 + 0x68);
                            }
                          }
LAB_23e7b5f52:
                          uStack_a8 = 0xd9;
                          plVar15 = (longlong *)0x0;
                          plVar12 = (longlong *)0x0;
                          iVar8 = 2;
                          plStack_b8 = (longlong *)0x0;
                          plStack_c0 = (longlong *)0x0;
                          plStack_88 = plVar16;
                          auStack_98._0_8_ = uVar23;
                          auStack_98._8_8_ = uVar24;
                          goto LAB_23e7b4f5e;
                        }
                      }
                      plVar15 = plStack_88;
                      uVar24 = auStack_98._8_8_;
                      uVar23 = auStack_98._0_8_;
                      plStack_88 = (longlong *)0x0;
                      auStack_98 = (undefined1  [16])0x0;
                      *plVar12 = *plVar12 + -1;
                      if (*plVar12 == 0) {
                        (**(code **)(plVar12[1] + 0x30))(plVar12);
                      }
                      plStack_88 = (longlong *)0x0;
                      auStack_98._0_8_ = 0;
                      auStack_98._8_8_ = 0;
                      if ((plVar14 != (longlong *)0x0) && (*plVar14 = *plVar14 + -1, *plVar14 == 0))
                      {
                        (**(code **)(plVar14[1] + 0x30))(plVar14);
                      }
                      if ((plStack_c8 != (longlong *)0x0) &&
                         (lVar11 = *plStack_c8, *plStack_c8 = lVar11 + -1, lVar11 + -1 == 0)) {
                        (**(code **)(plStack_c8[1] + 0x30))();
                      }
                      goto LAB_23e7b57e9;
                    }
                  }
LAB_23e7b57d0:
                  plVar15 = *(longlong **)(param_1 + 0x70);
                  *(undefined8 *)(param_1 + 0x70) = 0;
                  uVar23 = *(undefined8 *)(param_1 + 0x60);
                  *(undefined1 (*) [16])(param_1 + 0x60) = (undefined1  [16])0x0;
                  uVar24 = *(undefined8 *)(param_1 + 0x68);
                }
              }
LAB_23e7b57e9:
              uStack_a8 = 0xd8;
              plStack_88 = plVar15;
              auStack_98._0_8_ = uVar23;
              auStack_98._8_8_ = uVar24;
            }
          }
          iVar8 = 2;
          plVar15 = (longlong *)0x0;
          plVar14 = (longlong *)0x0;
          plVar12 = (longlong *)0x0;
          plStack_b8 = (longlong *)0x0;
          plStack_c0 = (longlong *)0x0;
          plStack_c8 = (longlong *)0x0;
          goto LAB_23e7b4f5e;
        }
        plStack_88 = *(longlong **)(param_1 + 0x70);
        auStack_98._0_8_ = *(undefined8 *)(param_1 + 0x60);
        auStack_98._8_8_ = *(undefined8 *)(param_1 + 0x68);
        *(undefined8 *)(param_1 + 0x70) = 0;
        *(undefined1 (*) [16])(param_1 + 0x60) = (undefined1  [16])0x0;
      }
      plVar15 = (longlong *)0x0;
      plVar14 = (longlong *)0x0;
      plVar12 = (longlong *)0x0;
      plVar13 = (longlong *)0x0;
      uStack_a8 = 0xca;
      iVar8 = 2;
      plStack_b8 = (longlong *)0x0;
      plStack_c0 = (longlong *)0x0;
      plStack_c8 = (longlong *)0x0;
      goto LAB_23e7b4f5e;
    }
    uVar23 = *(undefined8 *)(param_1 + 0x60);
    uVar24 = *(undefined8 *)(param_1 + 0x68);
    plVar16 = *(longlong **)(param_1 + 0x70);
    *(undefined8 *)(param_1 + 0x70) = 0;
    *(undefined1 (*) [16])(param_1 + 0x60) = (undefined1  [16])0x0;
    plVar10 = plVar12;
  }
  else {
    cVar7 = FUN_23e8c7160(&plStack_78);
    plVar12 = plStack_78;
    if (cVar7 != '\0') goto LAB_23e7b44a5;
LAB_23e7b4ec0:
    plVar16 = *(longlong **)(param_1 + 0x70);
    *(undefined8 *)(param_1 + 0x70) = 0;
    uVar23 = *(undefined8 *)(param_1 + 0x60);
    uVar24 = *(undefined8 *)(param_1 + 0x68);
    *(undefined1 (*) [16])(param_1 + 0x60) = (undefined1  [16])0x0;
  }
  plStack_88 = (longlong *)0x0;
  auStack_98 = (undefined1  [16])0x0;
  *plVar10 = *plVar10 + -1;
  if (*plVar10 == 0) {
    (**(code **)(plVar10[1] + 0x30))(plVar10);
  }
  plVar15 = (longlong *)0x0;
  plVar14 = (longlong *)0x0;
  plVar12 = (longlong *)0x0;
  uStack_a8 = 0xc9;
  plVar13 = (longlong *)0x0;
  plVar10 = (longlong *)0x0;
  plStack_b8 = (longlong *)0x0;
  iVar8 = 2;
  plStack_c0 = (longlong *)0x0;
  plStack_c8 = (longlong *)0x0;
  plStack_88 = plVar16;
  auStack_98._0_8_ = uVar23;
  auStack_98._8_8_ = uVar24;
LAB_23e7b4f5e:
  plVar17 = plStack_88;
  plVar16 = DAT_23ed6a4f8;
  if (plStack_88 == (longlong *)0x0) {
    if (DAT_23ed6a4f8 == (longlong *)0x0) {
      plVar16 = (longlong *)FUN_23a33a530(PyTraceBack_Type_exref);
    }
    else {
      plVar17 = (longlong *)*DAT_23ed6a4f8;
      *DAT_23ed6a4f8 = 1;
      DAT_23ed6a4f8 = plVar17;
      DAT_23ed6a4f0 = DAT_23ed6a4f0 + -1;
    }
    pcVar18 = _PyRuntime_exref;
    plVar16[2] = 0;
    plVar16[3] = (longlong)plVar5;
    *plVar5 = *plVar5 + 1;
    lVar11 = *(longlong *)(pcVar18 + 0x1f8);
    *(undefined4 *)((longlong)plVar16 + 0x24) = uStack_a8;
    lVar11 = *(longlong *)(lVar11 + 0x10);
    *(undefined4 *)(plVar16 + 4) = 0xffffffff;
    lVar11 = *(longlong *)(lVar11 + 0x2e8);
    lVar3 = plVar16[-1];
    puVar4 = *(undefined8 **)(lVar11 + 8);
    *puVar4 = plVar16 + -2;
    plVar16[-2] = lVar11;
    plVar16[-1] = (ulonglong)((uint)lVar3 & 3) | (ulonglong)puVar4;
    *(longlong **)(lVar11 + 8) = plVar16 + -2;
    plVar17 = plVar16;
    if ((plStack_88 != (longlong *)0x0) && (*plStack_88 = *plStack_88 + -1, *plStack_88 == 0)) {
      (**(code **)(plStack_88[1] + 0x30))(plStack_88);
    }
  }
  else if ((longlong *)plStack_88[3] != plVar5) {
    if (DAT_23ed6a4f8 == (longlong *)0x0) {
      plVar16 = (longlong *)FUN_23a33a530(PyTraceBack_Type_exref);
    }
    else {
      plVar6 = (longlong *)*DAT_23ed6a4f8;
      *DAT_23ed6a4f8 = 1;
      DAT_23ed6a4f8 = plVar6;
      DAT_23ed6a4f0 = DAT_23ed6a4f0 + -1;
    }
    pcVar18 = _PyRuntime_exref;
    plVar16[3] = (longlong)plVar5;
    *plVar5 = *plVar5 + 1;
    lVar11 = *(longlong *)(pcVar18 + 0x1f8);
    *(undefined4 *)((longlong)plVar16 + 0x24) = uStack_a8;
    *(undefined4 *)(plVar16 + 4) = 0xffffffff;
    lVar11 = *(longlong *)(*(longlong *)(lVar11 + 0x10) + 0x2e8);
    puVar4 = *(undefined8 **)(lVar11 + 8);
    *puVar4 = plVar16 + -2;
    plVar16[-2] = lVar11;
    plVar16[-1] = (ulonglong)puVar4 | (ulonglong)((uint)plVar16[-1] & 3);
    *(longlong **)(lVar11 + 8) = plVar16 + -2;
    plVar16[2] = (longlong)plVar17;
    *plVar17 = *plVar17 + 1;
    plVar17 = plVar16;
    if ((plStack_88 != (longlong *)0x0) && (*plStack_88 = *plStack_88 + -1, *plStack_88 == 0)) {
      (**(code **)(plStack_88[1] + 0x30))(plStack_88);
    }
  }
  plStack_88 = plVar17;
  FUN_23e8bba40(plVar5,"ooooooooobo",plVar2,plVar1,plVar10,plVar13,plVar12,plVar14,plStack_c8,
                plVar15,plStack_c0,iVar8,plStack_b8);
  if (_DAT_23eedaac0 == plVar5) {
    *plVar5 = *plVar5 + -1;
    if (*plVar5 == 0) {
      (**(code **)(plVar5[1] + 0x30))(plVar5);
    }
    _DAT_23eedaac0 = (longlong *)0x0;
  }
  lVar11 = *(longlong *)(*(longlong *)(param_1 + 0x38) + 8);
  plVar5 = *(longlong **)(lVar11 + 0x28);
  plVar16 = (longlong *)plVar5[2];
  *(undefined8 *)(*(longlong *)(param_1 + 0x38) + 8) = *(undefined8 *)(lVar11 + 0x30);
  *(undefined4 *)(plVar5 + 8) = 0xffffffff;
  if (plVar16 != (longlong *)0x0) {
    plVar5[2] = 0;
    *plVar16 = *plVar16 + -1;
    if (*plVar16 == 0) {
      (**(code **)(plVar16[1] + 0x30))();
    }
  }
  *plVar5 = *plVar5 + -1;
  if (*plVar5 == 0) {
    (**(code **)(plVar5[1] + 0x30))(plVar5);
  }
  plVar16 = plStack_88;
  uVar24 = auStack_98._8_8_;
  uVar23 = auStack_98._0_8_;
  plVar5[0xf] = 0;
  auStack_98 = (undefined1  [16])0x0;
  plStack_88 = (longlong *)0x0;
  if ((plVar10 != (longlong *)0x0) && (*plVar10 = *plVar10 + -1, *plVar10 == 0)) {
    (**(code **)(plVar10[1] + 0x30))(plVar10);
  }
  if ((plVar13 != (longlong *)0x0) && (*plVar13 = *plVar13 + -1, *plVar13 == 0)) {
    (**(code **)(plVar13[1] + 0x30))(plVar13);
  }
  if ((plVar12 != (longlong *)0x0) && (*plVar12 = *plVar12 + -1, *plVar12 == 0)) {
    (**(code **)(plVar12[1] + 0x30))(plVar12);
  }
  if ((plVar14 != (longlong *)0x0) && (*plVar14 = *plVar14 + -1, *plVar14 == 0)) {
    (**(code **)(plVar14[1] + 0x30))(plVar14);
  }
  if ((plStack_c8 != (longlong *)0x0) &&
     (lVar11 = *plStack_c8, *plStack_c8 = lVar11 + -1, lVar11 + -1 == 0)) {
    (**(code **)(plStack_c8[1] + 0x30))(plStack_c8);
  }
  if ((plVar15 != (longlong *)0x0) && (*plVar15 = *plVar15 + -1, *plVar15 == 0)) {
    (**(code **)(plVar15[1] + 0x30))(plVar15);
  }
  if ((plStack_c0 != (longlong *)0x0) &&
     (lVar11 = *plStack_c0, *plStack_c0 = lVar11 + -1, lVar11 + -1 == 0)) {
    (**(code **)(plStack_c0[1] + 0x30))(plStack_c0);
  }
  if ((plStack_b8 != (longlong *)0x0) &&
     (lVar11 = *plStack_b8, *plStack_b8 = lVar11 + -1, lVar11 + -1 == 0)) {
    (**(code **)(plStack_b8[1] + 0x30))(plStack_b8);
  }
  auStack_98 = CONCAT88(uVar24,uVar23);
  *plVar2 = *plVar2 + -1;
  plStack_88 = plVar16;
  if (*plVar2 == 0) {
    (**(code **)(plVar2[1] + 0x30))(plVar2);
  }
  lVar11 = *plVar1;
  *plVar1 = lVar11 + -1;
  if (lVar11 + -1 == 0) {
    (**(code **)(plVar1[1] + 0x30))(plVar1);
  }
  FUN_23a33aa70(param_1,auStack_98._0_8_,auStack_98._8_8_,plStack_88);
  return (longlong *)0x0;
}
