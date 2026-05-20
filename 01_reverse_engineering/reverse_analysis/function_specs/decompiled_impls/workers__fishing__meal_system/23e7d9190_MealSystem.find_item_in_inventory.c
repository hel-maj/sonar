/* ===== 23e7d9190 workers.fishing.meal_system:341 ===== */
/* ghidra_name=FUN_23e7d9190 entry=23e7d9190 size=8515 */

code * FUN_23e7d9190(longlong param_1,undefined8 param_2,undefined8 *param_3)

{
  longlong *plVar1;
  longlong lVar2;
  undefined8 *puVar3;
  longlong *plVar4;
  longlong *plVar5;
  undefined8 uVar6;
  char cVar7;
  int iVar8;
  undefined8 uVar9;
  longlong *plVar10;
  code *pcVar11;
  longlong lVar12;
  longlong *plVar13;
  longlong *plVar14;
  code *pcVar15;
  code *pcVar16;
  code *pcVar17;
  code *pcVar18;
  longlong lVar19;
  code *pcVar20;
  undefined4 uVar21;
  code *pcVar22;
  code *pcVar23;
  code *local_e8;
  code *local_d0;
  longlong *local_c0;
  code *local_b8;
  code *local_b0;
  undefined1 local_98 [16];
  longlong *local_88 [2];
  code *local_78;
  longlong *plStack_70;
  undefined8 local_68;
  
  plVar10 = DAT_23eedec38;
  plVar1 = (longlong *)*param_3;
  local_88[0] = (longlong *)0x0;
  local_98._0_8_ = (code *)0x0;
  local_98._8_8_ = 0;
  if (DAT_23eedec38 != (longlong *)0x0) {
    lVar12 = *DAT_23eedec38;
    if (lVar12 < 2) {
      if (DAT_23eedec38[2] == 0) goto LAB_23e7d921b;
      *DAT_23eedec38 = lVar12 + -1;
      if (lVar12 + -1 == 0) {
        (**(code **)(plVar10[1] + 0x30))(plVar10);
      }
    }
    else {
      *DAT_23eedec38 = lVar12 + -1;
    }
  }
  DAT_23eedec38 = (longlong *)FUN_23e91f3b0(param_1,DAT_23eedec30,DAT_23eed7940,0x38);
LAB_23e7d921b:
  plVar5 = DAT_23eedec38;
  lVar12 = *(longlong *)(param_1 + 0x38);
  plVar10 = DAT_23eedec38 + 9;
  lVar19 = *(longlong *)(lVar12 + 8);
  DAT_23eedec38[0xf] = lVar19;
  *(longlong **)(lVar12 + 8) = plVar10;
  if ((lVar19 != 0) &&
     (((*(char *)(lVar19 + 0x45) == '\x01' ||
       ((ulonglong)
        (*(longlong *)(lVar19 + 0x20) + 0xb8 +
        (longlong)*(int *)(*(longlong *)(lVar19 + 0x20) + 0xa8) * 2) <=
        *(ulonglong *)(lVar19 + 0x38))) && (plVar5[0xe] != 0)))) {
    plVar10 = *(longlong **)(lVar19 + 0x28);
    *(longlong **)(plVar5[0xe] + 0x10) = plVar10;
    if (plVar10 != (longlong *)0x0) {
      *plVar10 = *plVar10 + 1;
    }
  }
  *plVar5 = *plVar5 + 1;
  *(undefined4 *)(plVar5 + 8) = 0;
  uVar9 = FUN_23a3a0d40(DAT_23ed6cf28);
  *(undefined4 *)(plVar5 + 5) = 0x157;
  plVar10 = (longlong *)FUN_23e94bb80(param_1,uVar9,DAT_23eed7530);
  if (plVar10 == (longlong *)0x0) {
    local_98._0_8_ = *(undefined8 *)(param_1 + 0x60);
    local_98._8_8_ = *(undefined8 *)(param_1 + 0x68);
    local_88[0] = *(longlong **)(param_1 + 0x70);
    pcVar22 = (code *)0x0;
    pcVar23 = (code *)0x0;
    *(undefined8 *)(param_1 + 0x70) = 0;
    uVar21 = 0x157;
    local_b8 = (code *)0x0;
    local_c0 = (longlong *)0x0;
    local_e8 = (code *)0x0;
    *(undefined1 (*) [16])(param_1 + 0x60) = (undefined1  [16])0x0;
    pcVar20 = (code *)0x0;
  }
  else {
    *plVar10 = *plVar10 + -1;
    if (*plVar10 == 0) {
      (**(code **)(plVar10[1] + 0x30))(plVar10);
    }
    pcVar20 = DAT_23ed6ccf0;
    *(longlong *)DAT_23ed6ccf0 = *(longlong *)DAT_23ed6ccf0 + 1;
    if (plVar1 == (longlong *)0x0) {
      local_98._8_8_ =
           PyUnicode_FromFormat
                     ("cannot access local variable \'%U\' where it is not associated with a value",
                      DAT_23eed70d0);
      local_98._0_8_ = *(undefined8 *)PyExc_UnboundLocalError_exref;
      *(longlong *)local_98._0_8_ = *(longlong *)local_98._0_8_ + 1;
      local_88[0] = (longlong *)0x0;
      if ((code *)local_98._0_8_ != _Py_NoneStruct_exref) {
        FUN_23e91b1b0(param_1,local_98,local_98 + 8,local_88);
      }
      pcVar22 = (code *)0x0;
      pcVar23 = (code *)0x0;
      uVar21 = 0x15c;
      FUN_23ebf6a40(*(undefined8 *)(param_1 + 0x138),local_98._8_8_);
      local_b8 = (code *)0x0;
      local_c0 = (longlong *)0x0;
      local_e8 = (code *)0x0;
    }
    else {
      local_b8 = (code *)0x0;
      local_c0 = (longlong *)0x0;
      local_b0 = (code *)0x0;
      local_d0 = pcVar20;
      local_e8 = (code *)0x0;
      pcVar23 = (code *)0x0;
      do {
        pcVar22 = local_b0;
        pcVar20 = local_d0;
        plVar10 = (longlong *)FUN_23e8bc2f0(plVar1,DAT_23eed72a8);
        uVar9 = DAT_23eed72a8;
        if (plVar10 == (longlong *)0x0) {
LAB_23e7da2b0:
          local_98._0_8_ = *(undefined8 *)(param_1 + 0x60);
          local_98._8_8_ = *(undefined8 *)(param_1 + 0x68);
          local_88[0] = *(longlong **)(param_1 + 0x70);
          uVar21 = 0x15c;
          *(undefined8 *)(param_1 + 0x70) = 0;
          *(undefined1 (*) [16])(param_1 + 0x60) = (undefined1  [16])0x0;
          goto LAB_23e7d9b50;
        }
        *(undefined4 *)(plVar5 + 5) = 0x15c;
        pcVar11 = (code *)FUN_23e91bfe0(param_1,plVar10,uVar9);
        *plVar10 = *plVar10 + -1;
        if (*plVar10 == 0) {
          (**(code **)(plVar10[1] + 0x30))(plVar10);
        }
        if (pcVar11 == (code *)0x0) goto LAB_23e7da2b0;
        if ((local_e8 != (code *)0x0) &&
           (*(longlong *)local_e8 = *(longlong *)local_e8 + -1, *(longlong *)local_e8 == 0)) {
          (**(code **)(*(longlong *)(local_e8 + 8) + 0x30))(local_e8);
        }
        uVar9 = DAT_23eed7538;
        local_e8 = pcVar11;
        if (pcVar11 == _Py_NoneStruct_exref) {
          uVar9 = FUN_23a3a0d40(DAT_23ed6cf28);
          *(undefined4 *)(plVar5 + 5) = 0x15e;
          plVar10 = (longlong *)FUN_23e94bb80(param_1,uVar9,DAT_23eed74e0);
          if (plVar10 != (longlong *)0x0) {
            *plVar10 = *plVar10 + -1;
            pcVar16 = local_b0;
            pcVar15 = pcVar23;
            if (*plVar10 == 0) {
              (**(code **)(plVar10[1] + 0x30))(plVar10);
            }
LAB_23e7da59c:
            lVar12 = *(longlong *)(*(longlong *)(param_1 + 0x38) + 8);
            plVar10 = *(longlong **)(lVar12 + 0x28);
            plVar5 = (longlong *)plVar10[2];
            *(undefined8 *)(*(longlong *)(param_1 + 0x38) + 8) = *(undefined8 *)(lVar12 + 0x30);
            *(undefined4 *)(plVar10 + 8) = 0xffffffff;
            if (plVar5 != (longlong *)0x0) {
              plVar10[2] = 0;
              *plVar5 = *plVar5 + -1;
              if (*plVar5 == 0) {
                (**(code **)(plVar5[1] + 0x30))();
              }
            }
            *plVar10 = *plVar10 + -1;
            if (*plVar10 == 0) {
              (**(code **)(plVar10[1] + 0x30))(plVar10);
            }
            pcVar20 = _Py_FalseStruct_exref;
            plVar10[0xf] = 0;
            *(longlong *)pcVar20 = *(longlong *)pcVar20 + 1;
            local_b0 = pcVar16;
            pcVar23 = pcVar15;
LAB_23e7da60c:
            if ((local_d0 != (code *)0x0) &&
               (*(longlong *)local_d0 = *(longlong *)local_d0 + -1, *(longlong *)local_d0 == 0)) {
              (**(code **)(*(longlong *)(local_d0 + 8) + 0x30))(local_d0);
            }
            lVar12 = *(longlong *)pcVar11;
            *(longlong *)pcVar11 = lVar12 + -1;
            if (lVar12 + -1 == 0) {
              (**(code **)(*(longlong *)(pcVar11 + 8) + 0x30))(pcVar11);
            }
            if ((local_c0 != (longlong *)0x0) &&
               (lVar12 = *local_c0, *local_c0 = lVar12 + -1, lVar12 + -1 == 0)) {
              (**(code **)(local_c0[1] + 0x30))(local_c0);
            }
            if ((pcVar23 != (code *)0x0) &&
               (*(longlong *)pcVar23 = *(longlong *)pcVar23 + -1, *(longlong *)pcVar23 == 0)) {
              (**(code **)(*(longlong *)(pcVar23 + 8) + 0x30))(pcVar23);
            }
            if ((local_b0 != (code *)0x0) &&
               (*(longlong *)local_b0 = *(longlong *)local_b0 + -1, *(longlong *)local_b0 == 0)) {
              (**(code **)(*(longlong *)((longlong)local_b0 + 8) + 0x30))(local_b0);
            }
            if ((local_b8 != (code *)0x0) &&
               (lVar12 = *(longlong *)local_b8, *(longlong *)local_b8 = lVar12 + -1,
               lVar12 + -1 == 0)) {
              (**(code **)(*(longlong *)(local_b8 + 8) + 0x30))(local_b8);
            }
            lVar12 = *plVar1;
            *plVar1 = lVar12 + -1;
            if (lVar12 + -1 != 0) {
              return pcVar20;
            }
            (**(code **)(plVar1[1] + 0x30))(plVar1);
            return pcVar20;
          }
          local_98._0_8_ = *(undefined8 *)(param_1 + 0x60);
          local_98._8_8_ = *(undefined8 *)(param_1 + 0x68);
          local_88[0] = *(longlong **)(param_1 + 0x70);
          uVar21 = 0x15e;
          *(undefined8 *)(param_1 + 0x70) = 0;
          *(undefined1 (*) [16])(param_1 + 0x60) = (undefined1  [16])0x0;
          goto LAB_23e7d9b50;
        }
        *(undefined4 *)(plVar5 + 5) = 0x162;
        plVar10 = (longlong *)FUN_23e915840(param_1,plVar1,uVar9,pcVar11);
        if (plVar10 == (longlong *)0x0) {
          local_98._0_8_ = *(undefined8 *)(param_1 + 0x60);
          local_98._8_8_ = *(undefined8 *)(param_1 + 0x68);
          local_88[0] = *(longlong **)(param_1 + 0x70);
          uVar21 = 0x162;
          *(undefined8 *)(param_1 + 0x70) = 0;
          *(undefined1 (*) [16])(param_1 + 0x60) = (undefined1  [16])0x0;
          goto LAB_23e7d9b50;
        }
        iVar8 = FUN_23a35f020(plVar10);
        lVar12 = *plVar10 + -1;
        if (iVar8 == -1) {
          local_98._0_8_ = *(undefined8 *)(param_1 + 0x60);
          local_98._8_8_ = *(undefined8 *)(param_1 + 0x68);
          local_88[0] = *(longlong **)(param_1 + 0x70);
          uVar21 = 0x162;
          *(undefined8 *)(param_1 + 0x70) = 0;
          *(undefined1 (*) [16])(param_1 + 0x60) = (undefined1  [16])0x0;
          *plVar10 = lVar12;
          if (lVar12 == 0) {
            (**(code **)(plVar10[1] + 0x30))(plVar10);
          }
          goto LAB_23e7d9b50;
        }
        *plVar10 = lVar12;
        if (lVar12 == 0) {
          (**(code **)(plVar10[1] + 0x30))(plVar10);
        }
        plVar10 = DAT_23eed7550;
        uVar9 = DAT_23eed74e8;
        if (iVar8 != 0) {
          uVar9 = FUN_23a3a0d40(DAT_23ed6cf28);
          plVar13 = DAT_23eed7540;
          lVar12 = *(longlong *)(param_1 + 0x10);
          plVar10 = *(longlong **)(lVar12 + 0xe20);
          if (plVar10 == (longlong *)0x0) {
            plVar10 = (longlong *)FUN_23e916a20(PyTuple_Type_exref,2);
          }
          else {
            lVar19 = plVar10[3];
            *(int *)(lVar12 + 0xebc) = *(int *)(lVar12 + 0xebc) + -1;
            *(longlong *)(lVar12 + 0xe20) = lVar19;
            *plVar10 = 1;
          }
          pcVar16 = _PyRuntime_exref;
          plVar10[4] = 0;
          lVar12 = *(longlong *)(*(longlong *)(*(longlong *)(pcVar16 + 0x1f8) + 0x10) + 0x2e8);
          lVar19 = plVar10[-1];
          puVar3 = *(undefined8 **)(lVar12 + 8);
          *puVar3 = plVar10 + -2;
          plVar10[-2] = lVar12;
          plVar10[-1] = (ulonglong)((uint)lVar19 & 3) | (ulonglong)puVar3;
          *(longlong **)(lVar12 + 8) = plVar10 + -2;
          *plVar13 = *plVar13 + 1;
          plVar10[3] = (longlong)plVar13;
          plVar13 = DAT_23ed6cd28;
          if (local_d0 == (code *)0x0) {
            local_98._8_8_ =
                 PyUnicode_FromFormat
                           ("cannot access local variable \'%U\' where it is not associated with a value"
                            ,DAT_23eed7548);
            local_98._0_8_ = *(undefined8 *)PyExc_UnboundLocalError_exref;
            *(longlong *)local_98._0_8_ = *(longlong *)local_98._0_8_ + 1;
            local_88[0] = (longlong *)0x0;
            if ((code *)local_98._0_8_ != _Py_NoneStruct_exref) {
              FUN_23e91b1b0(param_1,local_98,local_98 + 8,local_88);
            }
            FUN_23ebf6a40(*(undefined8 *)(param_1 + 0x138),local_98._8_8_);
          }
          else {
            pcVar16 = (code *)&DAT_23ed6a4c0;
            if (DAT_23ed6a4c0 == (longlong *)0x0) {
              plVar14 = (longlong *)PyDict_GetItemString(DAT_23ed6ccc0,"format");
              if (plVar14 == (longlong *)0x0) goto LAB_23e7d9e10;
              *plVar14 = *plVar14 + 1;
              DAT_23ed6a4c0 = plVar14;
            }
            plStack_70 = plVar13;
            local_78 = local_d0;
            lVar12 = FUN_23e94ed00(param_1,DAT_23ed6a4c0,&local_78);
            if (lVar12 != 0) {
              plVar10[4] = lVar12;
              plVar13 = (longlong *)PyUnicode_Join(DAT_23ed6cd28,plVar10);
              *plVar10 = *plVar10 + -1;
              if (*plVar10 == 0) {
                (**(code **)(plVar10[1] + 0x30))(plVar10);
              }
              if (plVar13 != (longlong *)0x0) {
                *(undefined4 *)(plVar5 + 5) = 0x163;
                plVar10 = (longlong *)FUN_23e914090(param_1,uVar9,plVar13);
                *plVar13 = *plVar13 + -1;
                if (*plVar13 == 0) {
                  (**(code **)(plVar13[1] + 0x30))(plVar13);
                }
                if (plVar10 != (longlong *)0x0) {
                  *plVar10 = *plVar10 + -1;
                  if (*plVar10 == 0) {
                    (**(code **)(plVar10[1] + 0x30))(plVar10);
                  }
                  pcVar20 = _Py_TrueStruct_exref;
                  *(longlong *)_Py_TrueStruct_exref = *(longlong *)_Py_TrueStruct_exref + 1;
LAB_23e7da95a:
                  lVar12 = *(longlong *)(*(longlong *)(param_1 + 0x38) + 8);
                  plVar10 = *(longlong **)(lVar12 + 0x28);
                  plVar5 = (longlong *)plVar10[2];
                  *(undefined8 *)(*(longlong *)(param_1 + 0x38) + 8) =
                       *(undefined8 *)(lVar12 + 0x30);
                  *(undefined4 *)(plVar10 + 8) = 0xffffffff;
                  if (plVar5 != (longlong *)0x0) {
                    plVar10[2] = 0;
                    *plVar5 = *plVar5 + -1;
                    if (*plVar5 == 0) {
                      (**(code **)(plVar5[1] + 0x30))();
                    }
                  }
                  *plVar10 = *plVar10 + -1;
                  if (*plVar10 == 0) {
                    (**(code **)(plVar10[1] + 0x30))(plVar10);
                  }
                  plVar10[0xf] = 0;
                  goto LAB_23e7da60c;
                }
              }
              local_98._0_8_ = *(undefined8 *)(param_1 + 0x60);
              local_98._8_8_ = *(undefined8 *)(param_1 + 0x68);
              local_88[0] = *(longlong **)(param_1 + 0x70);
              uVar21 = 0x163;
              *(undefined8 *)(param_1 + 0x70) = 0;
              *(undefined1 (*) [16])(param_1 + 0x60) = (undefined1  [16])0x0;
              goto LAB_23e7d9b50;
            }
            local_88[0] = *(longlong **)(param_1 + 0x70);
            local_98._0_8_ = *(undefined8 *)(param_1 + 0x60);
            local_98._8_8_ = *(undefined8 *)(param_1 + 0x68);
            *(undefined8 *)(param_1 + 0x70) = 0;
            *(undefined1 (*) [16])(param_1 + 0x60) = (undefined1  [16])0x0;
          }
          *plVar10 = *plVar10 + -1;
          if (*plVar10 == 0) {
            uVar21 = 0x163;
            (**(code **)(plVar10[1] + 0x30))(plVar10);
          }
          else {
            uVar21 = 0x163;
          }
          goto LAB_23e7d9b50;
        }
        *(undefined4 *)(plVar5 + 5) = 0x167;
        plStack_70 = plVar10;
        local_78 = pcVar11;
        plVar10 = (longlong *)FUN_23e954670(param_1,plVar1,uVar9,&local_78);
        if (plVar10 == (longlong *)0x0) {
LAB_23e7da300:
          plVar10 = *(longlong **)(param_1 + 0x70);
          *(undefined8 *)(param_1 + 0x70) = 0;
          pcVar11 = *(code **)(param_1 + 0x60);
          uVar9 = *(undefined8 *)(param_1 + 0x68);
          *(undefined1 (*) [16])(param_1 + 0x60) = (undefined1  [16])0x0;
LAB_23e7da32b:
          uVar21 = 0x167;
          local_88[0] = plVar10;
          local_98._0_8_ = pcVar11;
          local_98._8_8_ = uVar9;
          goto LAB_23e7d9b50;
        }
        plVar13 = (longlong *)FUN_23a388310(plVar10);
        *plVar10 = *plVar10 + -1;
        if (*plVar10 == 0) {
          (**(code **)(plVar10[1] + 0x30))(plVar10);
        }
        if (plVar13 == (longlong *)0x0) goto LAB_23e7da300;
        plVar14 = (longlong *)(**(code **)(plVar13[1] + 0xe0))(plVar13);
        if ((plVar14 == (longlong *)0x0) &&
           (plVar14 = (longlong *)FUN_23a3c1b70(param_1,local_98,0,4), plVar14 == (longlong *)0x0))
        {
          pcVar16 = (code *)0x0;
          lVar12 = *plVar13;
          local_d0 = (code *)0x0;
          local_b0 = (code *)0x0;
          pcVar17 = local_d0;
          pcVar15 = local_b0;
LAB_23e7d9f40:
          local_b0 = pcVar15;
          local_d0 = pcVar17;
          plVar10 = local_88[0];
          uVar9 = local_98._8_8_;
          pcVar11 = (code *)local_98._0_8_;
          local_98 = (undefined1  [16])0x0;
          local_88[0] = (longlong *)0x0;
          *plVar13 = lVar12 + -1;
          if (lVar12 + -1 == 0) {
            (**(code **)(plVar13[1] + 0x30))(plVar13);
          }
          local_88[0] = (longlong *)0x0;
          local_98._0_8_ = 0;
          local_98._8_8_ = 0;
          if ((plVar14 != (longlong *)0x0) && (*plVar14 = *plVar14 + -1, *plVar14 == 0)) {
            (**(code **)(plVar14[1] + 0x30))(plVar14);
          }
          if ((local_b0 != (code *)0x0) &&
             (lVar12 = *(longlong *)local_b0, *(longlong *)local_b0 = lVar12 + -1, lVar12 + -1 == 0)
             ) {
            (**(code **)(*(longlong *)(local_b0 + 8) + 0x30))(local_b0);
          }
          if ((pcVar16 != (code *)0x0) &&
             (*(longlong *)pcVar16 = *(longlong *)pcVar16 + -1, *(longlong *)pcVar16 == 0)) {
            (**(code **)(*(longlong *)((longlong)pcVar16 + 8) + 0x30))(pcVar16);
          }
          if ((local_d0 != (code *)0x0) &&
             (lVar12 = *(longlong *)local_d0, *(longlong *)local_d0 = lVar12 + -1, lVar12 + -1 == 0)
             ) {
            (**(code **)(*(longlong *)(local_d0 + 8) + 0x30))(local_d0);
          }
          goto LAB_23e7da32b;
        }
        pcVar15 = (code *)(**(code **)(plVar13[1] + 0xe0))(plVar13);
        if ((pcVar15 == (code *)0x0) &&
           (pcVar15 = (code *)FUN_23a3c1b70(param_1,local_98,1,4), pcVar15 == (code *)0x0)) {
          pcVar16 = (code *)0x0;
          lVar12 = *plVar13;
          local_d0 = (code *)0x0;
          pcVar17 = local_d0;
          goto LAB_23e7d9f40;
        }
        pcVar16 = (code *)(**(code **)(plVar13[1] + 0xe0))(plVar13);
        if ((pcVar16 == (code *)0x0) &&
           (pcVar16 = (code *)FUN_23a3c1b70(param_1,local_98,2,4), pcVar16 == (code *)0x0)) {
          local_d0 = (code *)0x0;
          lVar12 = *plVar13;
          pcVar17 = local_d0;
          goto LAB_23e7d9f40;
        }
        pcVar17 = (code *)(**(code **)(plVar13[1] + 0xe0))(plVar13);
        if ((pcVar17 == (code *)0x0) &&
           (pcVar17 = (code *)FUN_23a3c1b70(param_1,local_98,3,4), pcVar17 == (code *)0x0)) {
          lVar12 = *plVar13;
          goto LAB_23e7d9f40;
        }
        cVar7 = FUN_23a3884a0(param_1,local_98,plVar13,4);
        lVar12 = *plVar13;
        if (cVar7 == '\0') goto LAB_23e7d9f40;
        *plVar13 = lVar12 + -1;
        if (lVar12 + -1 == 0) {
          (**(code **)(plVar13[1] + 0x30))(plVar13);
        }
        lVar12 = *plVar14;
        *plVar14 = lVar12 + 1;
        if (local_c0 != (longlong *)0x0) {
          lVar12 = *local_c0;
          *local_c0 = lVar12 + -1;
          if (lVar12 + -1 == 0) {
            (**(code **)(local_c0[1] + 0x30))();
          }
          lVar12 = *plVar14 + -1;
        }
        *plVar14 = lVar12;
        if (lVar12 == 0) {
          (**(code **)(plVar14[1] + 0x30))(plVar14);
        }
        lVar12 = *(longlong *)pcVar15;
        *(longlong *)pcVar15 = lVar12 + 1;
        if (pcVar23 != (code *)0x0) {
          *(longlong *)pcVar23 = *(longlong *)pcVar23 + -1;
          if (*(longlong *)pcVar23 == 0) {
            (**(code **)(*(longlong *)(pcVar23 + 8) + 0x30))(pcVar23);
          }
          lVar12 = *(longlong *)pcVar15 + -1;
        }
        *(longlong *)pcVar15 = lVar12;
        if (lVar12 == 0) {
          (**(code **)(*(longlong *)(pcVar15 + 8) + 0x30))(pcVar15);
        }
        lVar12 = *(longlong *)pcVar16;
        *(longlong *)pcVar16 = lVar12 + 1;
        if (local_b0 != (code *)0x0) {
          lVar12 = *(longlong *)local_b0;
          *(longlong *)local_b0 = lVar12 + -1;
          if (lVar12 + -1 == 0) {
            (**(code **)(*(longlong *)((longlong)local_b0 + 8) + 0x30))(local_b0);
          }
          lVar12 = *(longlong *)pcVar16 + -1;
        }
        *(longlong *)pcVar16 = lVar12;
        if (lVar12 == 0) {
          (**(code **)(*(longlong *)((longlong)pcVar16 + 8) + 0x30))(pcVar16);
        }
        lVar12 = *(longlong *)pcVar17;
        *(longlong *)pcVar17 = lVar12 + 1;
        if (local_b8 != (code *)0x0) {
          lVar12 = *(longlong *)local_b8;
          *(longlong *)local_b8 = lVar12 + -1;
          if (lVar12 + -1 == 0) {
            (**(code **)(*(longlong *)(local_b8 + 8) + 0x30))();
          }
          lVar12 = *(longlong *)pcVar17 + -1;
        }
        *(longlong *)pcVar17 = lVar12;
        if (lVar12 == 0) {
          (**(code **)(*(longlong *)(pcVar17 + 8) + 0x30))(pcVar17);
        }
        iVar8 = FUN_23a35f020(plVar14);
        pcVar22 = pcVar16;
        pcVar23 = pcVar15;
        local_c0 = plVar14;
        local_b8 = pcVar17;
        if (iVar8 == -1) {
          local_98._0_8_ = *(undefined8 *)(param_1 + 0x60);
          local_88[0] = *(longlong **)(param_1 + 0x70);
          uVar21 = 0x169;
          *(undefined8 *)(param_1 + 0x70) = 0;
          *(undefined1 (*) [16])(param_1 + 0x60) = (undefined1  [16])0x0;
          local_98._8_8_ = *(undefined8 *)(param_1 + 0x68);
          goto LAB_23e7d9b50;
        }
        local_b0 = pcVar16;
        if (iVar8 == 0) {
          uVar9 = FUN_23a3a0d40(DAT_23ed6cf28);
          plVar13 = DAT_23eed7558;
          lVar12 = *(longlong *)(param_1 + 0x10);
          plVar10 = *(longlong **)(lVar12 + 0xe28);
          if (plVar10 == (longlong *)0x0) {
            plVar10 = (longlong *)FUN_23e916a20(PyTuple_Type_exref,3);
          }
          else {
            lVar19 = plVar10[3];
            *(int *)(lVar12 + 0xec0) = *(int *)(lVar12 + 0xec0) + -1;
            *(longlong *)(lVar12 + 0xe28) = lVar19;
            *plVar10 = 1;
          }
          pcVar15 = _PyRuntime_exref;
          *(undefined1 (*) [16])(plVar10 + 4) = (undefined1  [16])0x0;
          lVar12 = *(longlong *)(*(longlong *)(*(longlong *)(pcVar15 + 0x1f8) + 0x10) + 0x2e8);
          lVar19 = plVar10[-1];
          puVar3 = *(undefined8 **)(lVar12 + 8);
          *puVar3 = plVar10 + -2;
          plVar10[-2] = lVar12;
          plVar10[-1] = (ulonglong)((uint)lVar19 & 3) | (ulonglong)puVar3;
          *(longlong **)(lVar12 + 8) = plVar10 + -2;
          *plVar13 = *plVar13 + 1;
          plVar10[3] = (longlong)plVar13;
          plVar13 = DAT_23ed6cd28;
          if (local_d0 == (code *)0x0) {
            local_98._8_8_ =
                 PyUnicode_FromFormat
                           ("cannot access local variable \'%U\' where it is not associated with a value"
                            ,DAT_23eed7548);
            local_98._0_8_ = *(undefined8 *)PyExc_UnboundLocalError_exref;
            *(longlong *)local_98._0_8_ = *(longlong *)local_98._0_8_ + 1;
            local_88[0] = (longlong *)0x0;
            if ((code *)local_98._0_8_ != _Py_NoneStruct_exref) {
              FUN_23e91b1b0(param_1,local_98,local_98 + 8,local_88);
            }
            FUN_23ebf6a40(*(undefined8 *)(param_1 + 0x138),local_98._8_8_);
LAB_23e7db071:
            *plVar10 = *plVar10 + -1;
            if (*plVar10 == 0) {
              uVar21 = 0x16a;
              (**(code **)(plVar10[1] + 0x30))(plVar10);
              goto LAB_23e7d9b50;
            }
          }
          else {
            if (DAT_23ed6a4c0 == (longlong *)0x0) {
              plVar14 = (longlong *)PyDict_GetItemString(DAT_23ed6ccc0,"format");
              if (plVar14 == (longlong *)0x0) goto LAB_23e7d9e10;
              *plVar14 = *plVar14 + 1;
              DAT_23ed6a4c0 = plVar14;
            }
            plStack_70 = plVar13;
            local_78 = local_d0;
            lVar12 = FUN_23e94ed00(param_1,DAT_23ed6a4c0,&local_78);
            if (lVar12 == 0) {
              local_88[0] = *(longlong **)(param_1 + 0x70);
              local_98._0_8_ = *(undefined8 *)(param_1 + 0x60);
              local_98._8_8_ = *(undefined8 *)(param_1 + 0x68);
              *(undefined8 *)(param_1 + 0x70) = 0;
              *(undefined1 (*) [16])(param_1 + 0x60) = (undefined1  [16])0x0;
              goto LAB_23e7db071;
            }
            plVar10[4] = lVar12;
            plVar13 = DAT_23eed74a0;
            *DAT_23eed74a0 = *DAT_23eed74a0 + 1;
            plVar10[5] = (longlong)plVar13;
            plVar13 = (longlong *)PyUnicode_Join(DAT_23ed6cd28,plVar10);
            *plVar10 = *plVar10 + -1;
            if (*plVar10 == 0) {
              (**(code **)(plVar10[1] + 0x30))(plVar10);
            }
            if (plVar13 != (longlong *)0x0) {
              *(undefined4 *)(plVar5 + 5) = 0x16a;
              plVar10 = (longlong *)FUN_23e914090(param_1,uVar9,plVar13);
              *plVar13 = *plVar13 + -1;
              if (*plVar13 == 0) {
                (**(code **)(plVar13[1] + 0x30))(plVar13);
              }
              if (plVar10 != (longlong *)0x0) {
                *plVar10 = *plVar10 + -1;
                if (*plVar10 == 0) {
                  (**(code **)(plVar10[1] + 0x30))(plVar10);
                }
                pcVar20 = _Py_FalseStruct_exref;
                *(longlong *)_Py_FalseStruct_exref = *(longlong *)_Py_FalseStruct_exref + 1;
                goto LAB_23e7da95a;
              }
            }
            local_98._0_8_ = *(undefined8 *)(param_1 + 0x60);
            local_98._8_8_ = *(undefined8 *)(param_1 + 0x68);
            local_88[0] = *(longlong **)(param_1 + 0x70);
            *(undefined8 *)(param_1 + 0x70) = 0;
            *(undefined1 (*) [16])(param_1 + 0x60) = (undefined1  [16])0x0;
          }
          uVar21 = 0x16a;
          goto LAB_23e7d9b50;
        }
        plVar13 = (longlong *)FUN_23a37a020(DAT_23ed6ccc0);
        plVar10 = DAT_23eed7560;
        if ((plVar13 == (longlong *)0x0) || (lVar12 = *plVar13, lVar12 == 0)) {
LAB_23e7d9e10:
          PyErr_PrintEx(0);
          Py_Exit(1);
          goto LAB_23e7d9e28;
        }
        lVar19 = *(longlong *)(param_1 + 0x10);
        plVar13 = *(longlong **)(lVar19 + 0xe38);
        if (plVar13 == (longlong *)0x0) {
          plVar13 = (longlong *)FUN_23e916a20(PyTuple_Type_exref,5);
        }
        else {
          lVar2 = plVar13[3];
          *(int *)(lVar19 + 0xec8) = *(int *)(lVar19 + 0xec8) + -1;
          *(longlong *)(lVar19 + 0xe38) = lVar2;
          *plVar13 = 1;
        }
        pcVar18 = _PyRuntime_exref;
        *(undefined1 (*) [16])(plVar13 + 4) = (undefined1  [16])0x0;
        lVar19 = *(longlong *)(pcVar18 + 0x1f8);
        *(undefined1 (*) [16])(plVar13 + 6) = (undefined1  [16])0x0;
        lVar19 = *(longlong *)(*(longlong *)(lVar19 + 0x10) + 0x2e8);
        lVar2 = plVar13[-1];
        puVar3 = *(undefined8 **)(lVar19 + 8);
        *puVar3 = plVar13 + -2;
        plVar13[-2] = lVar19;
        plVar13[-1] = (ulonglong)((uint)lVar2 & 3) | (ulonglong)puVar3;
        *(longlong **)(lVar19 + 8) = plVar13 + -2;
        *plVar10 = *plVar10 + 1;
        plVar13[3] = (longlong)plVar10;
        if (local_d0 == (code *)0x0) {
          local_98._8_8_ =
               PyUnicode_FromFormat
                         ("cannot access local variable \'%U\' where it is not associated with a value"
                          ,DAT_23eed7548);
          local_98._0_8_ = *(undefined8 *)PyExc_UnboundLocalError_exref;
          *(longlong *)local_98._0_8_ = *(longlong *)local_98._0_8_ + 1;
          local_88[0] = (longlong *)0x0;
          if ((code *)local_98._0_8_ != _Py_NoneStruct_exref) {
            FUN_23e91b1b0(param_1,local_98,local_98 + 8,local_88);
          }
          FUN_23ebf6a40(*(undefined8 *)(param_1 + 0x138),local_98._8_8_);
LAB_23e7da420:
          *plVar13 = *plVar13 + -1;
          if (*plVar13 == 0) {
            uVar21 = 0x16e;
            (**(code **)(plVar13[1] + 0x30))(plVar13);
          }
          else {
LAB_23e7da437:
            uVar21 = 0x16e;
          }
          goto LAB_23e7d9b50;
        }
        pcVar18 = (code *)FUN_23e8c0100(local_d0,1);
        plVar10 = DAT_23ed6cd28;
        if (DAT_23ed6a4c0 == (longlong *)0x0) {
          plVar14 = (longlong *)PyDict_GetItemString(DAT_23ed6ccc0,"format");
          if (plVar14 == (longlong *)0x0) goto LAB_23e7d9e10;
          *plVar14 = *plVar14 + 1;
          DAT_23ed6a4c0 = plVar14;
        }
        plStack_70 = plVar10;
        local_78 = pcVar18;
        lVar19 = FUN_23e94ed00(param_1,DAT_23ed6a4c0,&local_78);
        *(longlong *)pcVar18 = *(longlong *)pcVar18 + -1;
        if (*(longlong *)pcVar18 == 0) {
          (**(code **)(*(longlong *)(pcVar18 + 8) + 0x30))(pcVar18);
        }
        if (lVar19 == 0) {
LAB_23e7da3e0:
          local_88[0] = *(longlong **)(param_1 + 0x70);
          local_98._0_8_ = *(undefined8 *)(param_1 + 0x60);
          local_98._8_8_ = *(undefined8 *)(param_1 + 0x68);
          *(undefined8 *)(param_1 + 0x70) = 0;
          *(undefined1 (*) [16])(param_1 + 0x60) = (undefined1  [16])0x0;
          goto LAB_23e7da420;
        }
        plVar13[4] = lVar19;
        plVar14 = DAT_23eed7568;
        plVar10 = DAT_23eed7500;
        *DAT_23eed7568 = *DAT_23eed7568 + 1;
        plVar13[5] = (longlong)plVar14;
        if (DAT_23ed6a4c0 == (longlong *)0x0) {
          plVar14 = (longlong *)PyDict_GetItemString(DAT_23ed6ccc0,"format");
          if (plVar14 == (longlong *)0x0) goto LAB_23e7d9e10;
          *plVar14 = *plVar14 + 1;
          DAT_23ed6a4c0 = plVar14;
        }
        plStack_70 = plVar10;
        local_78 = pcVar17;
        lVar19 = FUN_23e94ed00(param_1,DAT_23ed6a4c0,&local_78);
        if (lVar19 == 0) goto LAB_23e7da3e0;
        plVar13[6] = lVar19;
        plVar10 = DAT_23eed74a0;
        *DAT_23eed74a0 = *DAT_23eed74a0 + 1;
        plVar13[7] = (longlong)plVar10;
        plVar10 = (longlong *)PyUnicode_Join(DAT_23ed6cd28,plVar13);
        *plVar13 = *plVar13 + -1;
        if (*plVar13 == 0) {
          (**(code **)(plVar13[1] + 0x30))(plVar13);
        }
        if (plVar10 == (longlong *)0x0) {
          local_98._0_8_ = *(undefined8 *)(param_1 + 0x60);
          local_98._8_8_ = *(undefined8 *)(param_1 + 0x68);
          local_88[0] = *(longlong **)(param_1 + 0x70);
          *(undefined8 *)(param_1 + 0x70) = 0;
          *(undefined1 (*) [16])(param_1 + 0x60) = (undefined1  [16])0x0;
          goto LAB_23e7da437;
        }
        *(undefined4 *)(plVar5 + 5) = 0x16e;
        plVar13 = (longlong *)FUN_23e914090(param_1,lVar12,plVar10);
        *plVar10 = *plVar10 + -1;
        if (*plVar10 == 0) {
          (**(code **)(plVar10[1] + 0x30))(plVar10);
        }
        if (plVar13 == (longlong *)0x0) {
          local_98._0_8_ = *(undefined8 *)(param_1 + 0x60);
          local_88[0] = *(longlong **)(param_1 + 0x70);
          uVar21 = 0x16e;
          *(undefined8 *)(param_1 + 0x70) = 0;
          *(undefined1 (*) [16])(param_1 + 0x60) = (undefined1  [16])0x0;
          local_98._8_8_ = *(undefined8 *)(param_1 + 0x68);
          goto LAB_23e7d9b50;
        }
        *plVar13 = *plVar13 + -1;
        if (*plVar13 == 0) {
          (**(code **)(plVar13[1] + 0x30))(plVar13);
        }
        local_68 = DAT_23eed7570;
        uVar9 = DAT_23eed7508;
        *(undefined4 *)(plVar5 + 5) = 0x16f;
        local_78 = pcVar15;
        plStack_70 = (longlong *)pcVar16;
        plVar10 = (longlong *)FUN_23e9578c0(param_1,plVar1,uVar9,&local_78);
        if (plVar10 == (longlong *)0x0) {
          local_98._0_8_ = *(undefined8 *)(param_1 + 0x60);
          local_88[0] = *(longlong **)(param_1 + 0x70);
          uVar21 = 0x16f;
          *(undefined8 *)(param_1 + 0x70) = 0;
          *(undefined1 (*) [16])(param_1 + 0x60) = (undefined1  [16])0x0;
          local_98._8_8_ = *(undefined8 *)(param_1 + 0x68);
          goto LAB_23e7d9b50;
        }
        iVar8 = FUN_23a35f020(plVar10);
        lVar12 = *plVar10 + -1;
        if (iVar8 == -1) {
          local_98._0_8_ = *(undefined8 *)(param_1 + 0x60);
          local_98._8_8_ = *(undefined8 *)(param_1 + 0x68);
          local_88[0] = *(longlong **)(param_1 + 0x70);
          *(undefined8 *)(param_1 + 0x70) = 0;
          *(undefined1 (*) [16])(param_1 + 0x60) = (undefined1  [16])0x0;
          *plVar10 = lVar12;
          if (lVar12 == 0) {
            uVar21 = 0x16f;
            (**(code **)(plVar10[1] + 0x30))(plVar10);
          }
          else {
            uVar21 = 0x16f;
          }
          goto LAB_23e7d9b50;
        }
        *plVar10 = lVar12;
        if (lVar12 == 0) {
          (**(code **)(plVar10[1] + 0x30))(plVar10);
        }
        if (iVar8 == 0) {
          uVar9 = FUN_23a3a0d40(DAT_23ed6cf28);
          *(undefined4 *)(plVar5 + 5) = 0x172;
          plVar10 = (longlong *)FUN_23e94bb80(param_1,uVar9,DAT_23eed7578);
          if (plVar10 != (longlong *)0x0) {
            *plVar10 = *plVar10 + -1;
            if (*plVar10 == 0) {
              (**(code **)(plVar10[1] + 0x30))(plVar10);
            }
            goto LAB_23e7da59c;
          }
          local_98._0_8_ = *(undefined8 *)(param_1 + 0x60);
          local_88[0] = *(longlong **)(param_1 + 0x70);
          *(undefined8 *)(param_1 + 0x70) = 0;
          uVar21 = 0x172;
          *(undefined1 (*) [16])(param_1 + 0x60) = (undefined1  [16])0x0;
          local_98._8_8_ = *(undefined8 *)(param_1 + 0x68);
          goto LAB_23e7d9b50;
        }
        local_78 = local_d0;
        FUN_23e8d34a0(&local_78);
        pcVar20 = local_78;
        lVar12 = *(longlong *)(param_1 + 0x10);
        local_d0 = local_78;
        if ((((*(int *)(*(longlong *)(lVar12 + 0x28) + 0x160) != 0) ||
             (*(int *)(lVar12 + 0x78) != 0)) && (iVar8 = Py_MakePendingCalls(), iVar8 < 0)) &&
           (pcVar11 = *(code **)(param_1 + 0x60), pcVar11 != (code *)0x0)) goto LAB_23e7d9af8;
        if (*(int *)(lVar12 + 0x68) == 0) {
          plVar10 = *(longlong **)(param_1 + 0x90);
        }
        else {
          PyEval_SaveThread();
          PyEval_AcquireThread(param_1);
          plVar10 = *(longlong **)(param_1 + 0x90);
        }
      } while (plVar10 == (longlong *)0x0);
      plVar13 = *(longlong **)(param_1 + 0x60);
      plVar14 = *(longlong **)(param_1 + 0x68);
      *(undefined8 *)(param_1 + 0x90) = 0;
      plVar4 = *(longlong **)(param_1 + 0x70);
      *(longlong **)(param_1 + 0x60) = plVar10;
      *plVar10 = *plVar10 + 1;
      *(undefined8 *)(param_1 + 0x68) = 0;
      *(undefined8 *)(param_1 + 0x70) = 0;
      if ((plVar13 != (longlong *)0x0) && (*plVar13 = *plVar13 + -1, *plVar13 == 0)) {
        (**(code **)(plVar13[1] + 0x30))();
      }
      if ((plVar14 != (longlong *)0x0) && (*plVar14 = *plVar14 + -1, *plVar14 == 0)) {
        (**(code **)(plVar14[1] + 0x30))(plVar14);
      }
      if ((plVar4 == (longlong *)0x0) || (*plVar4 = *plVar4 + -1, *plVar4 != 0)) {
        pcVar11 = *(code **)(param_1 + 0x60);
      }
      else {
        (**(code **)(plVar4[1] + 0x30))(plVar4);
        pcVar11 = *(code **)(param_1 + 0x60);
      }
LAB_23e7d9af8:
      local_88[0] = *(longlong **)(param_1 + 0x70);
      *(undefined8 *)(param_1 + 0x70) = 0;
      uVar21 = 0x15a;
      *(undefined1 (*) [16])(param_1 + 0x60) = (undefined1  [16])0x0;
      local_98._0_8_ = pcVar11;
      local_98._8_8_ = *(undefined8 *)(param_1 + 0x68);
    }
  }
LAB_23e7d9b50:
  plVar13 = local_88[0];
  plVar10 = DAT_23ed6a4f8;
  if (local_88[0] == (longlong *)0x0) {
    if (DAT_23ed6a4f8 == (longlong *)0x0) {
      plVar10 = (longlong *)FUN_23a33a530(PyTraceBack_Type_exref);
    }
    else {
      plVar13 = (longlong *)*DAT_23ed6a4f8;
      *DAT_23ed6a4f8 = 1;
      DAT_23ed6a4f8 = plVar13;
      DAT_23ed6a4f0 = DAT_23ed6a4f0 + -1;
    }
    pcVar11 = _PyRuntime_exref;
    plVar10[2] = 0;
    plVar10[3] = (longlong)plVar5;
    *plVar5 = *plVar5 + 1;
    lVar12 = *(longlong *)(pcVar11 + 0x1f8);
    *(undefined4 *)(plVar10 + 4) = 0xffffffff;
    lVar12 = *(longlong *)(lVar12 + 0x10);
    *(undefined4 *)((longlong)plVar10 + 0x24) = uVar21;
    lVar12 = *(longlong *)(lVar12 + 0x2e8);
    lVar19 = plVar10[-1];
    puVar3 = *(undefined8 **)(lVar12 + 8);
    *puVar3 = plVar10 + -2;
    plVar10[-2] = lVar12;
    plVar10[-1] = (ulonglong)((uint)lVar19 & 3) | (ulonglong)puVar3;
    *(longlong **)(lVar12 + 8) = plVar10 + -2;
    plVar13 = plVar10;
    if ((local_88[0] != (longlong *)0x0) && (*local_88[0] = *local_88[0] + -1, *local_88[0] == 0)) {
      (**(code **)(local_88[0][1] + 0x30))(local_88[0]);
    }
  }
  else if ((longlong *)local_88[0][3] != plVar5) {
    if (DAT_23ed6a4f8 == (longlong *)0x0) {
      plVar10 = (longlong *)FUN_23a33a530(PyTraceBack_Type_exref);
    }
    else {
      plVar14 = (longlong *)*DAT_23ed6a4f8;
      *DAT_23ed6a4f8 = 1;
      DAT_23ed6a4f8 = plVar14;
      DAT_23ed6a4f0 = DAT_23ed6a4f0 + -1;
    }
    pcVar11 = _PyRuntime_exref;
    plVar10[3] = (longlong)plVar5;
    *plVar5 = *plVar5 + 1;
    lVar12 = *(longlong *)(pcVar11 + 0x1f8);
    *(undefined4 *)(plVar10 + 4) = 0xffffffff;
    *(undefined4 *)((longlong)plVar10 + 0x24) = uVar21;
    lVar12 = *(longlong *)(*(longlong *)(lVar12 + 0x10) + 0x2e8);
    lVar19 = plVar10[-1];
    puVar3 = *(undefined8 **)(lVar12 + 8);
    *puVar3 = plVar10 + -2;
    plVar10[-2] = lVar12;
    plVar10[-1] = (ulonglong)((uint)lVar19 & 3) | (ulonglong)puVar3;
    *(longlong **)(lVar12 + 8) = plVar10 + -2;
    plVar10[2] = (longlong)plVar13;
    *plVar13 = *plVar13 + 1;
    plVar13 = plVar10;
    if ((local_88[0] != (longlong *)0x0) && (*local_88[0] = *local_88[0] + -1, *local_88[0] == 0)) {
      (**(code **)(local_88[0][1] + 0x30))();
    }
  }
  local_88[0] = plVar13;
  FUN_23e8bba40(plVar5,"ooooooo",plVar1,pcVar20,local_e8,local_c0,pcVar23,pcVar22,local_b8);
  if (DAT_23eedec38 == plVar5) {
    *plVar5 = *plVar5 + -1;
    if (*plVar5 == 0) {
      (**(code **)(plVar5[1] + 0x30))(plVar5);
    }
    DAT_23eedec38 = (longlong *)0x0;
  }
  lVar12 = *(longlong *)(*(longlong *)(param_1 + 0x38) + 8);
  plVar10 = *(longlong **)(lVar12 + 0x28);
  plVar5 = (longlong *)plVar10[2];
  *(undefined8 *)(*(longlong *)(param_1 + 0x38) + 8) = *(undefined8 *)(lVar12 + 0x30);
  *(undefined4 *)(plVar10 + 8) = 0xffffffff;
  if (plVar5 != (longlong *)0x0) {
    plVar10[2] = 0;
    *plVar5 = *plVar5 + -1;
    if (*plVar5 == 0) {
      (**(code **)(plVar5[1] + 0x30))();
    }
  }
  *plVar10 = *plVar10 + -1;
  if (*plVar10 == 0) {
    (**(code **)(plVar10[1] + 0x30))(plVar10);
  }
  plVar5 = local_88[0];
  uVar6 = local_98._8_8_;
  uVar9 = local_98._0_8_;
  plVar10[0xf] = 0;
  local_98 = (undefined1  [16])0x0;
  local_88[0] = (longlong *)0x0;
  if ((pcVar20 != (code *)0x0) &&
     (*(longlong *)pcVar20 = *(longlong *)pcVar20 + -1, *(longlong *)pcVar20 == 0)) {
    (**(code **)(*(longlong *)(pcVar20 + 8) + 0x30))(pcVar20);
  }
  if ((local_e8 != (code *)0x0) &&
     (lVar12 = *(longlong *)local_e8, *(longlong *)local_e8 = lVar12 + -1, lVar12 + -1 == 0)) {
    (**(code **)(*(longlong *)(local_e8 + 8) + 0x30))(local_e8);
  }
  if ((local_c0 != (longlong *)0x0) &&
     (lVar12 = *local_c0, *local_c0 = lVar12 + -1, lVar12 + -1 == 0)) {
    (**(code **)(local_c0[1] + 0x30))(local_c0);
  }
  if ((pcVar23 != (code *)0x0) &&
     (*(longlong *)pcVar23 = *(longlong *)pcVar23 + -1, *(longlong *)pcVar23 == 0)) {
    (**(code **)(*(longlong *)(pcVar23 + 8) + 0x30))(pcVar23);
  }
  if ((pcVar22 != (code *)0x0) &&
     (*(longlong *)pcVar22 = *(longlong *)pcVar22 + -1, *(longlong *)pcVar22 == 0)) {
    (**(code **)(*(longlong *)((longlong)pcVar22 + 8) + 0x30))(pcVar22);
  }
  if ((local_b8 != (code *)0x0) &&
     (lVar12 = *(longlong *)local_b8, *(longlong *)local_b8 = lVar12 + -1, lVar12 + -1 == 0)) {
    (**(code **)(*(longlong *)(local_b8 + 8) + 0x30))(local_b8);
  }
  lVar12 = *plVar1;
  *plVar1 = lVar12 + -1;
  pcVar16 = (code *)plVar1;
  local_88[0] = plVar5;
  local_98._0_8_ = uVar9;
  local_98._8_8_ = uVar6;
  if (lVar12 + -1 == 0) {
LAB_23e7d9e28:
    (**(code **)(*(longlong *)((longlong)pcVar16 + 8) + 0x30))(pcVar16);
  }
  FUN_23a33aa70(param_1,local_98._0_8_,local_98._8_8_,local_88[0]);
  return (code *)0x0;
}
