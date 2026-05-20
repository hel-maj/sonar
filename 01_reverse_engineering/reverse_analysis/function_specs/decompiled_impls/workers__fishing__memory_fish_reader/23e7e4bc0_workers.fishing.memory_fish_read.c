/* ===== 23e7e4bc0 workers.fishing.memory_fish_read:c1267 ===== */
/* ghidra_name=FUN_23e7e4bc0 entry=23e7e4bc0 size=7876 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

longlong * FUN_23e7e4bc0(longlong param_1,undefined8 param_2,undefined8 *param_3)

{
  longlong lVar1;
  longlong *plVar2;
  longlong *plVar3;
  undefined8 *puVar4;
  longlong *plVar5;
  char cVar6;
  int iVar7;
  longlong *plVar8;
  longlong *plVar9;
  longlong *plVar10;
  longlong *plVar11;
  longlong *plVar12;
  longlong lVar13;
  longlong *plVar14;
  longlong *plVar15;
  longlong *plVar16;
  code *pcVar17;
  longlong *plVar18;
  longlong lVar19;
  undefined4 uVar20;
  longlong *plVar21;
  longlong *plVar22;
  longlong *plVar23;
  undefined8 uVar24;
  undefined8 uVar25;
  longlong *plStack_f8;
  longlong *plStack_e8;
  longlong *plStack_d8;
  longlong *plStack_c0;
  undefined1 *puStack_b8;
  longlong *plStack_b0;
  undefined1 auStack_a8 [16];
  longlong *aplStack_98 [2];
  longlong *plStack_88;
  longlong *plStack_80;
  longlong *plStack_78;
  
  plVar2 = (longlong *)param_3[1];
  lVar13 = *(longlong *)(param_1 + 0x10);
  plVar23 = (longlong *)*param_3;
  plVar3 = (longlong *)param_3[2];
  aplStack_98[0] = (longlong *)0x0;
  auStack_a8 = (undefined1  [16])0x0;
  if (*(int *)(lVar13 + 0x1188) == 0) {
    plVar18 = (longlong *)FUN_23a33a530(PyList_Type_exref);
  }
  else {
    iVar7 = *(int *)(lVar13 + 0x1188) + -1;
    *(int *)(lVar13 + 0x1188) = iVar7;
    plVar18 = *(longlong **)(lVar13 + 0xf08 + (longlong)iVar7 * 8);
    *plVar18 = 1;
  }
  pcVar17 = _PyRuntime_exref;
  plVar18[2] = 0;
  plVar18[4] = 0;
  plVar8 = _DAT_23eedeb50;
  lVar13 = *(longlong *)(pcVar17 + 0x1f8);
  plVar18[3] = 0;
  lVar13 = *(longlong *)(*(longlong *)(lVar13 + 0x10) + 0x2e8);
  lVar19 = plVar18[-1];
  puVar4 = *(undefined8 **)(lVar13 + 8);
  *puVar4 = plVar18 + -2;
  plVar18[-2] = lVar13;
  plVar18[-1] = (ulonglong)((uint)lVar19 & 3) | (ulonglong)puVar4;
  *(longlong **)(lVar13 + 8) = plVar18 + -2;
  if (plVar8 == (longlong *)0x0) {
LAB_23e7e4ccc:
    plVar8 = (longlong *)FUN_23e91f3b0(param_1,_DAT_23eedeb48,DAT_23eedebc0,0x40);
    _DAT_23eedeb50 = plVar8;
  }
  else {
    lVar13 = *plVar8;
    if (1 < lVar13) {
      *plVar8 = lVar13 + -1;
      goto LAB_23e7e4ccc;
    }
    if (plVar8[2] != 0) {
      *plVar8 = lVar13 + -1;
      if (lVar13 + -1 == 0) {
        (**(code **)(plVar8[1] + 0x30))(plVar8);
      }
      goto LAB_23e7e4ccc;
    }
  }
  lVar13 = *(longlong *)(param_1 + 0x38);
  lVar19 = *(longlong *)(lVar13 + 8);
  plVar8[0xf] = lVar19;
  *(longlong **)(lVar13 + 8) = plVar8 + 9;
  if ((lVar19 != 0) &&
     (((*(char *)(lVar19 + 0x45) == '\x01' ||
       ((ulonglong)
        (*(longlong *)(lVar19 + 0x20) + 0xb8 +
        (longlong)*(int *)(*(longlong *)(lVar19 + 0x20) + 0xa8) * 2) <=
        *(ulonglong *)(lVar19 + 0x38))) && (plVar8[0xe] != 0)))) {
    plVar9 = *(longlong **)(lVar19 + 0x28);
    *(longlong **)(plVar8[0xe] + 0x10) = plVar9;
    if (plVar9 != (longlong *)0x0) {
      *plVar9 = *plVar9 + 1;
    }
  }
  lVar19 = DAT_23eeddba8;
  *plVar8 = *plVar8 + 1;
  *(undefined4 *)(plVar8 + 8) = 0;
  lVar13 = *(longlong *)(lVar19 + 0x20);
  if (*(char *)(lVar13 + 10) == '\0') {
    plVar9 = (longlong *)FUN_23a37a020(lVar19,_DAT_23eeddce0);
    if (plVar9 == (longlong *)0x0) goto LAB_23e7e5251;
    lVar19 = *plVar9;
LAB_23e7e59a8:
    if (lVar19 == 0) goto LAB_23e7e5251;
LAB_23e7e4dbc:
    *(undefined4 *)(plVar8 + 5) = 0x5a;
    plVar9 = (longlong *)FUN_23e914090(param_1,lVar19,plVar23);
    if (plVar9 == (longlong *)0x0) {
      auStack_a8 = *(undefined1 (*) [16])(param_1 + 0x60);
      aplStack_98[0] = *(longlong **)(param_1 + 0x70);
      *(undefined8 *)(param_1 + 0x70) = 0;
      *(undefined1 (*) [16])(param_1 + 0x60) = (undefined1  [16])0x0;
    }
    else {
      plVar10 = (longlong *)FUN_23ebf7180(plVar9);
      *plVar9 = *plVar9 + -1;
      if (*plVar9 == 0) {
        (**(code **)(plVar9[1] + 0x30))(plVar9);
      }
      if (plVar10 != (longlong *)0x0) {
        plVar9 = (longlong *)0x0;
        if (plVar23 == (longlong *)0x0) {
          plStack_d8 = (longlong *)0x0;
          plVar22 = (longlong *)0x0;
LAB_23e7e63cb:
          lVar13 = plVar10[1];
          if (*(code **)(lVar13 + 0xe0) == (code *)0x0) {
            plStack_f8 = (longlong *)0x0;
            plVar15 = (longlong *)0x0;
            goto LAB_23e7e59cd;
          }
          plStack_c0 = (longlong *)(**(code **)(lVar13 + 0xe0))();
          if (plStack_c0 == (longlong *)0x0) {
            plStack_f8 = (longlong *)0x0;
            plVar15 = (longlong *)0x0;
            goto LAB_23e7e59e8;
          }
          if ((plVar9 != (longlong *)0x0) && (*plVar9 = *plVar9 + -1, *plVar9 == 0)) {
            (**(code **)(plVar9[1] + 0x30))(plVar9);
          }
          plVar9 = (longlong *)FUN_23a388310(plStack_c0);
          if (plVar9 == (longlong *)0x0) {
            plStack_f8 = (longlong *)0x0;
            plVar15 = (longlong *)0x0;
LAB_23e7e6380:
            pcVar17 = *(code **)(param_1 + 0x60);
            uVar25 = *(undefined8 *)(param_1 + 0x68);
            plVar12 = *(longlong **)(param_1 + 0x70);
            *(undefined8 *)(param_1 + 0x70) = 0;
            *(undefined1 (*) [16])(param_1 + 0x60) = (undefined1  [16])0x0;
            plStack_e8 = plStack_d8;
            goto LAB_23e7e5c83;
          }
          plVar11 = (longlong *)(**(code **)(plVar9[1] + 0xe0))(plVar9);
          if ((plVar11 == (longlong *)0x0) &&
             (plVar11 = (longlong *)FUN_23a3c1b70(param_1,auStack_a8,0,2),
             plVar11 == (longlong *)0x0)) {
            plVar15 = (longlong *)0x0;
            plStack_f8 = (longlong *)0x0;
            plStack_e8 = (longlong *)0x0;
LAB_23e7e5bd9:
            plVar12 = aplStack_98[0];
            pcVar17 = (code *)auStack_a8._0_8_;
            uVar25 = auStack_a8._8_8_;
            aplStack_98[0] = (longlong *)0x0;
            auStack_a8 = (undefined1  [16])0x0;
            *plVar9 = *plVar9 + -1;
            if (*plVar9 == 0) {
              (**(code **)(plVar9[1] + 0x30))(plVar9);
            }
            aplStack_98[0] = (longlong *)0x0;
            auStack_a8 = (undefined1  [16])0x0;
            if ((plVar11 != (longlong *)0x0) && (*plVar11 = *plVar11 + -1, *plVar11 == 0)) {
              (**(code **)(plVar11[1] + 0x30))(plVar11);
            }
            if ((plStack_e8 != (longlong *)0x0) &&
               (lVar13 = *plStack_e8, *plStack_e8 = lVar13 + -1, lVar13 + -1 == 0)) {
              (**(code **)(plStack_e8[1] + 0x30))(plStack_e8);
            }
            plStack_e8 = plStack_d8;
LAB_23e7e5c83:
            uVar20 = 0x5a;
            plVar11 = plVar22;
          }
          else {
            puStack_b8 = auStack_a8;
            plStack_e8 = (longlong *)(**(code **)(plVar9[1] + 0xe0))(plVar9);
            if ((plStack_e8 == (longlong *)0x0) &&
               (plStack_e8 = (longlong *)FUN_23a3c1b70(param_1,puStack_b8,1,2),
               plStack_e8 == (longlong *)0x0)) {
LAB_23e7e67ee:
              plStack_f8 = (longlong *)0x0;
              plVar15 = (longlong *)0x0;
              goto LAB_23e7e5bd9;
            }
            cVar6 = FUN_23a3884a0(param_1,puStack_b8,plVar9,2);
            lVar13 = *plVar9;
            if (cVar6 == '\0') goto LAB_23e7e67ee;
            *plVar9 = lVar13 + -1;
            if (lVar13 + -1 == 0) {
              (**(code **)(plVar9[1] + 0x30))(plVar9);
            }
            lVar13 = *plVar11;
            *plVar11 = lVar13 + 1;
            if (plVar22 != (longlong *)0x0) {
              *plVar22 = *plVar22 + -1;
              if (*plVar22 == 0) {
                (**(code **)(plVar22[1] + 0x30))(plVar22);
              }
              lVar13 = *plVar11 + -1;
            }
            *plVar11 = lVar13;
            if (lVar13 == 0) {
              (**(code **)(plVar11[1] + 0x30))(plVar11);
            }
            lVar13 = *plStack_e8;
            *plStack_e8 = lVar13 + 1;
            if (plStack_d8 != (longlong *)0x0) {
              *plStack_d8 = *plStack_d8 + -1;
              if (*plStack_d8 == 0) {
                (**(code **)(plStack_d8[1] + 0x30))(plStack_d8);
              }
              lVar13 = *plStack_e8 + -1;
            }
            *plStack_e8 = lVar13;
            if (lVar13 == 0) {
              (**(code **)(plStack_e8[1] + 0x30))(plStack_e8);
            }
            plVar22 = plVar11;
            if (plVar3 == (longlong *)0x0) {
              plVar15 = (longlong *)0x0;
              plStack_f8 = (longlong *)0x0;
LAB_23e7e6693:
              puStack_b8 = auStack_a8;
              auStack_a8._8_8_ =
                   PyUnicode_FromFormat
                             ("cannot access local variable \'%U\' where it is not associated with a value"
                              ,DAT_23eeddce8);
              auStack_a8._0_8_ = *(undefined8 *)PyExc_UnboundLocalError_exref;
              *(longlong *)auStack_a8._0_8_ = *(longlong *)auStack_a8._0_8_ + 1;
              aplStack_98[0] = (longlong *)0x0;
              if ((code *)auStack_a8._0_8_ != _Py_NoneStruct_exref) {
                FUN_23e91b1b0(param_1,puStack_b8,auStack_a8 + 8,aplStack_98);
              }
              uVar20 = 0x5b;
              FUN_23ebf6a40(*(undefined8 *)(param_1 + 0x138),auStack_a8._8_8_);
              plVar11 = plVar22;
              plVar12 = aplStack_98[0];
              pcVar17 = (code *)auStack_a8._0_8_;
              uVar25 = auStack_a8._8_8_;
              goto LAB_23e7e570b;
            }
            plVar9 = (longlong *)FUN_23e97e310(param_1,DAT_23ed6ccf0,plStack_e8,plVar3);
            if (plVar9 == (longlong *)0x0) {
              plStack_f8 = (longlong *)0x0;
              plVar15 = (longlong *)0x0;
            }
            else {
              plStack_b0 = (longlong *)FUN_23ebf7180(plVar9);
              *plVar9 = *plVar9 + -1;
              if (*plVar9 == 0) {
                (**(code **)(plVar9[1] + 0x30))(plVar9);
              }
              if (plStack_b0 != (longlong *)0x0) {
                plVar15 = (longlong *)(**(code **)(plStack_b0[1] + 0xe0))(plStack_b0);
                if (plVar15 == (longlong *)0x0) {
                  cVar6 = FUN_23a3591a0(param_1);
                  if (cVar6 != '\0') {
                    *plStack_b0 = *plStack_b0 + -1;
                    if (*plStack_b0 == 0) {
                      (**(code **)(plStack_b0[1] + 0x30))(plStack_b0);
                    }
                    lVar13 = *(longlong *)(param_1 + 0x10);
                    if ((((*(int *)(*(longlong *)(lVar13 + 0x28) + 0x160) == 0) &&
                         (*(int *)(lVar13 + 0x78) == 0)) ||
                        (iVar7 = Py_MakePendingCalls(), -1 < iVar7)) ||
                       (*(longlong *)(param_1 + 0x60) == 0)) goto LAB_23e7e6921;
                    plVar15 = (longlong *)0x0;
                    plStack_f8 = (longlong *)0x0;
                    goto LAB_23e7e6331;
                  }
                  pcVar17 = *(code **)(param_1 + 0x60);
                  uVar25 = *(undefined8 *)(param_1 + 0x68);
                  plVar12 = *(longlong **)(param_1 + 0x70);
                  aplStack_98[0] = (longlong *)0x0;
                  *(undefined8 *)(param_1 + 0x70) = 0;
                  uVar20 = 0x5b;
                  plStack_f8 = (longlong *)0x0;
                  *(undefined1 (*) [16])(param_1 + 0x60) = (undefined1  [16])0x0;
                  auStack_a8 = (undefined1  [16])0x0;
                }
                else {
                  *plVar15 = *plVar15 + 1;
                  plVar9 = (longlong *)FUN_23e8dd7c0();
                  if (plVar9 == (longlong *)0x0) {
LAB_23e7e58f2:
                    plStack_f8 = plVar9;
                    puStack_b8 = auStack_a8;
                    uVar20 = 0x5c;
                    FUN_23e915740(param_1,puStack_b8,DAT_23eeddcf0);
                    plVar21 = plVar15;
                    plVar12 = aplStack_98[0];
                    pcVar17 = (code *)auStack_a8._0_8_;
                    uVar25 = auStack_a8._8_8_;
                  }
                  else {
                    auStack_a8._8_8_ =
                         PyUnicode_FromFormat
                                   ("cannot access local variable \'%U\' where it is not associated with a value"
                                    ,_DAT_23eeddc80);
                    auStack_a8._0_8_ = *(undefined8 *)PyExc_UnboundLocalError_exref;
                    *(longlong *)auStack_a8._0_8_ = *(longlong *)auStack_a8._0_8_ + 1;
                    aplStack_98[0] = (longlong *)0x0;
                    if ((code *)auStack_a8._0_8_ != _Py_NoneStruct_exref) {
                      FUN_23e91b1b0(param_1,puStack_b8,auStack_a8 + 8,aplStack_98);
                    }
                    uVar20 = 0x5c;
                    FUN_23ebf6a40(*(undefined8 *)(param_1 + 0x138),auStack_a8._8_8_);
                    plStack_f8 = (longlong *)0x0;
                    plVar21 = plVar15;
                    plVar12 = aplStack_98[0];
                    pcVar17 = (code *)auStack_a8._0_8_;
                    uVar25 = auStack_a8._8_8_;
                  }
LAB_23e7e56c0:
                  aplStack_98[0] = (longlong *)0x0;
                  auStack_a8 = (undefined1  [16])0x0;
                  *plVar21 = *plVar21 + -1;
                  plVar11 = plVar22;
                  if (*plVar21 == 0) {
                    (**(code **)(plVar21[1] + 0x30))(plVar21);
                  }
                }
LAB_23e7e56d0:
                lVar13 = *plStack_b0;
                *plStack_b0 = lVar13 + -1;
                if (lVar13 + -1 == 0) {
                  (**(code **)(plStack_b0[1] + 0x30))(plStack_b0);
                }
                goto LAB_23e7e570b;
              }
              plVar15 = (longlong *)0x0;
              plStack_f8 = (longlong *)0x0;
            }
LAB_23e7e605d:
            pcVar17 = *(code **)(param_1 + 0x60);
            plVar12 = *(longlong **)(param_1 + 0x70);
            *(undefined8 *)(param_1 + 0x70) = 0;
            uVar20 = 0x5b;
            *(undefined1 (*) [16])(param_1 + 0x60) = (undefined1  [16])0x0;
            plVar11 = plVar22;
            uVar25 = *(undefined8 *)(param_1 + 0x68);
          }
LAB_23e7e570b:
          aplStack_98[0] = (longlong *)0x0;
          auStack_a8 = (undefined1  [16])0x0;
          lVar13 = *plStack_c0;
          *plStack_c0 = lVar13 + -1;
          plVar22 = plVar11;
          if (lVar13 + -1 == 0) {
            (**(code **)(plStack_c0[1] + 0x30))(plStack_c0);
          }
        }
        else {
          plVar15 = (longlong *)0x0;
          plVar22 = (longlong *)0x0;
          plStack_f8 = (longlong *)0x0;
          plStack_d8 = (longlong *)0x0;
LAB_23e7e4e4a:
          lVar13 = plVar10[1];
          if (*(code **)(lVar13 + 0xe0) != (code *)0x0) {
            plStack_c0 = (longlong *)(**(code **)(lVar13 + 0xe0))();
            if (plStack_c0 != (longlong *)0x0) {
              if ((plVar9 != (longlong *)0x0) && (*plVar9 = *plVar9 + -1, *plVar9 == 0)) {
                (**(code **)(plVar9[1] + 0x30))(plVar9);
              }
              plVar9 = (longlong *)FUN_23a388310(plStack_c0);
              if (plVar9 != (longlong *)0x0) {
                plVar11 = (longlong *)(**(code **)(plVar9[1] + 0xe0))(plVar9);
                if ((plVar11 == (longlong *)0x0) &&
                   (plVar11 = (longlong *)FUN_23a3c1b70(param_1,auStack_a8,0,2),
                   plVar11 == (longlong *)0x0)) {
                  plStack_e8 = (longlong *)0x0;
                }
                else {
                  puStack_b8 = auStack_a8;
                  plVar12 = (longlong *)(**(code **)(plVar9[1] + 0xe0))(plVar9);
                  if ((plVar12 != (longlong *)0x0) ||
                     (plVar12 = (longlong *)FUN_23a3c1b70(param_1,puStack_b8,1,2),
                     plStack_e8 = plVar12, plVar12 != (longlong *)0x0)) {
                    cVar6 = FUN_23a3884a0(param_1,puStack_b8,plVar9,2);
                    lVar13 = *plVar9;
                    plStack_e8 = plVar12;
                    if (cVar6 != '\0') {
                      *plVar9 = lVar13 + -1;
                      if (lVar13 + -1 == 0) {
                        (**(code **)(plVar9[1] + 0x30))(plVar9);
                      }
                      lVar13 = *plVar11;
                      *plVar11 = lVar13 + 1;
                      if (plVar22 != (longlong *)0x0) {
                        *plVar22 = *plVar22 + -1;
                        plVar9 = plVar23;
                        if (*plVar22 != 0) goto LAB_23e7e5858;
                        (**(code **)(plVar22[1] + 0x30))(plVar22);
                        lVar13 = *plVar11 + -1;
                      }
                      while( true ) {
                        plVar22 = plVar11;
                        *plVar22 = lVar13;
                        if (lVar13 == 0) {
                          (**(code **)(plVar22[1] + 0x30))(plVar22);
                        }
                        lVar13 = *plStack_e8;
                        *plStack_e8 = lVar13 + 1;
                        if (plStack_d8 != (longlong *)0x0) {
                          *plStack_d8 = *plStack_d8 + -1;
                          if (*plStack_d8 == 0) {
                            (**(code **)(plStack_d8[1] + 0x30))(plStack_d8);
                            lVar13 = *plStack_e8 + -1;
                          }
                          else {
                            lVar13 = *plStack_e8 + -1;
                          }
                        }
                        *plStack_e8 = lVar13;
                        if (lVar13 == 0) {
                          (**(code **)(plStack_e8[1] + 0x30))(plStack_e8);
                        }
                        if (plVar3 == (longlong *)0x0) break;
                        plVar9 = (longlong *)FUN_23e97e310(param_1,DAT_23ed6ccf0,plStack_e8,plVar3);
                        if (plVar9 == (longlong *)0x0) goto LAB_23e7e605d;
                        plStack_d8 = (longlong *)FUN_23ebf7180(plVar9);
                        *plVar9 = *plVar9 + -1;
                        if (*plVar9 == 0) {
                          (**(code **)(plVar9[1] + 0x30))(plVar9);
                        }
                        if (plStack_d8 == (longlong *)0x0) goto LAB_23e7e605d;
                        plVar12 = plStack_e8;
                        plVar21 = (longlong *)0x0;
                        plVar9 = plStack_f8;
                        plVar11 = plVar22;
LAB_23e7e501c:
                        plVar14 = (longlong *)(**(code **)(plStack_d8[1] + 0xe0))(plStack_d8);
                        plStack_b0 = plStack_d8;
                        if (plVar14 == (longlong *)0x0) {
                          cVar6 = FUN_23a3591a0(param_1,*(undefined8 *)PyExc_StopIteration_exref);
                          if (cVar6 == '\0') {
                            pcVar17 = *(code **)(param_1 + 0x60);
                            uVar25 = *(undefined8 *)(param_1 + 0x68);
                            uVar20 = 0x5b;
                            plVar12 = *(longlong **)(param_1 + 0x70);
                            aplStack_98[0] = (longlong *)0x0;
                            *(undefined8 *)(param_1 + 0x70) = 0;
                            *(undefined1 (*) [16])(param_1 + 0x60) = (undefined1  [16])0x0;
                            auStack_a8 = (undefined1  [16])0x0;
                            plVar11 = plVar22;
                            plStack_f8 = plVar9;
                            if (plVar21 != (longlong *)0x0) goto LAB_23e7e56c0;
                            goto LAB_23e7e56d0;
                          }
                          plVar14 = plVar15;
                          plStack_f8 = plVar9;
                          if (plVar21 != (longlong *)0x0) {
LAB_23e7e5fd2:
                            *plVar21 = *plVar21 + -1;
                            plVar15 = plVar14;
                            if (*plVar21 == 0) {
                              (**(code **)(plVar21[1] + 0x30))(plVar21);
                            }
                          }
                          *plStack_d8 = *plStack_d8 + -1;
                          if (*plStack_d8 == 0) {
                            (**(code **)(plStack_d8[1] + 0x30))(plStack_d8);
                          }
                          lVar13 = *(longlong *)(param_1 + 0x10);
                          if ((((*(int *)(*(longlong *)(lVar13 + 0x28) + 0x160) != 0) ||
                               (*(int *)(lVar13 + 0x78) != 0)) &&
                              (iVar7 = Py_MakePendingCalls(), iVar7 < 0)) &&
                             (*(longlong *)(param_1 + 0x60) != 0)) goto LAB_23e7e6331;
                          if (*(int *)(lVar13 + 0x68) == 0) {
                            plVar11 = *(longlong **)(param_1 + 0x90);
                          }
                          else {
                            PyEval_SaveThread();
                            PyEval_AcquireThread(param_1);
                            plVar11 = *(longlong **)(param_1 + 0x90);
                          }
                          plVar9 = plStack_c0;
                          plStack_d8 = plStack_e8;
                          if (plVar11 != (longlong *)0x0) goto LAB_23e7e62c4;
                          goto LAB_23e7e4e4a;
                        }
                        if ((plVar21 != (longlong *)0x0) &&
                           (*plVar21 = *plVar21 + -1, *plVar21 == 0)) {
                          (**(code **)(plVar21[1] + 0x30))(plVar21);
                        }
                        *plVar14 = *plVar14 + 1;
                        if ((plVar15 != (longlong *)0x0) &&
                           (*plVar15 = *plVar15 + -1, *plVar15 == 0)) {
                          (**(code **)(plVar15[1] + 0x30))(plVar15);
                        }
                        lVar13 = FUN_23e8dd7c0();
                        plVar15 = plVar14;
                        if (lVar13 == 0) goto LAB_23e7e58f2;
                        plVar15 = (longlong *)FUN_23e8c09e0(plVar22,plVar14);
                        plVar21 = plVar14;
                        if (plVar15 == (longlong *)0x0) {
LAB_23e7e5dd8:
                          pcVar17 = *(code **)(param_1 + 0x60);
                          uVar20 = 0x5c;
                          plVar12 = *(longlong **)(param_1 + 0x70);
                          *(undefined8 *)(param_1 + 0x70) = 0;
                          *(undefined1 (*) [16])(param_1 + 0x60) = (undefined1  [16])0x0;
                          plVar15 = plVar14;
                          uVar25 = *(undefined8 *)(param_1 + 0x68);
                          plStack_f8 = plVar9;
                          goto LAB_23e7e56c0;
                        }
                        plVar16 = (longlong *)FUN_23a37a020(DAT_23ed6ccc0,DAT_23eeddd00);
                        if (plVar16 != (longlong *)0x0) {
                          lVar19 = *plVar16;
                          plVar11 = (longlong *)0x0;
                          if (lVar19 != 0) {
                            plVar12 = (longlong *)FUN_23e8c6640(plStack_e8,plVar14);
                            if (plVar12 == (longlong *)0x0) {
LAB_23e7e5ed8:
                              auStack_a8._0_8_ = *(undefined8 *)(param_1 + 0x60);
                              auStack_a8._8_8_ = *(undefined8 *)(param_1 + 0x68);
                              aplStack_98[0] = *(longlong **)(param_1 + 0x70);
                              *(undefined1 (*) [16])(param_1 + 0x60) = (undefined1  [16])0x0;
                              *(undefined8 *)(param_1 + 0x70) = 0;
                              *plVar15 = *plVar15 + -1;
                              if (*plVar15 == 0) {
                                uVar20 = 0x5c;
                                (**(code **)(plVar15[1] + 0x30))(plVar15);
                                plVar15 = plVar14;
                                plVar12 = aplStack_98[0];
                                pcVar17 = (code *)auStack_a8._0_8_;
                                uVar25 = auStack_a8._8_8_;
                                plStack_f8 = plVar9;
                              }
                              else {
                                uVar20 = 0x5c;
                                plVar15 = plVar14;
                                plVar12 = aplStack_98[0];
                                pcVar17 = (code *)auStack_a8._0_8_;
                                uVar25 = auStack_a8._8_8_;
                                plStack_f8 = plVar9;
                              }
                            }
                            else {
                              *(undefined4 *)(plVar8 + 5) = 0x5c;
                              plStack_88 = plVar3;
                              plStack_80 = plVar12;
                              plVar11 = (longlong *)FUN_23e94ed00(param_1,lVar19,&plStack_88);
                              *plVar12 = *plVar12 + -1;
                              if (*plVar12 == 0) {
                                (**(code **)(plVar12[1] + 0x30))(plVar12);
                              }
                              if (plVar11 == (longlong *)0x0) goto LAB_23e7e5ed8;
                              *(undefined4 *)(plVar8 + 5) = 0x5c;
                              plStack_88 = plVar23;
                              plStack_80 = plVar15;
                              plStack_78 = plVar11;
                              plVar16 = (longlong *)FUN_23e956150(param_1,lVar13,&plStack_88);
                              *plVar15 = *plVar15 + -1;
                              if (*plVar15 == 0) {
                                (**(code **)(plVar15[1] + 0x30))(plVar15);
                              }
                              *plVar11 = *plVar11 + -1;
                              if (*plVar11 == 0) {
                                (**(code **)(plVar11[1] + 0x30))(plVar11);
                              }
                              if (plVar16 == (longlong *)0x0) goto LAB_23e7e5dd8;
                              if ((plVar9 != (longlong *)0x0) &&
                                 (*plVar9 = *plVar9 + -1, *plVar9 == 0)) {
                                (**(code **)(plVar9[1] + 0x30))(plVar9);
                              }
                              iVar7 = PySequence_Contains(plVar16,plVar2);
                              if (iVar7 == -1) {
                                pcVar17 = *(code **)(param_1 + 0x60);
                                uVar20 = 0x5d;
                                plVar12 = *(longlong **)(param_1 + 0x70);
                                *(undefined8 *)(param_1 + 0x70) = 0;
                                *(undefined1 (*) [16])(param_1 + 0x60) = (undefined1  [16])0x0;
                                plVar15 = plVar14;
                                uVar25 = *(undefined8 *)(param_1 + 0x68);
                                plStack_f8 = plVar16;
                              }
                              else {
                                if (iVar7 != 1) {
                                  lVar13 = *(longlong *)(param_1 + 0x10);
                                  if ((((*(int *)(*(longlong *)(lVar13 + 0x28) + 0x160) == 0) &&
                                       (*(int *)(lVar13 + 0x78) == 0)) ||
                                      (iVar7 = Py_MakePendingCalls(), -1 < iVar7)) ||
                                     (pcVar17 = *(code **)(param_1 + 0x60), pcVar17 == (code *)0x0))
                                  goto LAB_23e7e51fb;
                                  goto LAB_23e7e567d;
                                }
                                plVar9 = (longlong *)FUN_23e8bc2f0(plVar18,_DAT_23eeddd18);
                                if (plVar9 != (longlong *)0x0) {
                                  lVar13 = *(longlong *)(param_1 + 0x10);
                                  plVar15 = *(longlong **)(lVar13 + 0xe20);
                                  if (plVar15 == (longlong *)0x0) {
                                    plVar15 = (longlong *)FUN_23e916a20(PyTuple_Type_exref,2);
                                  }
                                  else {
                                    lVar19 = plVar15[3];
                                    *(int *)(lVar13 + 0xebc) = *(int *)(lVar13 + 0xebc) + -1;
                                    *(longlong *)(lVar13 + 0xe20) = lVar19;
                                    *plVar15 = 1;
                                  }
                                  lVar13 = *(longlong *)
                                            (*(longlong *)
                                              (*(longlong *)(_PyRuntime_exref + 0x1f8) + 0x10) +
                                            0x2e8);
                                  lVar19 = plVar15[-1];
                                  puVar4 = *(undefined8 **)(lVar13 + 8);
                                  *puVar4 = plVar15 + -2;
                                  plVar15[-2] = lVar13;
                                  plVar15[-1] = (ulonglong)((uint)lVar19 & 3) | (ulonglong)puVar4;
                                  *(longlong **)(lVar13 + 8) = plVar15 + -2;
                                  *plVar22 = *plVar22 + 1;
                                  plVar15[3] = (longlong)plVar22;
                                  *plStack_e8 = *plStack_e8 + 1;
                                  plVar15[4] = (longlong)plStack_e8;
                                  *(undefined4 *)(plVar8 + 5) = 0x5e;
                                  plVar11 = (longlong *)FUN_23e914090(param_1,plVar9,plVar15);
                                  *plVar9 = *plVar9 + -1;
                                  if (*plVar9 == 0) {
                                    (**(code **)(plVar9[1] + 0x30))(plVar9);
                                  }
                                  *plVar15 = *plVar15 + -1;
                                  if (*plVar15 == 0) {
                                    (**(code **)(plVar15[1] + 0x30))(plVar15);
                                  }
                                  if (plVar11 != (longlong *)0x0) {
                                    *plVar11 = *plVar11 + -1;
                                    plStack_f8 = plVar16;
                                    if (*plVar11 == 0) {
                                      (**(code **)(plVar11[1] + 0x30))(plVar11);
                                    }
                                    goto LAB_23e7e5fd2;
                                  }
                                }
                                pcVar17 = *(code **)(param_1 + 0x60);
                                plVar12 = *(longlong **)(param_1 + 0x70);
                                uVar20 = 0x5e;
                                *(undefined8 *)(param_1 + 0x70) = 0;
                                *(undefined1 (*) [16])(param_1 + 0x60) = (undefined1  [16])0x0;
                                plVar15 = plVar14;
                                uVar25 = *(undefined8 *)(param_1 + 0x68);
                                plStack_f8 = plVar16;
                              }
                            }
                            goto LAB_23e7e56c0;
                          }
                        }
                        PyErr_PrintEx(0);
                        Py_Exit(1);
LAB_23e7e5858:
                        lVar13 = *plVar11 + -1;
                        plStack_e8 = plVar12;
                        plVar23 = plVar9;
                      }
                      goto LAB_23e7e6693;
                    }
                  }
                }
                goto LAB_23e7e5bd9;
              }
              goto LAB_23e7e6380;
            }
            goto LAB_23e7e59e8;
          }
LAB_23e7e59cd:
          PyErr_Format(*(undefined8 *)PyExc_TypeError_exref,"\'%s\' object is not an iterator",
                       *(undefined8 *)(lVar13 + 0x18));
LAB_23e7e59e8:
          cVar6 = FUN_23a3591a0(param_1,*(undefined8 *)PyExc_StopIteration_exref);
          if (cVar6 != '\0') {
            if ((plVar9 != (longlong *)0x0) && (*plVar9 = *plVar9 + -1, *plVar9 == 0)) {
              (**(code **)(plVar9[1] + 0x30))(plVar9);
            }
            lVar13 = *plVar10;
            *plVar10 = lVar13 + -1;
            if (lVar13 + -1 == 0) {
              (**(code **)(plVar10[1] + 0x30))(plVar10);
            }
            *plVar18 = *plVar18 + 1;
            lVar13 = *(longlong *)(*(longlong *)(param_1 + 0x38) + 8);
            plVar8 = *(longlong **)(lVar13 + 0x28);
            plVar9 = (longlong *)plVar8[2];
            *(undefined8 *)(*(longlong *)(param_1 + 0x38) + 8) = *(undefined8 *)(lVar13 + 0x30);
            *(undefined4 *)(plVar8 + 8) = 0xffffffff;
            if (plVar9 != (longlong *)0x0) {
              plVar8[2] = 0;
              *plVar9 = *plVar9 + -1;
              if (*plVar9 == 0) {
                (**(code **)(plVar9[1] + 0x30))();
              }
            }
            *plVar8 = *plVar8 + -1;
            if (*plVar8 == 0) {
              (**(code **)(plVar8[1] + 0x30))(plVar8);
            }
            plVar8[0xf] = 0;
            lVar13 = *plVar18;
            *plVar18 = lVar13 + -1;
            if (lVar13 + -1 == 0) {
              (**(code **)(plVar18[1] + 0x30))(plVar18);
            }
            if ((plVar22 != (longlong *)0x0) && (*plVar22 = *plVar22 + -1, *plVar22 == 0)) {
              (**(code **)(plVar22[1] + 0x30))(plVar22);
            }
            if ((plStack_d8 != (longlong *)0x0) &&
               (lVar13 = *plStack_d8, *plStack_d8 = lVar13 + -1, lVar13 + -1 == 0)) {
              (**(code **)(plStack_d8[1] + 0x30))(plStack_d8);
            }
            if ((plVar15 != (longlong *)0x0) && (*plVar15 = *plVar15 + -1, *plVar15 == 0)) {
              (**(code **)(plVar15[1] + 0x30))(plVar15);
            }
            if ((plStack_f8 != (longlong *)0x0) &&
               (lVar13 = *plStack_f8, *plStack_f8 = lVar13 + -1, lVar13 + -1 == 0)) {
              (**(code **)(plStack_f8[1] + 0x30))(plStack_f8);
            }
            *plVar23 = *plVar23 + -1;
            if (*plVar23 == 0) {
              (**(code **)(plVar23[1] + 0x30))(plVar23);
            }
            lVar13 = *plVar2;
            *plVar2 = lVar13 + -1;
            if (lVar13 + -1 == 0) {
              (**(code **)(plVar2[1] + 0x30))(plVar2);
            }
            lVar13 = *plVar3;
            *plVar3 = lVar13 + -1;
            if (lVar13 + -1 != 0) {
              return plVar18;
            }
            (**(code **)(plVar3[1] + 0x30))(plVar3);
            return plVar18;
          }
          plVar12 = *(longlong **)(param_1 + 0x70);
          pcVar17 = *(code **)(param_1 + 0x60);
          uVar25 = *(undefined8 *)(param_1 + 0x68);
          *(undefined8 *)(param_1 + 0x70) = 0;
          aplStack_98[0] = (longlong *)0x0;
          *(undefined1 (*) [16])(param_1 + 0x60) = (undefined1  [16])0x0;
          auStack_a8 = (undefined1  [16])0x0;
          plStack_e8 = plStack_d8;
          if (plVar9 != (longlong *)0x0) {
            uVar20 = 0x5a;
            plVar11 = plVar22;
            plStack_c0 = plVar9;
            goto LAB_23e7e570b;
          }
          uVar20 = 0x5a;
        }
        lVar13 = *plVar10;
        *plVar10 = lVar13 + -1;
        if (lVar13 + -1 == 0) {
          (**(code **)(plVar10[1] + 0x30))(plVar10);
        }
        auStack_a8._8_8_ = uVar25;
        auStack_a8._0_8_ = pcVar17;
        plVar9 = DAT_23ed6a4f8;
        goto joined_r0x00023e7e5764;
      }
      auStack_a8 = *(undefined1 (*) [16])(param_1 + 0x60);
      aplStack_98[0] = *(longlong **)(param_1 + 0x70);
      *(undefined8 *)(param_1 + 0x70) = 0;
      *(undefined1 (*) [16])(param_1 + 0x60) = (undefined1  [16])0x0;
    }
  }
  else {
    iVar7 = *(int *)(lVar13 + 0xc);
    if (*(int *)(lVar13 + 0xc) == 0) {
      *(int *)(lVar13 + 0xc) = DAT_23ec15618;
      iVar7 = DAT_23ec15618;
      DAT_23ec15618 = DAT_23ec15618 + 1;
    }
    if (_DAT_23ec15600 != iVar7) {
      _DAT_23ec15600 = iVar7;
      _DAT_23eedeb40 = FUN_23e8cbd60(lVar13,_DAT_23eeddce0,*(undefined8 *)(_DAT_23eeddce0 + 0x18));
    }
    if (-1 < _DAT_23eedeb40) {
      lVar1 = lVar13 + 0x20 + (1L << (*(byte *)(lVar13 + 9) & 0x3f));
      lVar19 = *(longlong *)(lVar1 + 8 + _DAT_23eedeb40 * 0x10);
      if (lVar19 != 0) goto LAB_23e7e4dbc;
      _DAT_23eedeb40 = FUN_23e8cbd60(lVar13,_DAT_23eeddce0,*(undefined8 *)(_DAT_23eeddce0 + 0x18));
      if (-1 < _DAT_23eedeb40) {
        lVar19 = *(longlong *)(lVar1 + 8 + _DAT_23eedeb40 * 0x10);
        goto LAB_23e7e59a8;
      }
    }
LAB_23e7e5251:
    plVar9 = (longlong *)FUN_23a37a020(DAT_23ed6ccc0,_DAT_23eeddce0);
    if ((plVar9 != (longlong *)0x0) && (lVar19 = *plVar9, lVar19 != 0)) goto LAB_23e7e4dbc;
    FUN_23e915740(param_1,auStack_a8,_DAT_23eeddce0);
  }
  plVar22 = (longlong *)0x0;
  plStack_e8 = (longlong *)0x0;
  plStack_f8 = (longlong *)0x0;
  plVar15 = (longlong *)0x0;
  uVar20 = 0x5a;
  plVar12 = aplStack_98[0];
  plVar9 = DAT_23ed6a4f8;
joined_r0x00023e7e5764:
  DAT_23ed6a4f8 = plVar9;
  aplStack_98[0] = plVar12;
  if (plVar12 == (longlong *)0x0) {
    if (plVar9 == (longlong *)0x0) {
      plVar9 = (longlong *)FUN_23a33a530(PyTraceBack_Type_exref);
    }
    else {
      DAT_23ed6a4f8 = (longlong *)*plVar9;
      *plVar9 = 1;
      DAT_23ed6a4f0 = DAT_23ed6a4f0 + -1;
    }
    pcVar17 = _PyRuntime_exref;
    plVar9[3] = (longlong)plVar8;
    plVar9[2] = 0;
    *plVar8 = *plVar8 + 1;
    lVar13 = *(longlong *)(pcVar17 + 0x1f8);
    *(undefined4 *)(plVar9 + 4) = 0xffffffff;
    lVar13 = *(longlong *)(lVar13 + 0x10);
    *(undefined4 *)((longlong)plVar9 + 0x24) = uVar20;
    lVar13 = *(longlong *)(lVar13 + 0x2e8);
    lVar19 = plVar9[-1];
    puVar4 = *(undefined8 **)(lVar13 + 8);
    *puVar4 = plVar9 + -2;
    plVar9[-2] = lVar13;
    plVar9[-1] = (ulonglong)((uint)lVar19 & 3) | (ulonglong)puVar4;
    *(longlong **)(lVar13 + 8) = plVar9 + -2;
    plVar12 = plVar9;
    if ((aplStack_98[0] != (longlong *)0x0) &&
       (*aplStack_98[0] = *aplStack_98[0] + -1, *aplStack_98[0] == 0)) {
      (**(code **)(aplStack_98[0][1] + 0x30))(aplStack_98[0]);
    }
  }
  else if ((longlong *)plVar12[3] != plVar8) {
    if (plVar9 == (longlong *)0x0) {
      plVar9 = (longlong *)FUN_23a33a530(PyTraceBack_Type_exref);
    }
    else {
      DAT_23ed6a4f8 = (longlong *)*plVar9;
      *plVar9 = 1;
      DAT_23ed6a4f0 = DAT_23ed6a4f0 + -1;
    }
    pcVar17 = _PyRuntime_exref;
    plVar9[3] = (longlong)plVar8;
    *plVar8 = *plVar8 + 1;
    lVar13 = *(longlong *)(pcVar17 + 0x1f8);
    *(undefined4 *)((longlong)plVar9 + 0x24) = uVar20;
    *(undefined4 *)(plVar9 + 4) = 0xffffffff;
    lVar13 = *(longlong *)(*(longlong *)(lVar13 + 0x10) + 0x2e8);
    lVar19 = plVar9[-1];
    puVar4 = *(undefined8 **)(lVar13 + 8);
    *puVar4 = plVar9 + -2;
    plVar9[-2] = lVar13;
    plVar9[-1] = (ulonglong)((uint)lVar19 & 3) | (ulonglong)puVar4;
    *(longlong **)(lVar13 + 8) = plVar9 + -2;
    plVar9[2] = (longlong)plVar12;
    *plVar12 = *plVar12 + 1;
    plVar12 = plVar9;
    if ((aplStack_98[0] != (longlong *)0x0) &&
       (*aplStack_98[0] = *aplStack_98[0] + -1, *aplStack_98[0] == 0)) {
      (**(code **)(aplStack_98[0][1] + 0x30))();
    }
  }
  aplStack_98[0] = plVar12;
  FUN_23e8bba40(plVar8,"oooooooo",plVar23,plVar2,plVar3,plVar18,plVar22,plStack_e8,plVar15,
                plStack_f8);
  if (_DAT_23eedeb50 == plVar8) {
    *plVar8 = *plVar8 + -1;
    if (*plVar8 == 0) {
      (**(code **)(plVar8[1] + 0x30))(plVar8);
    }
    _DAT_23eedeb50 = (longlong *)0x0;
  }
  lVar13 = *(longlong *)(*(longlong *)(param_1 + 0x38) + 8);
  plVar8 = *(longlong **)(lVar13 + 0x28);
  plVar9 = (longlong *)plVar8[2];
  *(undefined8 *)(*(longlong *)(param_1 + 0x38) + 8) = *(undefined8 *)(lVar13 + 0x30);
  *(undefined4 *)(plVar8 + 8) = 0xffffffff;
  if (plVar9 != (longlong *)0x0) {
    plVar8[2] = 0;
    *plVar9 = *plVar9 + -1;
    if (*plVar9 == 0) {
      (**(code **)(plVar9[1] + 0x30))();
    }
  }
  *plVar8 = *plVar8 + -1;
  if (*plVar8 == 0) {
    (**(code **)(plVar8[1] + 0x30))(plVar8);
    plVar8[0xf] = 0;
    plVar8 = aplStack_98[0];
    uVar25 = auStack_a8._0_8_;
    uVar24 = auStack_a8._8_8_;
  }
  else {
    plVar8[0xf] = 0;
    plVar8 = aplStack_98[0];
    uVar25 = auStack_a8._0_8_;
    uVar24 = auStack_a8._8_8_;
  }
  aplStack_98[0] = (longlong *)0x0;
  auStack_a8 = (undefined1  [16])0x0;
  lVar13 = *plVar18;
  *plVar18 = lVar13 + -1;
  if (lVar13 + -1 == 0) {
    (**(code **)(plVar18[1] + 0x30))(plVar18);
  }
  if ((plVar22 != (longlong *)0x0) && (*plVar22 = *plVar22 + -1, *plVar22 == 0)) {
    (**(code **)(plVar22[1] + 0x30))(plVar22);
  }
  if ((plStack_e8 != (longlong *)0x0) &&
     (lVar13 = *plStack_e8, *plStack_e8 = lVar13 + -1, lVar13 + -1 == 0)) {
    (**(code **)(plStack_e8[1] + 0x30))(plStack_e8);
  }
  if ((plVar15 != (longlong *)0x0) && (*plVar15 = *plVar15 + -1, *plVar15 == 0)) {
    (**(code **)(plVar15[1] + 0x30))(plVar15);
  }
  if ((plStack_f8 != (longlong *)0x0) &&
     (lVar13 = *plStack_f8, *plStack_f8 = lVar13 + -1, lVar13 + -1 == 0)) {
    (**(code **)(plStack_f8[1] + 0x30))();
  }
  auStack_a8._8_8_ = uVar24;
  auStack_a8._0_8_ = uVar25;
  *plVar23 = *plVar23 + -1;
  aplStack_98[0] = plVar8;
  if (*plVar23 == 0) {
    (**(code **)(plVar23[1] + 0x30))(plVar23);
  }
  lVar13 = *plVar2;
  *plVar2 = lVar13 + -1;
  if (lVar13 + -1 == 0) {
    (**(code **)(plVar2[1] + 0x30))(plVar2);
  }
  lVar13 = *plVar3;
  *plVar3 = lVar13 + -1;
  if (lVar13 + -1 == 0) {
    (**(code **)(plVar3[1] + 0x30))(plVar3);
  }
  FUN_23a33aa70(param_1,auStack_a8._0_8_,auStack_a8._8_8_,aplStack_98[0]);
  return (longlong *)0x0;
LAB_23e7e51fb:
  plVar12 = (longlong *)(ulonglong)*(uint *)(lVar13 + 0x68);
  if (*(uint *)(lVar13 + 0x68) == 0) {
    plVar5 = *(longlong **)(param_1 + 0x90);
  }
  else {
    PyEval_SaveThread();
    PyEval_AcquireThread(param_1);
    plVar5 = *(longlong **)(param_1 + 0x90);
  }
  plVar15 = plVar14;
  plVar9 = plVar16;
  if (plVar5 != (longlong *)0x0) {
    plVar9 = *(longlong **)(param_1 + 0x60);
    plVar15 = *(longlong **)(param_1 + 0x70);
    plVar11 = *(longlong **)(param_1 + 0x68);
    *(undefined8 *)(param_1 + 0x90) = 0;
    *(longlong **)(param_1 + 0x60) = plVar5;
    *plVar5 = *plVar5 + 1;
    *(undefined8 *)(param_1 + 0x68) = 0;
    *(undefined8 *)(param_1 + 0x70) = 0;
    if ((plVar9 != (longlong *)0x0) && (*plVar9 = *plVar9 + -1, *plVar9 == 0)) {
      (**(code **)(plVar9[1] + 0x30))();
    }
    if ((plVar11 != (longlong *)0x0) && (*plVar11 = *plVar11 + -1, *plVar11 == 0)) {
      (**(code **)(plVar11[1] + 0x30))(plVar11);
    }
    if ((plVar15 != (longlong *)0x0) && (*plVar15 = *plVar15 + -1, *plVar15 == 0)) {
      (**(code **)(plVar15[1] + 0x30))(plVar15);
    }
    pcVar17 = *(code **)(param_1 + 0x60);
LAB_23e7e567d:
    plVar12 = *(longlong **)(param_1 + 0x70);
    *(undefined8 *)(param_1 + 0x70) = 0;
    uVar20 = 0x5b;
    *(undefined1 (*) [16])(param_1 + 0x60) = (undefined1  [16])0x0;
    plVar15 = plVar14;
    uVar25 = *(undefined8 *)(param_1 + 0x68);
    plStack_f8 = plVar16;
    goto LAB_23e7e56c0;
  }
  goto LAB_23e7e501c;
LAB_23e7e6921:
  if (*(int *)(lVar13 + 0x68) == 0) {
    plVar11 = *(longlong **)(param_1 + 0x90);
  }
  else {
    PyEval_SaveThread();
    PyEval_AcquireThread(param_1);
    plVar11 = *(longlong **)(param_1 + 0x90);
  }
  plVar9 = plStack_c0;
  plStack_d8 = plStack_e8;
  if (plVar11 != (longlong *)0x0) goto LAB_23e7e6a42;
  goto LAB_23e7e63cb;
LAB_23e7e6a42:
  plVar15 = (longlong *)0x0;
  plStack_f8 = (longlong *)0x0;
LAB_23e7e62c4:
  plVar9 = *(longlong **)(param_1 + 0x60);
  plVar12 = *(longlong **)(param_1 + 0x68);
  *(undefined8 *)(param_1 + 0x90) = 0;
  plVar21 = *(longlong **)(param_1 + 0x70);
  *(longlong **)(param_1 + 0x60) = plVar11;
  *plVar11 = *plVar11 + 1;
  *(undefined8 *)(param_1 + 0x68) = 0;
  *(undefined8 *)(param_1 + 0x70) = 0;
  if ((plVar9 != (longlong *)0x0) && (*plVar9 = *plVar9 + -1, *plVar9 == 0)) {
    (**(code **)(plVar9[1] + 0x30))();
  }
  if ((plVar12 != (longlong *)0x0) && (*plVar12 = *plVar12 + -1, *plVar12 == 0)) {
    (**(code **)(plVar12[1] + 0x30))(plVar12);
  }
  if ((plVar21 != (longlong *)0x0) && (*plVar21 = *plVar21 + -1, *plVar21 == 0)) {
    (**(code **)(plVar21[1] + 0x30))(plVar21);
  }
LAB_23e7e6331:
  pcVar17 = *(code **)(param_1 + 0x60);
  plVar12 = *(longlong **)(param_1 + 0x70);
  *(undefined8 *)(param_1 + 0x70) = 0;
  uVar20 = 0x5a;
  *(undefined1 (*) [16])(param_1 + 0x60) = (undefined1  [16])0x0;
  plVar11 = plVar22;
  uVar25 = *(undefined8 *)(param_1 + 0x68);
  goto LAB_23e7e570b;
}
