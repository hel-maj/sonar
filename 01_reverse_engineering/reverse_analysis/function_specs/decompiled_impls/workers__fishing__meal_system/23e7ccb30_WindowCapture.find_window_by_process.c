/* ===== 23e7ccb30 workers.fishing.meal_system:47 ===== */
/* ghidra_name=FUN_23e7ccb30 entry=23e7ccb30 size=3969 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

code * FUN_23e7ccb30(longlong param_1,undefined8 param_2,longlong *param_3)

{
  longlong lVar1;
  undefined8 *puVar2;
  undefined8 uVar3;
  undefined1 auVar4 [16];
  char cVar5;
  int iVar6;
  longlong *plVar7;
  longlong *plVar8;
  longlong lVar9;
  longlong *plVar10;
  longlong *plVar11;
  longlong *plVar12;
  longlong *plVar13;
  longlong *plVar14;
  longlong *plVar15;
  longlong *plVar16;
  code *pcVar17;
  longlong *plVar18;
  undefined4 uVar19;
  longlong lVar20;
  longlong *plVar21;
  undefined8 uVar22;
  longlong *plStack_a8;
  longlong *plStack_88;
  longlong *plStack_80;
  undefined1 auStack_78 [16];
  longlong *aplStack_68 [5];
  
  plVar18 = DAT_23ed6a4e0;
  lVar9 = *param_3;
  if (DAT_23ed6a4e0 == (longlong *)0x0) {
    plVar18 = (longlong *)FUN_23a33a530(&DAT_23ec0fb60);
    lVar20 = *plVar18 + 1;
  }
  else {
    lVar20 = 2;
    plVar7 = (longlong *)*DAT_23ed6a4e0;
    *DAT_23ed6a4e0 = 1;
    DAT_23ed6a4e0 = plVar7;
    DAT_23ed6a4d8 = DAT_23ed6a4d8 + -1;
  }
  pcVar17 = _PyRuntime_exref;
  plVar18[2] = lVar9;
  lVar9 = *(longlong *)(*(longlong *)(*(longlong *)(pcVar17 + 0x1f8) + 0x10) + 0x2e8);
  lVar1 = plVar18[-1];
  puVar2 = *(undefined8 **)(lVar9 + 8);
  *puVar2 = plVar18 + -2;
  plVar18[-2] = lVar9;
  plVar18[-1] = (ulonglong)((uint)lVar1 & 3) | (ulonglong)puVar2;
  uVar3 = uRam000000023eed70b8;
  *(longlong **)(lVar9 + 8) = plVar18 + -2;
  uVar22 = uRam000000023eed70b0;
  aplStack_68[0] = (longlong *)0x0;
  auStack_78 = (undefined1  [16])0x0;
  *plVar18 = lVar20;
  plStack_88 = plVar18;
  plVar7 = (longlong *)
           FUN_23e93e1e0(FUN_23e7cdb20,uVar22,uVar3,_DAT_23eeded70,0,0,DAT_23eed7940,0,&plStack_88,1
                        );
  lVar9 = *(longlong *)(param_1 + 0x10);
  if (*(int *)(lVar9 + 0x1188) == 0) {
    plVar16 = (longlong *)FUN_23a33a530(PyList_Type_exref);
  }
  else {
    iVar6 = *(int *)(lVar9 + 0x1188) + -1;
    *(int *)(lVar9 + 0x1188) = iVar6;
    plVar16 = *(longlong **)(lVar9 + 0xf08 + (longlong)iVar6 * 8);
    *plVar16 = 1;
  }
  pcVar17 = _PyRuntime_exref;
  plVar16[2] = 0;
  plVar16[4] = 0;
  plVar8 = _DAT_23eeded80;
  lVar9 = *(longlong *)(pcVar17 + 0x1f8);
  plVar16[3] = 0;
  lVar9 = *(longlong *)(*(longlong *)(lVar9 + 0x10) + 0x2e8);
  lVar20 = plVar16[-1];
  puVar2 = *(undefined8 **)(lVar9 + 8);
  *puVar2 = plVar16 + -2;
  plVar16[-2] = lVar9;
  plVar16[-1] = (ulonglong)((uint)lVar20 & 3) | (ulonglong)puVar2;
  *(longlong **)(lVar9 + 8) = plVar16 + -2;
  if (plVar8 != (longlong *)0x0) {
    lVar9 = *plVar8;
    if (lVar9 < 2) {
      if (plVar8[2] == 0) goto LAB_23e7ccd2b;
      *plVar8 = lVar9 + -1;
      if (lVar9 + -1 == 0) {
        (**(code **)(plVar8[1] + 0x30))(plVar8);
      }
    }
    else {
      *plVar8 = lVar9 + -1;
    }
  }
  plVar8 = (longlong *)FUN_23e91f3b0(param_1,_DAT_23eeded78,DAT_23eed7940,0x28);
  _DAT_23eeded80 = plVar8;
LAB_23e7ccd2b:
  lVar9 = *(longlong *)(param_1 + 0x38);
  lVar20 = *(longlong *)(lVar9 + 8);
  plVar8[0xf] = lVar20;
  *(longlong **)(lVar9 + 8) = plVar8 + 9;
  if ((lVar20 != 0) &&
     (((*(char *)(lVar20 + 0x45) == '\x01' ||
       ((ulonglong)
        (*(longlong *)(lVar20 + 0x20) + 0xb8 +
        (longlong)*(int *)(*(longlong *)(lVar20 + 0x20) + 0xa8) * 2) <=
        *(ulonglong *)(lVar20 + 0x38))) && (plVar8[0xe] != 0)))) {
    plVar10 = *(longlong **)(lVar20 + 0x28);
    *(longlong **)(plVar8[0xe] + 0x10) = plVar10;
    if (plVar10 != (longlong *)0x0) {
      *plVar10 = *plVar10 + 1;
    }
  }
  *plVar8 = *plVar8 + 1;
  *(undefined4 *)(plVar8 + 8) = 0;
  lVar9 = FUN_23e8de4a0();
  if (lVar9 == 0) {
    plVar21 = (longlong *)0x0;
    uVar19 = 0x3d;
    FUN_23e915740(param_1,auStack_78,uRam000000023eed70c0);
    plVar10 = (longlong *)0x0;
  }
  else {
    *(undefined4 *)(plVar8 + 5) = 0x3d;
    plStack_88 = plVar7;
    plStack_80 = plVar16;
    plVar10 = (longlong *)FUN_23e954670(param_1,lVar9,uRam000000023eed70c8,&plStack_88);
    if (plVar10 == (longlong *)0x0) {
      auStack_78 = *(undefined1 (*) [16])(param_1 + 0x60);
      aplStack_68[0] = *(longlong **)(param_1 + 0x70);
      plVar21 = (longlong *)0x0;
      *(undefined8 *)(param_1 + 0x70) = 0;
      uVar19 = 0x3d;
      *(undefined1 (*) [16])(param_1 + 0x60) = (undefined1  [16])0x0;
      plVar10 = (longlong *)0x0;
    }
    else {
      *plVar10 = *plVar10 + -1;
      if (*plVar10 == 0) {
        (**(code **)(plVar10[1] + 0x30))(plVar10);
        iVar6 = FUN_23a35f020(plVar16);
        pcVar17 = _Py_FalseStruct_exref;
      }
      else {
        iVar6 = FUN_23a35f020(plVar16);
        pcVar17 = _Py_FalseStruct_exref;
      }
      _Py_FalseStruct_exref = pcVar17;
      if (iVar6 == 0) {
        plVar15 = (longlong *)0x0;
        plVar14 = (longlong *)0x0;
        *(longlong *)pcVar17 = *(longlong *)pcVar17 + 1;
LAB_23e7cce06:
        lVar9 = *(longlong *)(*(longlong *)(param_1 + 0x38) + 8);
        plVar8 = *(longlong **)(lVar9 + 0x28);
        plVar10 = (longlong *)plVar8[2];
        *(undefined8 *)(*(longlong *)(param_1 + 0x38) + 8) = *(undefined8 *)(lVar9 + 0x30);
        *(undefined4 *)(plVar8 + 8) = 0xffffffff;
        if (plVar10 != (longlong *)0x0) {
          plVar8[2] = 0;
          *plVar10 = *plVar10 + -1;
          if (*plVar10 == 0) {
            (**(code **)(plVar10[1] + 0x30))();
          }
        }
        *plVar8 = *plVar8 + -1;
        if (*plVar8 == 0) {
          (**(code **)(plVar8[1] + 0x30))(plVar8);
        }
        plVar8[0xf] = 0;
        plVar10 = plVar14;
        plVar21 = plVar15;
LAB_23e7cce51:
        *plVar18 = *plVar18 + -1;
        if (*plVar18 == 0) {
          (**(code **)(plVar18[1] + 0x30))(plVar18);
        }
        lVar9 = *plVar7;
        *plVar7 = lVar9 + -1;
        if (lVar9 + -1 == 0) {
          (**(code **)(plVar7[1] + 0x30))(plVar7);
        }
        *plVar16 = *plVar16 + -1;
        if (*plVar16 == 0) {
          (**(code **)(plVar16[1] + 0x30))(plVar16);
        }
        if ((plVar10 != (longlong *)0x0) && (*plVar10 = *plVar10 + -1, *plVar10 == 0)) {
          (**(code **)(plVar10[1] + 0x30))(plVar10);
        }
        if (plVar21 == (longlong *)0x0) {
          return pcVar17;
        }
        *plVar21 = *plVar21 + -1;
        if (*plVar21 != 0) {
          return pcVar17;
        }
        (**(code **)(plVar21[1] + 0x30))(plVar21);
        return pcVar17;
      }
      plVar21 = (longlong *)0x0;
      plVar10 = (longlong *)0x0;
      plVar11 = (longlong *)FUN_23ebf7180(plVar16);
      plStack_a8 = (longlong *)0x0;
      if (plVar11 == (longlong *)0x0) {
        auStack_78 = *(undefined1 (*) [16])(param_1 + 0x60);
        aplStack_68[0] = *(longlong **)(param_1 + 0x70);
        uVar19 = 0x42;
        *(undefined8 *)(param_1 + 0x70) = 0;
        *(undefined1 (*) [16])(param_1 + 0x60) = (undefined1  [16])0x0;
      }
      else {
        do {
          plVar12 = (longlong *)(**(code **)(plVar11[1] + 0xe0))(plVar11);
          if (plVar12 == (longlong *)0x0) {
            cVar5 = FUN_23a3591a0(param_1,*(undefined8 *)PyExc_StopIteration_exref);
            if (cVar5 == '\0') {
              plVar12 = *(longlong **)(param_1 + 0x70);
              pcVar17 = *(code **)(param_1 + 0x60);
              uVar22 = *(undefined8 *)(param_1 + 0x68);
              *(undefined8 *)(param_1 + 0x70) = 0;
              *(undefined1 (*) [16])(param_1 + 0x60) = (undefined1  [16])0x0;
              uVar19 = 0x42;
              aplStack_68[0] = (longlong *)0x0;
              auStack_78 = (undefined1  [16])0x0;
              if (plStack_a8 == (longlong *)0x0) goto LAB_23e7cd22a;
              uVar19 = 0x42;
              goto LAB_23e7cd200;
            }
            lVar9 = *(longlong *)(*(longlong *)(param_1 + 0x38) + 8);
            plVar8 = *(longlong **)(lVar9 + 0x28);
            plVar14 = (longlong *)plVar8[2];
            *(undefined8 *)(*(longlong *)(param_1 + 0x38) + 8) = *(undefined8 *)(lVar9 + 0x30);
            *(undefined4 *)(plVar8 + 8) = 0xffffffff;
            if (plVar14 != (longlong *)0x0) {
              plVar8[2] = 0;
              *plVar14 = *plVar14 + -1;
              if (*plVar14 == 0) {
                (**(code **)(plVar14[1] + 0x30))();
              }
            }
            *plVar8 = *plVar8 + -1;
            if (*plVar8 == 0) {
              (**(code **)(plVar8[1] + 0x30))(plVar8);
            }
            plVar8[0xf] = 0;
            if ((plStack_a8 != (longlong *)0x0) &&
               (*plStack_a8 = *plStack_a8 + -1, *plStack_a8 == 0)) {
              (**(code **)(plStack_a8[1] + 0x30))(plStack_a8);
            }
            lVar9 = *plVar11;
            *plVar11 = lVar9 + -1;
            if (lVar9 + -1 == 0) {
              (**(code **)(plVar11[1] + 0x30))(plVar11);
            }
            pcVar17 = _Py_FalseStruct_exref;
            *(longlong *)_Py_FalseStruct_exref = *(longlong *)_Py_FalseStruct_exref + 1;
            goto LAB_23e7cce51;
          }
          if ((plStack_a8 != (longlong *)0x0) && (*plStack_a8 = *plStack_a8 + -1, *plStack_a8 == 0))
          {
            (**(code **)(plStack_a8[1] + 0x30))(plStack_a8);
          }
          plVar13 = (longlong *)FUN_23a388310(plVar12);
          plStack_a8 = plVar12;
          if (plVar13 == (longlong *)0x0) {
            pcVar17 = *(code **)(param_1 + 0x60);
            uVar22 = *(undefined8 *)(param_1 + 0x68);
            plVar12 = *(longlong **)(param_1 + 0x70);
            *(undefined8 *)(param_1 + 0x70) = 0;
            *(undefined1 (*) [16])(param_1 + 0x60) = (undefined1  [16])0x0;
LAB_23e7cd568:
            uVar19 = 0x42;
            goto LAB_23e7cd200;
          }
          plVar14 = (longlong *)(**(code **)(plVar13[1] + 0xe0))(plVar13);
          if ((plVar14 == (longlong *)0x0) &&
             (plVar14 = (longlong *)FUN_23a3c1b70(param_1,auStack_78,0,2),
             plVar14 == (longlong *)0x0)) {
            plVar15 = (longlong *)0x0;
            lVar9 = *plVar13;
LAB_23e7cd4cc:
            plVar12 = aplStack_68[0];
            pcVar17 = (code *)auStack_78._0_8_;
            uVar22 = auStack_78._8_8_;
            auStack_78 = (undefined1  [16])0x0;
            aplStack_68[0] = (longlong *)0x0;
            *plVar13 = lVar9 + -1;
            if (lVar9 + -1 == 0) {
              (**(code **)(plVar13[1] + 0x30))(plVar13);
            }
            aplStack_68[0] = (longlong *)0x0;
            auStack_78 = (undefined1  [16])0x0;
            if ((plVar14 != (longlong *)0x0) && (*plVar14 = *plVar14 + -1, *plVar14 == 0)) {
              (**(code **)(plVar14[1] + 0x30))(plVar14);
            }
            if ((plVar15 != (longlong *)0x0) && (*plVar15 = *plVar15 + -1, *plVar15 == 0)) {
              (**(code **)(plVar15[1] + 0x30))(plVar15);
            }
            goto LAB_23e7cd568;
          }
          plVar15 = (longlong *)(**(code **)(plVar13[1] + 0xe0))(plVar13);
          if ((plVar15 == (longlong *)0x0) &&
             (plVar15 = (longlong *)FUN_23a3c1b70(param_1,auStack_78,1,2),
             plVar15 == (longlong *)0x0)) {
            lVar9 = *plVar13;
            goto LAB_23e7cd4cc;
          }
          cVar5 = FUN_23a3884a0(param_1,auStack_78,plVar13,2);
          lVar9 = *plVar13;
          if (cVar5 == '\0') goto LAB_23e7cd4cc;
          *plVar13 = lVar9 + -1;
          if (lVar9 + -1 == 0) {
            (**(code **)(plVar13[1] + 0x30))(plVar13);
          }
          lVar9 = *plVar14;
          *plVar14 = lVar9 + 1;
          if (plVar10 != (longlong *)0x0) {
            *plVar10 = *plVar10 + -1;
            if (*plVar10 == 0) {
              (**(code **)(plVar10[1] + 0x30))(plVar10);
            }
            lVar9 = *plVar14 + -1;
          }
          *plVar14 = lVar9;
          if (lVar9 == 0) {
            (**(code **)(plVar14[1] + 0x30))(plVar14);
          }
          lVar9 = *plVar15;
          *plVar15 = lVar9 + 1;
          if (plVar21 != (longlong *)0x0) {
            *plVar21 = *plVar21 + -1;
            if (*plVar21 == 0) {
              (**(code **)(plVar21[1] + 0x30))(plVar21);
            }
            lVar9 = *plVar15 + -1;
          }
          *plVar15 = lVar9;
          if (lVar9 == 0) {
            (**(code **)(plVar15[1] + 0x30))(plVar15);
          }
          iVar6 = FUN_23a35f020(plVar15);
          plVar10 = plVar14;
          plVar21 = plVar15;
          if (iVar6 == -1) {
            plVar12 = *(longlong **)(param_1 + 0x70);
            pcVar17 = *(code **)(param_1 + 0x60);
            uVar22 = *(undefined8 *)(param_1 + 0x68);
            uVar19 = 0x43;
            *(undefined8 *)(param_1 + 0x70) = 0;
            *(undefined1 (*) [16])(param_1 + 0x60) = (undefined1  [16])0x0;
            goto LAB_23e7cd200;
          }
          if (iVar6 != 0) {
            if (plVar18[2] == 0) {
              auStack_78._8_8_ =
                   PyUnicode_FromFormat
                             ("cannot access local variable \'%U\' where it is not associated with a value"
                              ,DAT_23eed70d0);
              auStack_78._0_8_ = *(undefined8 *)PyExc_UnboundLocalError_exref;
              *(longlong *)auStack_78._0_8_ = *(longlong *)auStack_78._0_8_ + 1;
              aplStack_68[0] = (longlong *)0x0;
              if ((code *)auStack_78._0_8_ != _Py_NoneStruct_exref) {
                FUN_23e91b1b0(param_1,auStack_78,auStack_78 + 8,aplStack_68);
              }
              FUN_23ebf6a40(*(undefined8 *)(param_1 + 0x138),auStack_78._8_8_);
              pcVar17 = (code *)auStack_78._0_8_;
              uVar22 = auStack_78._8_8_;
            }
            else {
              cVar5 = FUN_23e8d9ac0(plVar18[2],_DAT_23eed70a8,plVar14);
              pcVar17 = _Py_TrueStruct_exref;
              if (cVar5 != '\0') {
                *(longlong *)_Py_TrueStruct_exref = *(longlong *)_Py_TrueStruct_exref + 1;
                lVar9 = *plVar12;
                *plVar12 = lVar9 + -1;
                if (lVar9 + -1 == 0) {
                  (**(code **)(plVar12[1] + 0x30))(plVar12);
                }
                lVar9 = *plVar11;
                *plVar11 = lVar9 + -1;
                if (lVar9 + -1 == 0) {
                  (**(code **)(plVar11[1] + 0x30))(plVar11);
                }
                goto LAB_23e7cce06;
              }
              aplStack_68[0] = *(longlong **)(param_1 + 0x70);
              *(undefined8 *)(param_1 + 0x70) = 0;
              pcVar17 = *(code **)(param_1 + 0x60);
              *(undefined1 (*) [16])(param_1 + 0x60) = (undefined1  [16])0x0;
              uVar22 = *(undefined8 *)(param_1 + 0x68);
            }
            uVar19 = 0x44;
            plVar12 = aplStack_68[0];
            goto LAB_23e7cd200;
          }
          lVar9 = *(longlong *)(param_1 + 0x10);
          if ((((*(int *)(*(longlong *)(lVar9 + 0x28) + 0x160) != 0) ||
               (*(int *)(lVar9 + 0x78) != 0)) && (iVar6 = Py_MakePendingCalls(), iVar6 < 0)) &&
             (pcVar17 = *(code **)(param_1 + 0x60), pcVar17 != (code *)0x0)) goto LAB_23e7cd1ba;
          if (*(int *)(lVar9 + 0x68) == 0) {
            plVar14 = *(longlong **)(param_1 + 0x90);
          }
          else {
            PyEval_SaveThread();
            PyEval_AcquireThread(param_1);
            plVar14 = *(longlong **)(param_1 + 0x90);
          }
        } while (plVar14 == (longlong *)0x0);
        plVar15 = *(longlong **)(param_1 + 0x60);
        plVar12 = *(longlong **)(param_1 + 0x68);
        *(undefined8 *)(param_1 + 0x90) = 0;
        plVar13 = *(longlong **)(param_1 + 0x70);
        *(longlong **)(param_1 + 0x60) = plVar14;
        *plVar14 = *plVar14 + 1;
        *(undefined8 *)(param_1 + 0x68) = 0;
        *(undefined8 *)(param_1 + 0x70) = 0;
        if ((plVar15 != (longlong *)0x0) && (*plVar15 = *plVar15 + -1, *plVar15 == 0)) {
          (**(code **)(plVar15[1] + 0x30))();
        }
        if ((plVar12 != (longlong *)0x0) && (*plVar12 = *plVar12 + -1, *plVar12 == 0)) {
          (**(code **)(plVar12[1] + 0x30))(plVar12);
        }
        if ((plVar13 != (longlong *)0x0) && (*plVar13 = *plVar13 + -1, *plVar13 == 0)) {
          (**(code **)(plVar13[1] + 0x30))(plVar13);
        }
        pcVar17 = *(code **)(param_1 + 0x60);
LAB_23e7cd1ba:
        plVar12 = *(longlong **)(param_1 + 0x70);
        *(undefined8 *)(param_1 + 0x70) = 0;
        uVar22 = *(undefined8 *)(param_1 + 0x68);
        uVar19 = 0x42;
        *(undefined1 (*) [16])(param_1 + 0x60) = (undefined1  [16])0x0;
LAB_23e7cd200:
        aplStack_68[0] = (longlong *)0x0;
        auStack_78 = (undefined1  [16])0x0;
        lVar9 = *plStack_a8;
        *plStack_a8 = lVar9 + -1;
        if (lVar9 + -1 == 0) {
          (**(code **)(plStack_a8[1] + 0x30))(plStack_a8);
        }
LAB_23e7cd22a:
        lVar9 = *plVar11;
        *plVar11 = lVar9 + -1;
        if (lVar9 + -1 == 0) {
          (**(code **)(plVar11[1] + 0x30))(plVar11);
        }
        auStack_78._8_8_ = uVar22;
        auStack_78._0_8_ = pcVar17;
        aplStack_68[0] = plVar12;
      }
    }
  }
  plVar15 = aplStack_68[0];
  plVar14 = DAT_23ed6a4f8;
  if (aplStack_68[0] == (longlong *)0x0) {
    if (DAT_23ed6a4f8 == (longlong *)0x0) {
      plVar14 = (longlong *)FUN_23a33a530(PyTraceBack_Type_exref);
    }
    else {
      plVar15 = (longlong *)*DAT_23ed6a4f8;
      *DAT_23ed6a4f8 = 1;
      DAT_23ed6a4f8 = plVar15;
      DAT_23ed6a4f0 = DAT_23ed6a4f0 + -1;
    }
    pcVar17 = _PyRuntime_exref;
    plVar14[2] = 0;
    plVar14[3] = (longlong)plVar8;
    *plVar8 = *plVar8 + 1;
    lVar9 = *(longlong *)(pcVar17 + 0x1f8);
    *(undefined4 *)(plVar14 + 4) = 0xffffffff;
    lVar9 = *(longlong *)(lVar9 + 0x10);
    *(undefined4 *)((longlong)plVar14 + 0x24) = uVar19;
    lVar9 = *(longlong *)(lVar9 + 0x2e8);
    lVar20 = plVar14[-1];
    puVar2 = *(undefined8 **)(lVar9 + 8);
    *puVar2 = plVar14 + -2;
    plVar14[-2] = lVar9;
    plVar14[-1] = (ulonglong)((uint)lVar20 & 3) | (ulonglong)puVar2;
    *(longlong **)(lVar9 + 8) = plVar14 + -2;
    plVar15 = plVar14;
    if ((aplStack_68[0] != (longlong *)0x0) &&
       (*aplStack_68[0] = *aplStack_68[0] + -1, *aplStack_68[0] == 0)) {
      (**(code **)(aplStack_68[0][1] + 0x30))(aplStack_68[0]);
    }
  }
  else if ((longlong *)aplStack_68[0][3] != plVar8) {
    if (DAT_23ed6a4f8 == (longlong *)0x0) {
      plVar14 = (longlong *)FUN_23a33a530(PyTraceBack_Type_exref);
    }
    else {
      plVar11 = (longlong *)*DAT_23ed6a4f8;
      *DAT_23ed6a4f8 = 1;
      DAT_23ed6a4f8 = plVar11;
      DAT_23ed6a4f0 = DAT_23ed6a4f0 + -1;
    }
    pcVar17 = _PyRuntime_exref;
    plVar14[3] = (longlong)plVar8;
    *plVar8 = *plVar8 + 1;
    lVar9 = *(longlong *)(pcVar17 + 0x1f8);
    *(undefined4 *)(plVar14 + 4) = 0xffffffff;
    *(undefined4 *)((longlong)plVar14 + 0x24) = uVar19;
    lVar9 = *(longlong *)(*(longlong *)(lVar9 + 0x10) + 0x2e8);
    lVar20 = plVar14[-1];
    puVar2 = *(undefined8 **)(lVar9 + 8);
    *puVar2 = plVar14 + -2;
    plVar14[-2] = lVar9;
    plVar14[-1] = (ulonglong)((uint)lVar20 & 3) | (ulonglong)puVar2;
    *(longlong **)(lVar9 + 8) = plVar14 + -2;
    plVar14[2] = (longlong)plVar15;
    *plVar15 = *plVar15 + 1;
    plVar15 = plVar14;
    if ((aplStack_68[0] != (longlong *)0x0) &&
       (*aplStack_68[0] = *aplStack_68[0] + -1, *aplStack_68[0] == 0)) {
      (**(code **)(aplStack_68[0][1] + 0x30))();
    }
  }
  aplStack_68[0] = plVar15;
  FUN_23e8bba40(plVar8,"coooo",plVar18,plVar7,plVar16,plVar10,plVar21);
  if (_DAT_23eeded80 == plVar8) {
    *plVar8 = *plVar8 + -1;
    if (*plVar8 == 0) {
      (**(code **)(plVar8[1] + 0x30))(plVar8);
    }
    _DAT_23eeded80 = (longlong *)0x0;
  }
  lVar9 = *(longlong *)(*(longlong *)(param_1 + 0x38) + 8);
  plVar8 = *(longlong **)(lVar9 + 0x28);
  plVar14 = (longlong *)plVar8[2];
  *(undefined8 *)(*(longlong *)(param_1 + 0x38) + 8) = *(undefined8 *)(lVar9 + 0x30);
  *(undefined4 *)(plVar8 + 8) = 0xffffffff;
  if (plVar14 != (longlong *)0x0) {
    plVar8[2] = 0;
    *plVar14 = *plVar14 + -1;
    if (*plVar14 == 0) {
      (**(code **)(plVar14[1] + 0x30))();
    }
  }
  *plVar8 = *plVar8 + -1;
  if (*plVar8 == 0) {
    (**(code **)(plVar8[1] + 0x30))(plVar8);
  }
  plVar14 = aplStack_68[0];
  auVar4 = auStack_78;
  plVar8[0xf] = 0;
  uVar22 = auStack_78._0_8_;
  uVar3 = auStack_78._8_8_;
  auStack_78 = (undefined1  [16])0x0;
  aplStack_68[0] = (longlong *)0x0;
  *plVar18 = *plVar18 + -1;
  if (*plVar18 == 0) {
    (**(code **)(plVar18[1] + 0x30))(plVar18);
  }
  lVar9 = *plVar7;
  *plVar7 = lVar9 + -1;
  if (lVar9 + -1 == 0) {
    (**(code **)(plVar7[1] + 0x30))(plVar7);
  }
  *plVar16 = *plVar16 + -1;
  if (*plVar16 == 0) {
    (**(code **)(plVar16[1] + 0x30))(plVar16);
  }
  if ((plVar10 != (longlong *)0x0) && (*plVar10 = *plVar10 + -1, *plVar10 == 0)) {
    (**(code **)(plVar10[1] + 0x30))(plVar10);
  }
  if ((plVar21 != (longlong *)0x0) && (*plVar21 = *plVar21 + -1, *plVar21 == 0)) {
    (**(code **)(plVar21[1] + 0x30))(plVar21);
  }
  auStack_78 = auVar4;
  aplStack_68[0] = plVar14;
  FUN_23a33aa70(param_1,uVar22,uVar3,plVar14);
  return (code *)0x0;
}
