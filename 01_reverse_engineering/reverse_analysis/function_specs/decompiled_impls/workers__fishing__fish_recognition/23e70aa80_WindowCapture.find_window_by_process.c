/* ===== 23e70aa80 workers.fishing.fish_recognition:35 ===== */
/* ghidra_name=FUN_23e70aa80 entry=23e70aa80 size=3953 */

code * FUN_23e70aa80(longlong param_1,undefined8 param_2,longlong *param_3)

{
  longlong lVar1;
  undefined8 *puVar2;
  undefined8 uVar3;
  undefined8 uVar4;
  undefined1 auVar5 [16];
  char cVar6;
  int iVar7;
  longlong *plVar8;
  longlong *plVar9;
  longlong lVar10;
  longlong *plVar11;
  longlong *plVar12;
  longlong *plVar13;
  longlong *plVar14;
  longlong *plVar15;
  longlong *plVar16;
  longlong *plVar17;
  code *pcVar18;
  longlong *plVar19;
  undefined4 uVar20;
  longlong lVar21;
  longlong *plVar22;
  undefined8 uVar23;
  longlong *local_a8;
  longlong *local_88;
  longlong *local_80;
  undefined1 local_78 [16];
  longlong *local_68 [5];
  
  plVar19 = DAT_23ed6a4e0;
  lVar10 = *param_3;
  if (DAT_23ed6a4e0 == (longlong *)0x0) {
    plVar19 = (longlong *)FUN_23a33a530(&DAT_23ec0fb60);
    lVar21 = *plVar19 + 1;
  }
  else {
    lVar21 = 2;
    plVar8 = (longlong *)*DAT_23ed6a4e0;
    *DAT_23ed6a4e0 = 1;
    DAT_23ed6a4e0 = plVar8;
    DAT_23ed6a4d8 = DAT_23ed6a4d8 + -1;
  }
  pcVar18 = _PyRuntime_exref;
  plVar19[2] = lVar10;
  lVar10 = *(longlong *)(*(longlong *)(*(longlong *)(pcVar18 + 0x1f8) + 0x10) + 0x2e8);
  lVar1 = plVar19[-1];
  puVar2 = *(undefined8 **)(lVar10 + 8);
  *puVar2 = plVar19 + -2;
  uVar4 = DAT_23eedb148;
  uVar3 = DAT_23eed9d18;
  plVar19[-2] = lVar10;
  plVar19[-1] = (ulonglong)((uint)lVar1 & 3) | (ulonglong)puVar2;
  *(longlong **)(lVar10 + 8) = plVar19 + -2;
  uVar23 = DAT_23eed9d10;
  local_68[0] = (longlong *)0x0;
  local_78 = (undefined1  [16])0x0;
  *plVar19 = lVar21;
  local_88 = plVar19;
  plVar8 = (longlong *)
           FUN_23e93e1e0(FUN_23e70ba60,uVar23,uVar3,DAT_23eedb128,0,0,uVar4,0,&local_88,1);
  lVar10 = *(longlong *)(param_1 + 0x10);
  if (*(int *)(lVar10 + 0x1188) == 0) {
    plVar17 = (longlong *)FUN_23a33a530(PyList_Type_exref);
  }
  else {
    iVar7 = *(int *)(lVar10 + 0x1188) + -1;
    *(int *)(lVar10 + 0x1188) = iVar7;
    plVar17 = *(longlong **)(lVar10 + 0xf08 + (longlong)iVar7 * 8);
    *plVar17 = 1;
  }
  pcVar18 = _PyRuntime_exref;
  plVar17[2] = 0;
  plVar17[4] = 0;
  plVar9 = DAT_23eedb138;
  lVar10 = *(longlong *)(pcVar18 + 0x1f8);
  plVar17[3] = 0;
  lVar10 = *(longlong *)(*(longlong *)(lVar10 + 0x10) + 0x2e8);
  lVar21 = plVar17[-1];
  puVar2 = *(undefined8 **)(lVar10 + 8);
  *puVar2 = plVar17 + -2;
  plVar17[-2] = lVar10;
  plVar17[-1] = (ulonglong)((uint)lVar21 & 3) | (ulonglong)puVar2;
  *(longlong **)(lVar10 + 8) = plVar17 + -2;
  if (plVar9 != (longlong *)0x0) {
    lVar10 = *plVar9;
    if (lVar10 < 2) {
      if (plVar9[2] == 0) goto LAB_23e70ac7b;
      *plVar9 = lVar10 + -1;
      if (lVar10 + -1 == 0) {
        (**(code **)(plVar9[1] + 0x30))(plVar9);
      }
    }
    else {
      *plVar9 = lVar10 + -1;
    }
  }
  plVar9 = (longlong *)FUN_23e91f3b0(param_1,DAT_23eedb130,DAT_23eedb148,0x28);
  DAT_23eedb138 = plVar9;
LAB_23e70ac7b:
  lVar10 = *(longlong *)(param_1 + 0x38);
  lVar21 = *(longlong *)(lVar10 + 8);
  plVar9[0xf] = lVar21;
  *(longlong **)(lVar10 + 8) = plVar9 + 9;
  if ((lVar21 != 0) &&
     (((*(char *)(lVar21 + 0x45) == '\x01' ||
       ((ulonglong)
        (*(longlong *)(lVar21 + 0x20) + 0xb8 +
        (longlong)*(int *)(*(longlong *)(lVar21 + 0x20) + 0xa8) * 2) <=
        *(ulonglong *)(lVar21 + 0x38))) && (plVar9[0xe] != 0)))) {
    plVar11 = *(longlong **)(lVar21 + 0x28);
    *(longlong **)(plVar9[0xe] + 0x10) = plVar11;
    if (plVar11 != (longlong *)0x0) {
      *plVar11 = *plVar11 + 1;
    }
  }
  *plVar9 = *plVar9 + 1;
  *(undefined4 *)(plVar9 + 8) = 0;
  lVar10 = FUN_23e8e1490();
  if (lVar10 == 0) {
    plVar22 = (longlong *)0x0;
    uVar20 = 0x31;
    FUN_23e915740(param_1,local_78,DAT_23eed9d20);
    plVar11 = (longlong *)0x0;
  }
  else {
    *(undefined4 *)(plVar9 + 5) = 0x31;
    local_88 = plVar8;
    local_80 = plVar17;
    plVar11 = (longlong *)FUN_23e954670(param_1,lVar10,DAT_23eed9d28,&local_88);
    if (plVar11 == (longlong *)0x0) {
      local_78 = *(undefined1 (*) [16])(param_1 + 0x60);
      local_68[0] = *(longlong **)(param_1 + 0x70);
      plVar22 = (longlong *)0x0;
      *(undefined8 *)(param_1 + 0x70) = 0;
      uVar20 = 0x31;
      *(undefined1 (*) [16])(param_1 + 0x60) = (undefined1  [16])0x0;
      plVar11 = (longlong *)0x0;
    }
    else {
      *plVar11 = *plVar11 + -1;
      if (*plVar11 == 0) {
        (**(code **)(plVar11[1] + 0x30))(plVar11);
        iVar7 = FUN_23a35f020(plVar17);
        pcVar18 = _Py_FalseStruct_exref;
      }
      else {
        iVar7 = FUN_23a35f020(plVar17);
        pcVar18 = _Py_FalseStruct_exref;
      }
      _Py_FalseStruct_exref = pcVar18;
      if (iVar7 == 0) {
        plVar16 = (longlong *)0x0;
        plVar15 = (longlong *)0x0;
        *(longlong *)pcVar18 = *(longlong *)pcVar18 + 1;
LAB_23e70ad52:
        lVar10 = *(longlong *)(*(longlong *)(param_1 + 0x38) + 8);
        plVar9 = *(longlong **)(lVar10 + 0x28);
        plVar11 = (longlong *)plVar9[2];
        *(undefined8 *)(*(longlong *)(param_1 + 0x38) + 8) = *(undefined8 *)(lVar10 + 0x30);
        *(undefined4 *)(plVar9 + 8) = 0xffffffff;
        if (plVar11 != (longlong *)0x0) {
          plVar9[2] = 0;
          *plVar11 = *plVar11 + -1;
          if (*plVar11 == 0) {
            (**(code **)(plVar11[1] + 0x30))();
          }
        }
        *plVar9 = *plVar9 + -1;
        if (*plVar9 == 0) {
          (**(code **)(plVar9[1] + 0x30))(plVar9);
        }
        plVar9[0xf] = 0;
        plVar11 = plVar15;
        plVar22 = plVar16;
LAB_23e70ad9d:
        *plVar19 = *plVar19 + -1;
        if (*plVar19 == 0) {
          (**(code **)(plVar19[1] + 0x30))(plVar19);
        }
        lVar10 = *plVar8;
        *plVar8 = lVar10 + -1;
        if (lVar10 + -1 == 0) {
          (**(code **)(plVar8[1] + 0x30))(plVar8);
        }
        *plVar17 = *plVar17 + -1;
        if (*plVar17 == 0) {
          (**(code **)(plVar17[1] + 0x30))(plVar17);
        }
        if ((plVar11 != (longlong *)0x0) && (*plVar11 = *plVar11 + -1, *plVar11 == 0)) {
          (**(code **)(plVar11[1] + 0x30))(plVar11);
        }
        if (plVar22 == (longlong *)0x0) {
          return pcVar18;
        }
        *plVar22 = *plVar22 + -1;
        if (*plVar22 != 0) {
          return pcVar18;
        }
        (**(code **)(plVar22[1] + 0x30))(plVar22);
        return pcVar18;
      }
      plVar22 = (longlong *)0x0;
      plVar11 = (longlong *)0x0;
      plVar12 = (longlong *)FUN_23ebf7180(plVar17);
      local_a8 = (longlong *)0x0;
      if (plVar12 == (longlong *)0x0) {
        local_78 = *(undefined1 (*) [16])(param_1 + 0x60);
        local_68[0] = *(longlong **)(param_1 + 0x70);
        uVar20 = 0x36;
        *(undefined8 *)(param_1 + 0x70) = 0;
        *(undefined1 (*) [16])(param_1 + 0x60) = (undefined1  [16])0x0;
      }
      else {
        do {
          plVar13 = (longlong *)(**(code **)(plVar12[1] + 0xe0))(plVar12);
          if (plVar13 == (longlong *)0x0) {
            cVar6 = FUN_23a3591a0(param_1,*(undefined8 *)PyExc_StopIteration_exref);
            if (cVar6 == '\0') {
              plVar13 = *(longlong **)(param_1 + 0x70);
              pcVar18 = *(code **)(param_1 + 0x60);
              uVar23 = *(undefined8 *)(param_1 + 0x68);
              *(undefined8 *)(param_1 + 0x70) = 0;
              *(undefined1 (*) [16])(param_1 + 0x60) = (undefined1  [16])0x0;
              uVar20 = 0x36;
              local_68[0] = (longlong *)0x0;
              local_78 = (undefined1  [16])0x0;
              if (local_a8 == (longlong *)0x0) goto LAB_23e70b17a;
              uVar20 = 0x36;
              goto LAB_23e70b150;
            }
            lVar10 = *(longlong *)(*(longlong *)(param_1 + 0x38) + 8);
            plVar9 = *(longlong **)(lVar10 + 0x28);
            plVar15 = (longlong *)plVar9[2];
            *(undefined8 *)(*(longlong *)(param_1 + 0x38) + 8) = *(undefined8 *)(lVar10 + 0x30);
            *(undefined4 *)(plVar9 + 8) = 0xffffffff;
            if (plVar15 != (longlong *)0x0) {
              plVar9[2] = 0;
              *plVar15 = *plVar15 + -1;
              if (*plVar15 == 0) {
                (**(code **)(plVar15[1] + 0x30))();
              }
            }
            *plVar9 = *plVar9 + -1;
            if (*plVar9 == 0) {
              (**(code **)(plVar9[1] + 0x30))(plVar9);
            }
            plVar9[0xf] = 0;
            if ((local_a8 != (longlong *)0x0) && (*local_a8 = *local_a8 + -1, *local_a8 == 0)) {
              (**(code **)(local_a8[1] + 0x30))(local_a8);
            }
            lVar10 = *plVar12;
            *plVar12 = lVar10 + -1;
            if (lVar10 + -1 == 0) {
              (**(code **)(plVar12[1] + 0x30))(plVar12);
            }
            pcVar18 = _Py_FalseStruct_exref;
            *(longlong *)_Py_FalseStruct_exref = *(longlong *)_Py_FalseStruct_exref + 1;
            goto LAB_23e70ad9d;
          }
          if ((local_a8 != (longlong *)0x0) && (*local_a8 = *local_a8 + -1, *local_a8 == 0)) {
            (**(code **)(local_a8[1] + 0x30))(local_a8);
          }
          plVar14 = (longlong *)FUN_23a388310(plVar13);
          local_a8 = plVar13;
          if (plVar14 == (longlong *)0x0) {
            pcVar18 = *(code **)(param_1 + 0x60);
            uVar23 = *(undefined8 *)(param_1 + 0x68);
            plVar13 = *(longlong **)(param_1 + 0x70);
            *(undefined8 *)(param_1 + 0x70) = 0;
            *(undefined1 (*) [16])(param_1 + 0x60) = (undefined1  [16])0x0;
LAB_23e70b4b8:
            uVar20 = 0x36;
            goto LAB_23e70b150;
          }
          plVar15 = (longlong *)(**(code **)(plVar14[1] + 0xe0))(plVar14);
          if ((plVar15 == (longlong *)0x0) &&
             (plVar15 = (longlong *)FUN_23a3c1b70(param_1,local_78,0,2), plVar15 == (longlong *)0x0)
             ) {
            plVar16 = (longlong *)0x0;
            lVar10 = *plVar14;
LAB_23e70b41c:
            plVar13 = local_68[0];
            pcVar18 = (code *)local_78._0_8_;
            uVar23 = local_78._8_8_;
            local_78 = (undefined1  [16])0x0;
            local_68[0] = (longlong *)0x0;
            *plVar14 = lVar10 + -1;
            if (lVar10 + -1 == 0) {
              (**(code **)(plVar14[1] + 0x30))(plVar14);
            }
            local_68[0] = (longlong *)0x0;
            local_78 = (undefined1  [16])0x0;
            if ((plVar15 != (longlong *)0x0) && (*plVar15 = *plVar15 + -1, *plVar15 == 0)) {
              (**(code **)(plVar15[1] + 0x30))(plVar15);
            }
            if ((plVar16 != (longlong *)0x0) && (*plVar16 = *plVar16 + -1, *plVar16 == 0)) {
              (**(code **)(plVar16[1] + 0x30))(plVar16);
            }
            goto LAB_23e70b4b8;
          }
          plVar16 = (longlong *)(**(code **)(plVar14[1] + 0xe0))(plVar14);
          if ((plVar16 == (longlong *)0x0) &&
             (plVar16 = (longlong *)FUN_23a3c1b70(param_1,local_78,1,2), plVar16 == (longlong *)0x0)
             ) {
            lVar10 = *plVar14;
            goto LAB_23e70b41c;
          }
          cVar6 = FUN_23a3884a0(param_1,local_78,plVar14,2);
          lVar10 = *plVar14;
          if (cVar6 == '\0') goto LAB_23e70b41c;
          *plVar14 = lVar10 + -1;
          if (lVar10 + -1 == 0) {
            (**(code **)(plVar14[1] + 0x30))(plVar14);
          }
          lVar10 = *plVar15;
          *plVar15 = lVar10 + 1;
          if (plVar11 != (longlong *)0x0) {
            *plVar11 = *plVar11 + -1;
            if (*plVar11 == 0) {
              (**(code **)(plVar11[1] + 0x30))(plVar11);
            }
            lVar10 = *plVar15 + -1;
          }
          *plVar15 = lVar10;
          if (lVar10 == 0) {
            (**(code **)(plVar15[1] + 0x30))(plVar15);
          }
          lVar10 = *plVar16;
          *plVar16 = lVar10 + 1;
          if (plVar22 != (longlong *)0x0) {
            *plVar22 = *plVar22 + -1;
            if (*plVar22 == 0) {
              (**(code **)(plVar22[1] + 0x30))(plVar22);
            }
            lVar10 = *plVar16 + -1;
          }
          *plVar16 = lVar10;
          if (lVar10 == 0) {
            (**(code **)(plVar16[1] + 0x30))(plVar16);
          }
          iVar7 = FUN_23a35f020(plVar16);
          plVar11 = plVar15;
          plVar22 = plVar16;
          if (iVar7 == -1) {
            plVar13 = *(longlong **)(param_1 + 0x70);
            pcVar18 = *(code **)(param_1 + 0x60);
            uVar23 = *(undefined8 *)(param_1 + 0x68);
            uVar20 = 0x37;
            *(undefined8 *)(param_1 + 0x70) = 0;
            *(undefined1 (*) [16])(param_1 + 0x60) = (undefined1  [16])0x0;
            goto LAB_23e70b150;
          }
          if (iVar7 != 0) {
            if (plVar19[2] == 0) {
              local_78._8_8_ =
                   PyUnicode_FromFormat
                             ("cannot access local variable \'%U\' where it is not associated with a value"
                              ,DAT_23eed9d30);
              local_78._0_8_ = *(undefined8 *)PyExc_UnboundLocalError_exref;
              *(longlong *)local_78._0_8_ = *(longlong *)local_78._0_8_ + 1;
              local_68[0] = (longlong *)0x0;
              if ((code *)local_78._0_8_ != _Py_NoneStruct_exref) {
                FUN_23e91b1b0(param_1,local_78,local_78 + 8,local_68);
              }
              FUN_23ebf6a40(*(undefined8 *)(param_1 + 0x138),local_78._8_8_);
              pcVar18 = (code *)local_78._0_8_;
              uVar23 = local_78._8_8_;
            }
            else {
              cVar6 = FUN_23e8d9ac0(plVar19[2],DAT_23eed9d08,plVar15);
              pcVar18 = _Py_TrueStruct_exref;
              if (cVar6 != '\0') {
                *(longlong *)_Py_TrueStruct_exref = *(longlong *)_Py_TrueStruct_exref + 1;
                lVar10 = *plVar13;
                *plVar13 = lVar10 + -1;
                if (lVar10 + -1 == 0) {
                  (**(code **)(plVar13[1] + 0x30))(plVar13);
                }
                lVar10 = *plVar12;
                *plVar12 = lVar10 + -1;
                if (lVar10 + -1 == 0) {
                  (**(code **)(plVar12[1] + 0x30))(plVar12);
                }
                goto LAB_23e70ad52;
              }
              local_68[0] = *(longlong **)(param_1 + 0x70);
              *(undefined8 *)(param_1 + 0x70) = 0;
              pcVar18 = *(code **)(param_1 + 0x60);
              *(undefined1 (*) [16])(param_1 + 0x60) = (undefined1  [16])0x0;
              uVar23 = *(undefined8 *)(param_1 + 0x68);
            }
            uVar20 = 0x38;
            plVar13 = local_68[0];
            goto LAB_23e70b150;
          }
          lVar10 = *(longlong *)(param_1 + 0x10);
          if ((((*(int *)(*(longlong *)(lVar10 + 0x28) + 0x160) != 0) ||
               (*(int *)(lVar10 + 0x78) != 0)) && (iVar7 = Py_MakePendingCalls(), iVar7 < 0)) &&
             (pcVar18 = *(code **)(param_1 + 0x60), pcVar18 != (code *)0x0)) goto LAB_23e70b10a;
          if (*(int *)(lVar10 + 0x68) == 0) {
            plVar15 = *(longlong **)(param_1 + 0x90);
          }
          else {
            PyEval_SaveThread();
            PyEval_AcquireThread(param_1);
            plVar15 = *(longlong **)(param_1 + 0x90);
          }
        } while (plVar15 == (longlong *)0x0);
        plVar16 = *(longlong **)(param_1 + 0x60);
        plVar13 = *(longlong **)(param_1 + 0x68);
        *(undefined8 *)(param_1 + 0x90) = 0;
        plVar14 = *(longlong **)(param_1 + 0x70);
        *(longlong **)(param_1 + 0x60) = plVar15;
        *plVar15 = *plVar15 + 1;
        *(undefined8 *)(param_1 + 0x68) = 0;
        *(undefined8 *)(param_1 + 0x70) = 0;
        if ((plVar16 != (longlong *)0x0) && (*plVar16 = *plVar16 + -1, *plVar16 == 0)) {
          (**(code **)(plVar16[1] + 0x30))();
        }
        if ((plVar13 != (longlong *)0x0) && (*plVar13 = *plVar13 + -1, *plVar13 == 0)) {
          (**(code **)(plVar13[1] + 0x30))(plVar13);
        }
        if ((plVar14 != (longlong *)0x0) && (*plVar14 = *plVar14 + -1, *plVar14 == 0)) {
          (**(code **)(plVar14[1] + 0x30))(plVar14);
        }
        pcVar18 = *(code **)(param_1 + 0x60);
LAB_23e70b10a:
        plVar13 = *(longlong **)(param_1 + 0x70);
        *(undefined8 *)(param_1 + 0x70) = 0;
        uVar23 = *(undefined8 *)(param_1 + 0x68);
        uVar20 = 0x36;
        *(undefined1 (*) [16])(param_1 + 0x60) = (undefined1  [16])0x0;
LAB_23e70b150:
        local_68[0] = (longlong *)0x0;
        local_78 = (undefined1  [16])0x0;
        lVar10 = *local_a8;
        *local_a8 = lVar10 + -1;
        if (lVar10 + -1 == 0) {
          (**(code **)(local_a8[1] + 0x30))(local_a8);
        }
LAB_23e70b17a:
        lVar10 = *plVar12;
        *plVar12 = lVar10 + -1;
        if (lVar10 + -1 == 0) {
          (**(code **)(plVar12[1] + 0x30))(plVar12);
        }
        local_78._8_8_ = uVar23;
        local_78._0_8_ = pcVar18;
        local_68[0] = plVar13;
      }
    }
  }
  plVar16 = local_68[0];
  plVar15 = DAT_23ed6a4f8;
  if (local_68[0] == (longlong *)0x0) {
    if (DAT_23ed6a4f8 == (longlong *)0x0) {
      plVar15 = (longlong *)FUN_23a33a530(PyTraceBack_Type_exref);
    }
    else {
      plVar16 = (longlong *)*DAT_23ed6a4f8;
      *DAT_23ed6a4f8 = 1;
      DAT_23ed6a4f8 = plVar16;
      DAT_23ed6a4f0 = DAT_23ed6a4f0 + -1;
    }
    pcVar18 = _PyRuntime_exref;
    plVar15[2] = 0;
    plVar15[3] = (longlong)plVar9;
    *plVar9 = *plVar9 + 1;
    lVar10 = *(longlong *)(pcVar18 + 0x1f8);
    *(undefined4 *)(plVar15 + 4) = 0xffffffff;
    lVar10 = *(longlong *)(lVar10 + 0x10);
    *(undefined4 *)((longlong)plVar15 + 0x24) = uVar20;
    lVar10 = *(longlong *)(lVar10 + 0x2e8);
    lVar21 = plVar15[-1];
    puVar2 = *(undefined8 **)(lVar10 + 8);
    *puVar2 = plVar15 + -2;
    plVar15[-2] = lVar10;
    plVar15[-1] = (ulonglong)((uint)lVar21 & 3) | (ulonglong)puVar2;
    *(longlong **)(lVar10 + 8) = plVar15 + -2;
    plVar16 = plVar15;
    if ((local_68[0] != (longlong *)0x0) && (*local_68[0] = *local_68[0] + -1, *local_68[0] == 0)) {
      (**(code **)(local_68[0][1] + 0x30))(local_68[0]);
    }
  }
  else if ((longlong *)local_68[0][3] != plVar9) {
    if (DAT_23ed6a4f8 == (longlong *)0x0) {
      plVar15 = (longlong *)FUN_23a33a530(PyTraceBack_Type_exref);
    }
    else {
      plVar12 = (longlong *)*DAT_23ed6a4f8;
      *DAT_23ed6a4f8 = 1;
      DAT_23ed6a4f8 = plVar12;
      DAT_23ed6a4f0 = DAT_23ed6a4f0 + -1;
    }
    pcVar18 = _PyRuntime_exref;
    plVar15[3] = (longlong)plVar9;
    *plVar9 = *plVar9 + 1;
    lVar10 = *(longlong *)(pcVar18 + 0x1f8);
    *(undefined4 *)(plVar15 + 4) = 0xffffffff;
    *(undefined4 *)((longlong)plVar15 + 0x24) = uVar20;
    lVar10 = *(longlong *)(*(longlong *)(lVar10 + 0x10) + 0x2e8);
    lVar21 = plVar15[-1];
    puVar2 = *(undefined8 **)(lVar10 + 8);
    *puVar2 = plVar15 + -2;
    plVar15[-2] = lVar10;
    plVar15[-1] = (ulonglong)((uint)lVar21 & 3) | (ulonglong)puVar2;
    *(longlong **)(lVar10 + 8) = plVar15 + -2;
    plVar15[2] = (longlong)plVar16;
    *plVar16 = *plVar16 + 1;
    plVar16 = plVar15;
    if ((local_68[0] != (longlong *)0x0) && (*local_68[0] = *local_68[0] + -1, *local_68[0] == 0)) {
      (**(code **)(local_68[0][1] + 0x30))();
    }
  }
  local_68[0] = plVar16;
  FUN_23e8bba40(plVar9,"coooo",plVar19,plVar8,plVar17,plVar11,plVar22);
  if (DAT_23eedb138 == plVar9) {
    *plVar9 = *plVar9 + -1;
    if (*plVar9 == 0) {
      (**(code **)(plVar9[1] + 0x30))(plVar9);
    }
    DAT_23eedb138 = (longlong *)0x0;
  }
  lVar10 = *(longlong *)(*(longlong *)(param_1 + 0x38) + 8);
  plVar9 = *(longlong **)(lVar10 + 0x28);
  plVar15 = (longlong *)plVar9[2];
  *(undefined8 *)(*(longlong *)(param_1 + 0x38) + 8) = *(undefined8 *)(lVar10 + 0x30);
  *(undefined4 *)(plVar9 + 8) = 0xffffffff;
  if (plVar15 != (longlong *)0x0) {
    plVar9[2] = 0;
    *plVar15 = *plVar15 + -1;
    if (*plVar15 == 0) {
      (**(code **)(plVar15[1] + 0x30))();
    }
  }
  *plVar9 = *plVar9 + -1;
  if (*plVar9 == 0) {
    (**(code **)(plVar9[1] + 0x30))(plVar9);
  }
  plVar15 = local_68[0];
  auVar5 = local_78;
  plVar9[0xf] = 0;
  uVar23 = local_78._0_8_;
  uVar3 = local_78._8_8_;
  local_78 = (undefined1  [16])0x0;
  local_68[0] = (longlong *)0x0;
  *plVar19 = *plVar19 + -1;
  if (*plVar19 == 0) {
    (**(code **)(plVar19[1] + 0x30))(plVar19);
  }
  lVar10 = *plVar8;
  *plVar8 = lVar10 + -1;
  if (lVar10 + -1 == 0) {
    (**(code **)(plVar8[1] + 0x30))(plVar8);
  }
  *plVar17 = *plVar17 + -1;
  if (*plVar17 == 0) {
    (**(code **)(plVar17[1] + 0x30))(plVar17);
  }
  if ((plVar11 != (longlong *)0x0) && (*plVar11 = *plVar11 + -1, *plVar11 == 0)) {
    (**(code **)(plVar11[1] + 0x30))(plVar11);
  }
  if ((plVar22 != (longlong *)0x0) && (*plVar22 = *plVar22 + -1, *plVar22 == 0)) {
    (**(code **)(plVar22[1] + 0x30))(plVar22);
  }
  local_78 = auVar5;
  local_68[0] = plVar15;
  FUN_23a33aa70(param_1,uVar23,uVar3,plVar15);
  return (code *)0x0;
}
