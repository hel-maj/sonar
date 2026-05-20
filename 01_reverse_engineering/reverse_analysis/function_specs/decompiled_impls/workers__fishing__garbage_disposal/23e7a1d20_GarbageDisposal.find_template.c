/* ===== 23e7a1d20 workers.fishing.garbage_disposal:443 ===== */
/* ghidra_name=FUN_23e7a1d20 entry=23e7a1d20 size=17791 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

code * FUN_23e7a1d20(longlong param_1,undefined8 param_2,undefined8 *param_3)

{
  longlong lVar1;
  undefined8 *puVar2;
  code *pcVar3;
  char cVar4;
  int iVar5;
  longlong *plVar6;
  longlong lVar7;
  undefined8 uVar8;
  longlong *plVar9;
  code *pcVar10;
  longlong *plVar11;
  longlong *plVar12;
  longlong *plVar13;
  code *pcVar14;
  longlong *plVar15;
  longlong *plVar16;
  code *pcVar17;
  longlong *plVar18;
  undefined4 uVar19;
  longlong *plVar20;
  code *pcVar21;
  undefined8 uVar22;
  undefined8 in_stack_fffffffffffffeb8;
  code *local_110;
  code *local_108;
  code **local_100;
  code *local_f8;
  longlong *local_f0;
  longlong *local_d0;
  code *local_a8;
  undefined8 uStack_a0;
  longlong *local_98;
  undefined1 local_88 [16];
  longlong *local_78 [7];
  
  plVar6 = _DAT_23eedabd0;
  plVar18 = (longlong *)*param_3;
  local_78[0] = (longlong *)0x0;
  local_88._0_8_ = (code *)0x0;
  local_88._8_8_ = 0;
  if (_DAT_23eedabd0 == (longlong *)0x0) {
LAB_23e7a1d85:
    _DAT_23eedabd0 = (longlong *)FUN_23e91f3b0(param_1,DAT_23eedabc8,DAT_23eedacf8);
  }
  else {
    lVar7 = *_DAT_23eedabd0;
    if (1 < lVar7) {
      *_DAT_23eedabd0 = lVar7 + -1;
      goto LAB_23e7a1d85;
    }
    if (_DAT_23eedabd0[2] != 0) {
      *_DAT_23eedabd0 = lVar7 + -1;
      if (lVar7 + -1 == 0) {
        (**(code **)(plVar6[1] + 0x30))(plVar6);
      }
      goto LAB_23e7a1d85;
    }
  }
  plVar20 = _DAT_23eedabd0;
  lVar7 = *(longlong *)(param_1 + 0x38);
  plVar6 = _DAT_23eedabd0 + 9;
  lVar1 = *(longlong *)(lVar7 + 8);
  _DAT_23eedabd0[0xf] = lVar1;
  *(longlong **)(lVar7 + 8) = plVar6;
  if ((lVar1 != 0) &&
     (((*(char *)(lVar1 + 0x45) == '\x01' ||
       ((ulonglong)
        (*(longlong *)(lVar1 + 0x20) + 0xb8 +
        (longlong)*(int *)(*(longlong *)(lVar1 + 0x20) + 0xa8) * 2) <= *(ulonglong *)(lVar1 + 0x38))
       ) && (plVar20[0xe] != 0)))) {
    plVar6 = *(longlong **)(lVar1 + 0x28);
    *(longlong **)(plVar20[0xe] + 0x10) = plVar6;
    if (plVar6 != (longlong *)0x0) {
      *plVar6 = *plVar6 + 1;
    }
  }
  *plVar20 = *plVar20 + 1;
  uVar8 = DAT_23eed8618;
  *(undefined4 *)(plVar20 + 8) = 0;
  *(undefined4 *)(plVar20 + 5) = 0x1bd;
  plVar6 = (longlong *)FUN_23e91bfe0(param_1,plVar18,uVar8);
  if (plVar6 != (longlong *)0x0) {
    iVar5 = FUN_23a35f020();
    *plVar6 = *plVar6 + -1;
    if (*plVar6 == 0) {
      (**(code **)(plVar6[1] + 0x30))();
    }
    if (iVar5 == -1) {
      local_88 = *(undefined1 (*) [16])(param_1 + 0x60);
      local_78[0] = *(longlong **)(param_1 + 0x70);
      *(undefined8 *)(param_1 + 0x70) = 0;
      *(undefined1 (*) [16])(param_1 + 0x60) = (undefined1  [16])0x0;
      if (local_78[0] == (longlong *)0x0) goto LAB_23e7a32d0;
      if (plVar20 == (longlong *)local_78[0][3]) goto LAB_23e7a2eb0;
      plVar12 = (longlong *)0x0;
      plVar9 = (longlong *)0x0;
      pcVar17 = (code *)0x0;
      pcVar14 = (code *)0x0;
      pcVar10 = (code *)0x0;
      plVar6 = (longlong *)0x0;
      uVar19 = 0x1bd;
      local_110 = (code *)0x0;
      local_108 = _PyRuntime_exref;
      goto LAB_23e7a2b85;
    }
    if (iVar5 == 0) {
      pcVar10 = (code *)0x0;
      plVar6 = (longlong *)0x0;
      local_110 = (code *)0x0;
      lVar7 = *(longlong *)_Py_NoneStruct_exref + 1;
      pcVar14 = (code *)0x0;
      pcVar21 = _Py_NoneStruct_exref;
LAB_23e7a1e73:
      *(longlong *)pcVar21 = lVar7;
      lVar7 = *(longlong *)(*(longlong *)(param_1 + 0x38) + 8);
      plVar20 = *(longlong **)(lVar7 + 0x28);
      plVar9 = (longlong *)plVar20[2];
      *(undefined8 *)(*(longlong *)(param_1 + 0x38) + 8) = *(undefined8 *)(lVar7 + 0x30);
      *(undefined4 *)(plVar20 + 8) = 0xffffffff;
      if (plVar9 != (longlong *)0x0) {
        plVar20[2] = 0;
        *plVar9 = *plVar9 + -1;
        if (*plVar9 == 0) {
          (**(code **)(plVar9[1] + 0x30))();
        }
      }
      *plVar20 = *plVar20 + -1;
      if (*plVar20 == 0) {
        (**(code **)(plVar20[1] + 0x30))(plVar20);
      }
      plVar20[0xf] = 0;
      plVar12 = (longlong *)0x0;
      plVar9 = (longlong *)0x0;
      pcVar17 = (code *)0x0;
LAB_23e7a1edd:
      if ((plVar6 != (longlong *)0x0) && (*plVar6 = *plVar6 + -1, *plVar6 == 0)) {
        (**(code **)(plVar6[1] + 0x30))(plVar6);
      }
      if ((pcVar10 != (code *)0x0) &&
         (*(longlong *)pcVar10 = *(longlong *)pcVar10 + -1, *(longlong *)pcVar10 == 0)) {
        (**(code **)(*(longlong *)(pcVar10 + 8) + 0x30))(pcVar10);
      }
      if ((pcVar14 != (code *)0x0) &&
         (*(longlong *)pcVar14 = *(longlong *)pcVar14 + -1, *(longlong *)pcVar14 == 0)) {
        (**(code **)(*(longlong *)(pcVar14 + 8) + 0x30))(pcVar14);
      }
      if ((local_110 != (code *)0x0) &&
         (lVar7 = *(longlong *)local_110, *(longlong *)local_110 = lVar7 + -1, lVar7 + -1 == 0)) {
        (**(code **)(*(longlong *)(local_110 + 8) + 0x30))(local_110);
      }
      if ((pcVar17 != (code *)0x0) &&
         (*(longlong *)pcVar17 = *(longlong *)pcVar17 + -1, *(longlong *)pcVar17 == 0)) {
        (**(code **)(*(longlong *)(pcVar17 + 8) + 0x30))(pcVar17);
      }
      if ((plVar9 != (longlong *)0x0) && (*plVar9 = *plVar9 + -1, *plVar9 == 0)) {
        (**(code **)(plVar9[1] + 0x30))(plVar9);
      }
      if ((plVar12 != (longlong *)0x0) && (*plVar12 = *plVar12 + -1, *plVar12 == 0)) {
        (**(code **)(plVar12[1] + 0x30))(plVar12);
      }
      *plVar18 = *plVar18 + -1;
      if (*plVar18 != 0) {
        return pcVar21;
      }
      (**(code **)(plVar18[1] + 0x30))(plVar18);
      return pcVar21;
    }
    uVar8 = FUN_23a3a0d40(DAT_23ed6cf28);
    *(undefined4 *)(plVar20 + 5) = 0x1c0;
    plVar6 = (longlong *)FUN_23e94bb80(param_1,uVar8,_DAT_23eed8620);
    if (plVar6 == (longlong *)0x0) {
      local_88 = *(undefined1 (*) [16])(param_1 + 0x60);
      local_78[0] = *(longlong **)(param_1 + 0x70);
      *(undefined8 *)(param_1 + 0x70) = 0;
      *(undefined1 (*) [16])(param_1 + 0x60) = (undefined1  [16])0x0;
      if (local_78[0] == (longlong *)0x0) {
        plVar12 = (longlong *)0x0;
        plVar9 = (longlong *)0x0;
        pcVar17 = (code *)0x0;
        local_110 = (code *)0x0;
        pcVar14 = (code *)0x0;
        pcVar10 = (code *)0x0;
        uVar19 = 0x1c0;
        local_108 = _PyRuntime_exref;
        plVar6 = (longlong *)0x0;
        goto LAB_23e7a3300;
      }
      if (plVar20 != (longlong *)local_78[0][3]) {
        plVar12 = (longlong *)0x0;
        plVar9 = (longlong *)0x0;
        pcVar17 = (code *)0x0;
        local_110 = (code *)0x0;
        pcVar14 = (code *)0x0;
        pcVar10 = (code *)0x0;
        uVar19 = 0x1c0;
        local_108 = _PyRuntime_exref;
        plVar6 = (longlong *)0x0;
        goto LAB_23e7a2b85;
      }
    }
    else {
      *plVar6 = *plVar6 + -1;
      if (*plVar6 == 0) {
        (**(code **)(plVar6[1] + 0x30))(plVar6);
      }
      uVar8 = FUN_23a3a0d40(DAT_23ed6cf28);
      *(undefined4 *)(plVar20 + 5) = 0x1c1;
      plVar6 = (longlong *)FUN_23e94bb80(param_1,uVar8,_DAT_23eed8628);
      if (plVar6 == (longlong *)0x0) {
        local_88 = *(undefined1 (*) [16])(param_1 + 0x60);
        local_78[0] = *(longlong **)(param_1 + 0x70);
        *(undefined8 *)(param_1 + 0x70) = 0;
        *(undefined1 (*) [16])(param_1 + 0x60) = (undefined1  [16])0x0;
        if (local_78[0] == (longlong *)0x0) {
          plVar12 = (longlong *)0x0;
          plVar9 = (longlong *)0x0;
          pcVar17 = (code *)0x0;
          local_110 = (code *)0x0;
          pcVar14 = (code *)0x0;
          pcVar10 = (code *)0x0;
          uVar19 = 0x1c1;
          local_108 = _PyRuntime_exref;
          plVar6 = (longlong *)0x0;
          goto LAB_23e7a3300;
        }
        if (plVar20 != (longlong *)local_78[0][3]) {
          plVar12 = (longlong *)0x0;
          plVar9 = (longlong *)0x0;
          pcVar17 = (code *)0x0;
          local_110 = (code *)0x0;
          pcVar14 = (code *)0x0;
          pcVar10 = (code *)0x0;
          uVar19 = 0x1c1;
          local_108 = _PyRuntime_exref;
          plVar6 = (longlong *)0x0;
          goto LAB_23e7a2b85;
        }
      }
      else {
        *plVar6 = *plVar6 + -1;
        if (*plVar6 == 0) {
          (**(code **)(plVar6[1] + 0x30))(plVar6);
        }
        uVar8 = FUN_23a3a0d40(DAT_23ed6cf28);
        *(undefined4 *)(plVar20 + 5) = 0x1c2;
        plVar6 = (longlong *)FUN_23e94bb80(param_1,uVar8,_DAT_23eed8630);
        if (plVar6 == (longlong *)0x0) {
          local_88 = *(undefined1 (*) [16])(param_1 + 0x60);
          local_78[0] = *(longlong **)(param_1 + 0x70);
          *(undefined8 *)(param_1 + 0x70) = 0;
          *(undefined1 (*) [16])(param_1 + 0x60) = (undefined1  [16])0x0;
          if (local_78[0] == (longlong *)0x0) {
            local_108 = _PyRuntime_exref;
            plVar12 = (longlong *)0x0;
            plVar9 = (longlong *)0x0;
            pcVar17 = (code *)0x0;
            local_110 = (code *)0x0;
            pcVar14 = (code *)0x0;
            pcVar10 = (code *)0x0;
            uVar19 = 0x1c2;
            plVar6 = (longlong *)0x0;
            goto LAB_23e7a3300;
          }
          if (plVar20 != (longlong *)local_78[0][3]) {
            local_108 = _PyRuntime_exref;
            plVar12 = (longlong *)0x0;
            plVar9 = (longlong *)0x0;
            pcVar17 = (code *)0x0;
            local_110 = (code *)0x0;
            pcVar14 = (code *)0x0;
            pcVar10 = (code *)0x0;
            uVar19 = 0x1c2;
            plVar6 = (longlong *)0x0;
            goto LAB_23e7a2b85;
          }
        }
        else {
          *plVar6 = *plVar6 + -1;
          if (*plVar6 == 0) {
            (**(code **)(plVar6[1] + 0x30))(plVar6);
          }
          plVar9 = (longlong *)FUN_23a3a0d40(DAT_23ed6cf28);
          plVar12 = _DAT_23eed8638;
          lVar7 = *(longlong *)(param_1 + 0x10);
          plVar6 = *(longlong **)(lVar7 + 0xe20);
          if (plVar6 == (longlong *)0x0) {
            plVar6 = (longlong *)FUN_23e916a20(PyTuple_Type_exref,2);
          }
          else {
            lVar1 = plVar6[3];
            *(int *)(lVar7 + 0xebc) = *(int *)(lVar7 + 0xebc) + -1;
            *(longlong *)(lVar7 + 0xe20) = lVar1;
            *plVar6 = 1;
          }
          local_108 = _PyRuntime_exref;
          plVar6[4] = 0;
          lVar7 = *(longlong *)(*(longlong *)(*(longlong *)(local_108 + 0x1f8) + 0x10) + 0x2e8);
          lVar1 = plVar6[-1];
          puVar2 = *(undefined8 **)(lVar7 + 8);
          *puVar2 = plVar6 + -2;
          plVar6[-2] = lVar7;
          plVar6[-1] = (ulonglong)((uint)lVar1 & 3) | (ulonglong)puVar2;
          *(longlong **)(lVar7 + 8) = plVar6 + -2;
          uVar8 = _DAT_23eed82b0;
          *plVar12 = *plVar12 + 1;
          plVar6[3] = (longlong)plVar12;
          pcVar10 = (code *)FUN_23e8bc2f0(plVar18,uVar8);
          uVar8 = DAT_23ed6cd28;
          if (pcVar10 != (code *)0x0) {
            plVar12 = plVar18;
            plVar13 = plVar20;
            if (DAT_23ed6a4c0 == (longlong *)0x0) {
              plVar11 = (longlong *)PyDict_GetItemString(DAT_23ed6ccc0,"format");
              pcVar14 = pcVar10;
              if (plVar11 == (longlong *)0x0) goto LAB_23e7a36a4;
              *plVar11 = *plVar11 + 1;
              DAT_23ed6a4c0 = plVar11;
            }
            local_100 = &local_a8;
            uStack_a0 = uVar8;
            local_a8 = pcVar10;
            lVar7 = FUN_23e94ed00(param_1,DAT_23ed6a4c0,local_100);
            *(longlong *)pcVar10 = *(longlong *)pcVar10 + -1;
            if (*(longlong *)pcVar10 == 0) {
              (**(code **)(*(longlong *)(pcVar10 + 8) + 0x30))();
            }
            if (lVar7 == 0) goto LAB_23e7a2f00;
            plVar6[4] = lVar7;
            local_f8 = PyUnicode_Join_exref;
            plVar11 = (longlong *)PyUnicode_Join(DAT_23ed6cd28,plVar6);
            *plVar6 = *plVar6 + -1;
            if (*plVar6 == 0) {
              (**(code **)(plVar6[1] + 0x30))();
            }
            if (plVar11 != (longlong *)0x0) {
              *(undefined4 *)(plVar20 + 5) = 0x1c3;
              plVar6 = (longlong *)FUN_23e914090(param_1,plVar9,plVar11);
              *plVar11 = *plVar11 + -1;
              if (*plVar11 == 0) {
                (**(code **)(plVar11[1] + 0x30))();
              }
              if (plVar6 == (longlong *)0x0) {
                local_88 = *(undefined1 (*) [16])(param_1 + 0x60);
                local_78[0] = *(longlong **)(param_1 + 0x70);
                *(undefined8 *)(param_1 + 0x70) = 0;
                *(undefined1 (*) [16])(param_1 + 0x60) = (undefined1  [16])0x0;
                if (local_78[0] == (longlong *)0x0) goto LAB_23e7a3410;
                if ((longlong *)local_78[0][3] != plVar20) {
                  local_110 = (code *)0x0;
                  plVar12 = (longlong *)0x0;
                  pcVar17 = (code *)0x0;
                  plVar6 = (longlong *)0x0;
                  plVar9 = (longlong *)0x0;
                  pcVar14 = (code *)0x0;
                  uVar19 = 0x1c3;
                  pcVar10 = (code *)0x0;
                  goto LAB_23e7a2b85;
                }
                goto LAB_23e7a2eb0;
              }
              *plVar6 = *plVar6 + -1;
              if (*plVar6 == 0) {
                (**(code **)(plVar6[1] + 0x30))(plVar6);
              }
              plVar9 = (longlong *)FUN_23a3a0d40(DAT_23ed6cf28);
              plVar11 = _DAT_23eed8640;
              lVar7 = *(longlong *)(param_1 + 0x10);
              plVar6 = *(longlong **)(lVar7 + 0xe50);
              if (plVar6 == (longlong *)0x0) {
                plVar6 = (longlong *)FUN_23e916a20(PyTuple_Type_exref,8);
              }
              else {
                lVar1 = plVar6[3];
                *(int *)(lVar7 + 0xed4) = *(int *)(lVar7 + 0xed4) + -1;
                *(longlong *)(lVar7 + 0xe50) = lVar1;
                *plVar6 = 1;
              }
              *(undefined1 (*) [16])(plVar6 + 3) = (undefined1  [16])0x0;
              *(undefined1 (*) [16])(plVar6 + 5) = (undefined1  [16])0x0;
              *(undefined1 (*) [16])(plVar6 + 7) = (undefined1  [16])0x0;
              *(undefined1 (*) [16])(plVar6 + 9) = (undefined1  [16])0x0;
              lVar7 = *(longlong *)(*(longlong *)(*(longlong *)(local_108 + 0x1f8) + 0x10) + 0x2e8);
              lVar1 = plVar6[-1];
              puVar2 = *(undefined8 **)(lVar7 + 8);
              *puVar2 = plVar6 + -2;
              plVar6[-2] = lVar7;
              plVar6[-1] = (ulonglong)((uint)lVar1 & 3) | (ulonglong)puVar2;
              *(longlong **)(lVar7 + 8) = plVar6 + -2;
              uVar8 = DAT_23eed82b8;
              *plVar11 = *plVar11 + 1;
              plVar6[3] = (longlong)plVar11;
              plVar11 = (longlong *)FUN_23e8bc2f0(plVar18,uVar8);
              if (plVar11 == (longlong *)0x0) {
LAB_23e7a2ab0:
                local_88 = *(undefined1 (*) [16])(param_1 + 0x60);
                local_78[0] = *(longlong **)(param_1 + 0x70);
                uVar19 = 0x1c4;
              }
              else {
                pcVar10 = (code *)FUN_23a38cc10(param_1,plVar11,DAT_23eed8338);
                *plVar11 = *plVar11 + -1;
                if (*plVar11 == 0) {
                  (**(code **)(plVar11[1] + 0x30))();
                }
                uVar8 = DAT_23ed6cd28;
                if (pcVar10 == (code *)0x0) goto LAB_23e7a2ab0;
                if (DAT_23ed6a4c0 == (longlong *)0x0) {
                  plVar11 = (longlong *)PyDict_GetItemString(DAT_23ed6ccc0,"format");
                  pcVar14 = pcVar10;
                  if (plVar11 == (longlong *)0x0) goto LAB_23e7a36a4;
                  *plVar11 = *plVar11 + 1;
                  DAT_23ed6a4c0 = plVar11;
                }
                uStack_a0 = uVar8;
                local_a8 = pcVar10;
                lVar7 = FUN_23e94ed00(param_1,DAT_23ed6a4c0,local_100);
                *(longlong *)pcVar10 = *(longlong *)pcVar10 + -1;
                if (*(longlong *)pcVar10 == 0) {
                  (**(code **)(*(longlong *)(pcVar10 + 8) + 0x30))();
                }
                plVar11 = _DAT_23eed8648;
                if (lVar7 == 0) goto LAB_23e7a2ab0;
                plVar6[4] = lVar7;
                uVar8 = DAT_23eed82b8;
                *plVar11 = *plVar11 + 1;
                plVar6[5] = (longlong)plVar11;
                plVar11 = (longlong *)FUN_23e8bc2f0(plVar18,uVar8);
                if (plVar11 == (longlong *)0x0) goto LAB_23e7a2ab0;
                pcVar10 = (code *)FUN_23a38cc10(param_1,plVar11,DAT_23eed8410);
                *plVar11 = *plVar11 + -1;
                if (*plVar11 == 0) {
                  (**(code **)(plVar11[1] + 0x30))();
                }
                uVar8 = DAT_23ed6cd28;
                if (pcVar10 == (code *)0x0) goto LAB_23e7a2ab0;
                if (DAT_23ed6a4c0 == (longlong *)0x0) {
                  plVar11 = (longlong *)PyDict_GetItemString(DAT_23ed6ccc0,"format");
                  pcVar14 = pcVar10;
                  if (plVar11 == (longlong *)0x0) goto LAB_23e7a36a4;
                  *plVar11 = *plVar11 + 1;
                  DAT_23ed6a4c0 = plVar11;
                }
                uStack_a0 = uVar8;
                local_a8 = pcVar10;
                lVar7 = FUN_23e94ed00(param_1,DAT_23ed6a4c0,local_100);
                *(longlong *)pcVar10 = *(longlong *)pcVar10 + -1;
                if (*(longlong *)pcVar10 == 0) {
                  (**(code **)(*(longlong *)(pcVar10 + 8) + 0x30))();
                }
                plVar11 = _DAT_23eed8650;
                if (lVar7 == 0) goto LAB_23e7a2ab0;
                plVar6[6] = lVar7;
                uVar8 = DAT_23eed82b8;
                *plVar11 = *plVar11 + 1;
                plVar6[7] = (longlong)plVar11;
                plVar11 = (longlong *)FUN_23e8bc2f0(plVar18,uVar8);
                if (plVar11 != (longlong *)0x0) {
                  pcVar10 = (code *)FUN_23a38cc10(param_1,plVar11,DAT_23eed8420);
                  *plVar11 = *plVar11 + -1;
                  if (*plVar11 == 0) {
                    (**(code **)(plVar11[1] + 0x30))();
                  }
                  if (pcVar10 != (code *)0x0) {
                    pcVar14 = pcVar10;
                    uVar8 = DAT_23ed6cd28;
                    if (DAT_23ed6a4c0 == (longlong *)0x0) goto LAB_23e7a36b7;
                    while( true ) {
                      local_a8 = pcVar14;
                      uStack_a0 = uVar8;
                      lVar7 = FUN_23e94ed00(param_1,DAT_23ed6a4c0,local_100);
                      *(longlong *)pcVar10 = *(longlong *)pcVar10 + -1;
                      if (*(longlong *)pcVar10 == 0) {
                        (**(code **)(*(longlong *)(pcVar10 + 8) + 0x30))();
                      }
                      plVar12 = _DAT_23eed8658;
                      if (lVar7 == 0) goto LAB_23e7a3170;
                      plVar6[8] = lVar7;
                      uVar8 = DAT_23eed82b8;
                      *plVar12 = *plVar12 + 1;
                      plVar6[9] = (longlong)plVar12;
                      plVar12 = (longlong *)FUN_23e8bc2f0(plVar18,uVar8);
                      if (plVar12 == (longlong *)0x0) goto LAB_23e7a3170;
                      pcVar10 = (code *)FUN_23a38cc10(param_1,plVar12,DAT_23eed8418);
                      *plVar12 = *plVar12 + -1;
                      if (*plVar12 == 0) {
                        (**(code **)(plVar12[1] + 0x30))();
                      }
                      uVar8 = DAT_23ed6cd28;
                      if (pcVar10 == (code *)0x0) goto LAB_23e7a3170;
                      if (DAT_23ed6a4c0 != (longlong *)0x0) break;
                      plVar11 = (longlong *)PyDict_GetItemString(DAT_23ed6ccc0,"format");
                      plVar12 = plVar18;
                      plVar13 = plVar20;
                      pcVar14 = pcVar10;
                      if (plVar11 != (longlong *)0x0) {
                        *plVar11 = *plVar11 + 1;
                        DAT_23ed6a4c0 = plVar11;
                        break;
                      }
LAB_23e7a36a4:
                      do {
                        PyErr_PrintEx(0,0);
                        Py_Exit(1);
LAB_23e7a36b7:
                        plVar11 = (longlong *)PyDict_GetItemString(DAT_23ed6ccc0,"format");
                      } while (plVar11 == (longlong *)0x0);
                      *plVar11 = *plVar11 + 1;
                      plVar18 = plVar12;
                      plVar20 = plVar13;
                      DAT_23ed6a4c0 = plVar11;
                    }
                    uStack_a0 = uVar8;
                    local_a8 = pcVar10;
                    lVar7 = FUN_23e94ed00(param_1,DAT_23ed6a4c0,local_100);
                    *(longlong *)pcVar10 = *(longlong *)pcVar10 + -1;
                    if (*(longlong *)pcVar10 == 0) {
                      (**(code **)(*(longlong *)(pcVar10 + 8) + 0x30))();
                    }
                    if (lVar7 != 0) {
                      plVar6[10] = lVar7;
                      plVar12 = (longlong *)(*local_f8)();
                      *plVar6 = *plVar6 + -1;
                      if (*plVar6 == 0) {
                        (**(code **)(plVar6[1] + 0x30))();
                      }
                      if (plVar12 == (longlong *)0x0) {
                        local_88 = *(undefined1 (*) [16])(param_1 + 0x60);
                        local_78[0] = *(longlong **)(param_1 + 0x70);
                        *(undefined8 *)(param_1 + 0x70) = 0;
                        *(undefined1 (*) [16])(param_1 + 0x60) = (undefined1  [16])0x0;
                        if (local_78[0] != (longlong *)0x0) {
                          if ((longlong *)local_78[0][3] == plVar20) goto LAB_23e7a2eb0;
                          plVar12 = (longlong *)0x0;
                          plVar9 = (longlong *)0x0;
                          pcVar17 = (code *)0x0;
                          local_110 = (code *)0x0;
                          pcVar14 = (code *)0x0;
                          pcVar10 = (code *)0x0;
                          uVar19 = 0x1c4;
                          plVar6 = (longlong *)0x0;
                          goto LAB_23e7a2b85;
                        }
                      }
                      else {
                        *(undefined4 *)(plVar20 + 5) = 0x1c4;
                        plVar6 = (longlong *)FUN_23e914090(param_1,plVar9,plVar12);
                        *plVar12 = *plVar12 + -1;
                        if (*plVar12 == 0) {
                          (**(code **)(plVar12[1] + 0x30))();
                        }
                        if (plVar6 != (longlong *)0x0) {
                          *plVar6 = *plVar6 + -1;
                          if (*plVar6 == 0) {
                            (**(code **)(plVar6[1] + 0x30))(plVar6);
                          }
                          uVar8 = FUN_23a3a0d40(DAT_23ed6cf28);
                          *(undefined4 *)(plVar20 + 5) = 0x1c6;
                          plVar6 = (longlong *)FUN_23e94bb80(param_1,uVar8,_DAT_23eed8660);
                          if (plVar6 != (longlong *)0x0) {
                            *plVar6 = *plVar6 + -1;
                            if (*plVar6 == 0) {
                              (**(code **)(plVar6[1] + 0x30))(plVar6);
                            }
                            plVar6 = (longlong *)FUN_23e8bc2f0(plVar18,DAT_23eed8308);
                            if (plVar6 == (longlong *)0x0) {
                              local_88 = *(undefined1 (*) [16])(param_1 + 0x60);
                              local_78[0] = *(longlong **)(param_1 + 0x70);
                              *(undefined8 *)(param_1 + 0x70) = 0;
                              *(undefined1 (*) [16])(param_1 + 0x60) = (undefined1  [16])0x0;
                              if (local_78[0] != (longlong *)0x0) {
                                if ((longlong *)local_78[0][3] == plVar20) goto LAB_23e7a2eb0;
LAB_23e7a3d3a:
                                plVar6 = (longlong *)0x0;
                                plVar12 = (longlong *)0x0;
                                plVar9 = (longlong *)0x0;
                                pcVar17 = (code *)0x0;
                                local_110 = (code *)0x0;
                                pcVar14 = (code *)0x0;
                                pcVar10 = (code *)0x0;
                                uVar19 = 0x1c7;
                                goto LAB_23e7a2b85;
                              }
                            }
                            else {
                              plVar9 = (longlong *)FUN_23e8bc2f0(plVar6,_DAT_23eed8668);
                              *plVar6 = *plVar6 + -1;
                              if (*plVar6 == 0) {
                                (**(code **)(plVar6[1] + 0x30))();
                              }
                              if (plVar9 == (longlong *)0x0) {
                                local_88 = *(undefined1 (*) [16])(param_1 + 0x60);
                                local_78[0] = *(longlong **)(param_1 + 0x70);
                                *(undefined8 *)(param_1 + 0x70) = 0;
                                *(undefined1 (*) [16])(param_1 + 0x60) = (undefined1  [16])0x0;
                                if (local_78[0] != (longlong *)0x0) {
                                  if (plVar20 == (longlong *)local_78[0][3]) goto LAB_23e7a2eb0;
                                  plVar12 = (longlong *)0x0;
                                  plVar9 = (longlong *)0x0;
                                  pcVar17 = (code *)0x0;
                                  local_110 = (code *)0x0;
                                  pcVar14 = (code *)0x0;
                                  plVar6 = (longlong *)0x0;
                                  uVar19 = 0x1c7;
                                  pcVar10 = (code *)0x0;
                                  goto LAB_23e7a2b85;
                                }
                              }
                              else {
                                *(undefined4 *)(plVar20 + 5) = 0x1c7;
                                plVar6 = (longlong *)FUN_23e91a870();
                                *plVar9 = *plVar9 + -1;
                                if (*plVar9 == 0) {
                                  (**(code **)(plVar9[1] + 0x30))();
                                }
                                if (plVar6 == (longlong *)0x0) {
                                  local_88 = *(undefined1 (*) [16])(param_1 + 0x60);
                                  local_78[0] = *(longlong **)(param_1 + 0x70);
                                  *(undefined8 *)(param_1 + 0x70) = 0;
                                  *(undefined1 (*) [16])(param_1 + 0x60) = (undefined1  [16])0x0;
                                  if (local_78[0] != (longlong *)0x0) {
                                    if (plVar20 != (longlong *)local_78[0][3]) goto LAB_23e7a3d3a;
                                    goto LAB_23e7a2eb0;
                                  }
                                }
                                else {
                                  plVar11 = (longlong *)FUN_23ebf7180();
                                  *plVar6 = *plVar6 + -1;
                                  if (*plVar6 == 0) {
                                    (**(code **)(plVar6[1] + 0x30))();
                                  }
                                  pcVar10 = (code *)0x0;
                                  plVar6 = (longlong *)0x0;
                                  plVar16 = (longlong *)0x0;
                                  pcVar14 = (code *)0x0;
                                  if (plVar11 != (longlong *)0x0) {
LAB_23e7a27b0:
                                    pcVar10 = pcVar14;
                                    pcVar14 = *(code **)(plVar11[1] + 0xe0);
                                    if (pcVar14 == (code *)0x0) {
                                      PyErr_Format(*(undefined8 *)PyExc_TypeError_exref,
                                                   "\'%s\' object is not an iterator",
                                                   *(undefined8 *)(plVar11[1] + 0x18));
LAB_23e7a3804:
                                      cVar4 = FUN_23a3591a0(param_1,*(undefined8 *)
                                                                     PyExc_StopIteration_exref);
                                      if (cVar4 == '\0') {
                                        pcVar17 = *(code **)(param_1 + 0x60);
                                        uVar8 = *(undefined8 *)(param_1 + 0x68);
                                        plVar15 = *(longlong **)(param_1 + 0x70);
                                        local_78[0] = (longlong *)0x0;
                                        *(undefined8 *)(param_1 + 0x70) = 0;
                                        *(undefined1 (*) [16])(param_1 + 0x60) =
                                             (undefined1  [16])0x0;
                                        local_88 = (undefined1  [16])0x0;
                                        if (plVar16 != (longlong *)0x0) {
                                          uVar19 = 0x1c7;
                                          goto LAB_23e7a35db;
                                        }
                                        uVar19 = 0x1c7;
                                        goto LAB_23e7a361e;
                                      }
                                      if ((plVar16 != (longlong *)0x0) &&
                                         (*plVar16 = *plVar16 + -1, *plVar16 == 0)) {
                                        FUN_23a334bc0(plVar16);
                                      }
                                      *plVar11 = *plVar11 + -1;
                                      if (*plVar11 == 0) {
                                        FUN_23a334bc0(plVar11);
                                      }
                                      uVar8 = FUN_23a3a0d40(DAT_23ed6cf28);
                                      *(undefined4 *)(plVar20 + 5) = 0x1c9;
                                      plVar9 = (longlong *)
                                               FUN_23e94bb80(param_1,uVar8,_DAT_23eed8678);
                                      if (plVar9 == (longlong *)0x0) {
                                        local_88 = *(undefined1 (*) [16])(param_1 + 0x60);
                                        local_78[0] = *(longlong **)(param_1 + 0x70);
                                        *(undefined8 *)(param_1 + 0x70) = 0;
                                        *(undefined1 (*) [16])(param_1 + 0x60) =
                                             (undefined1  [16])0x0;
                                        local_110 = (code *)0x0;
                                        if (local_78[0] == (longlong *)0x0) {
                                          plVar12 = (longlong *)0x0;
                                          plVar9 = (longlong *)0x0;
                                          pcVar17 = (code *)0x0;
                                          uVar19 = 0x1c9;
                                          pcVar14 = (code *)0x0;
                                          goto LAB_23e7a3300;
                                        }
                                        if (plVar20 == (longlong *)local_78[0][3]) {
                                          plVar12 = (longlong *)0x0;
                                          plVar9 = (longlong *)0x0;
                                          pcVar17 = (code *)0x0;
                                          pcVar14 = (code *)0x0;
                                          plVar15 = local_78[0];
                                          goto LAB_23e7a2c44;
                                        }
                                        plVar12 = (longlong *)0x0;
                                        plVar9 = (longlong *)0x0;
                                        pcVar17 = (code *)0x0;
                                        pcVar14 = (code *)0x0;
                                        uVar19 = 0x1c9;
                                        goto LAB_23e7a2b85;
                                      }
                                      lVar7 = *plVar9;
                                      *plVar9 = lVar7 + -1;
                                      if (lVar7 + -1 == 0) {
                                        FUN_23a334bc0(plVar9);
                                      }
                                      uVar8 = FUN_23a3a0d40(DAT_23ed6cf28);
                                      *(undefined4 *)(plVar20 + 5) = 0x1cd;
                                      plVar9 = (longlong *)FUN_23e94bb80(param_1,uVar8);
                                      if (plVar9 == (longlong *)0x0) {
                                        pcVar21 = *(code **)(param_1 + 0x60);
                                        plVar13 = *(longlong **)(param_1 + 0x70);
                                        *(undefined8 *)(param_1 + 0x70) = 0;
                                        plVar12 = (longlong *)0x0;
                                        plVar9 = (longlong *)0x0;
                                        pcVar17 = (code *)0x0;
                                        uVar19 = 0x1cd;
                                        local_110 = (code *)0x0;
                                        *(undefined1 (*) [16])(param_1 + 0x60) =
                                             (undefined1  [16])0x0;
                                        pcVar14 = (code *)0x0;
                                        uVar8 = *(undefined8 *)(param_1 + 0x68);
                                        goto LAB_23e7a416b;
                                      }
                                      *plVar9 = *plVar9 + -1;
                                      if (*plVar9 == 0) {
                                        FUN_23a334bc0(plVar9);
                                      }
                                      plVar9 = (longlong *)FUN_23e8bc2f0(plVar18,DAT_23eed82a8);
                                      if (plVar9 != (longlong *)0x0) {
                                        *(undefined4 *)(plVar20 + 5) = 0x1ce;
                                        pcVar14 = (code *)FUN_23e91bfe0(param_1,plVar9,DAT_23eed82a8
                                                                       );
                                        *plVar9 = *plVar9 + -1;
                                        if (*plVar9 == 0) {
                                          FUN_23a334bc0(plVar9);
                                        }
                                        pcVar21 = _Py_NoneStruct_exref;
                                        uVar8 = DAT_23eed8690;
                                        if (pcVar14 != (code *)0x0) {
                                          if (pcVar14 == _Py_NoneStruct_exref) {
                                            uVar8 = FUN_23a3a0d40(DAT_23ed6cf28);
                                            *(undefined4 *)(plVar20 + 5) = 0x1d0;
                                            plVar9 = (longlong *)
                                                     FUN_23e94bb80(param_1,uVar8,_DAT_23eed8688);
                                            if (plVar9 == (longlong *)0x0) {
                                              pcVar21 = *(code **)(param_1 + 0x60);
                                              plVar13 = *(longlong **)(param_1 + 0x70);
                                              plVar12 = (longlong *)0x0;
                                              *(undefined8 *)(param_1 + 0x70) = 0;
                                              plVar9 = (longlong *)0x0;
                                              pcVar17 = (code *)0x0;
                                              uVar19 = 0x1d0;
                                              *(undefined1 (*) [16])(param_1 + 0x60) =
                                                   (undefined1  [16])0x0;
                                              local_110 = (code *)0x0;
                                              uVar8 = *(undefined8 *)(param_1 + 0x68);
                                              goto LAB_23e7a416b;
                                            }
                                            lVar7 = *plVar9;
                                            *plVar9 = lVar7 + -1;
                                            if (lVar7 + -1 == 0) {
                                              FUN_23a334bc0(plVar9);
                                            }
                                            local_110 = (code *)0x0;
                                            lVar7 = *(longlong *)pcVar21 + 1;
                                            pcVar14 = pcVar21;
                                            goto LAB_23e7a1e73;
                                          }
                                          *(undefined4 *)(plVar20 + 5) = 0x1d4;
                                          local_110 = (code *)FUN_23e915840(param_1,plVar18,uVar8);
                                          if (local_110 == (code *)0x0) {
                                            pcVar21 = *(code **)(param_1 + 0x60);
                                            plVar13 = *(longlong **)(param_1 + 0x70);
                                            plVar12 = (longlong *)0x0;
                                            *(undefined8 *)(param_1 + 0x70) = 0;
                                            plVar9 = (longlong *)0x0;
                                            pcVar17 = (code *)0x0;
                                            uVar19 = 0x1d4;
                                            *(undefined1 (*) [16])(param_1 + 0x60) =
                                                 (undefined1  [16])0x0;
                                            uVar8 = *(undefined8 *)(param_1 + 0x68);
                                            goto LAB_23e7a416b;
                                          }
                                          iVar5 = FUN_23a35f020(local_110);
                                          if (iVar5 == -1) {
                                            pcVar21 = *(code **)(param_1 + 0x60);
                                            plVar13 = *(longlong **)(param_1 + 0x70);
                                            plVar9 = (longlong *)0x0;
                                            *(undefined8 *)(param_1 + 0x70) = 0;
                                            uVar19 = 0x1d6;
                                            plVar12 = (longlong *)0x0;
                                            pcVar17 = (code *)0x0;
                                            *(undefined1 (*) [16])(param_1 + 0x60) =
                                                 (undefined1  [16])0x0;
                                            uVar8 = *(undefined8 *)(param_1 + 0x68);
                                            goto LAB_23e7a416b;
                                          }
                                          if (iVar5 == 0) {
                                            uVar8 = FUN_23a3a0d40(DAT_23ed6cf28);
                                            *(undefined4 *)(plVar20 + 5) = 0x1d7;
                                            plVar9 = (longlong *)
                                                     FUN_23e94bb80(param_1,uVar8,_DAT_23eed8698);
                                            if (plVar9 == (longlong *)0x0) {
                                              pcVar21 = *(code **)(param_1 + 0x60);
                                              plVar13 = *(longlong **)(param_1 + 0x70);
                                              plVar12 = (longlong *)0x0;
                                              *(undefined8 *)(param_1 + 0x70) = 0;
                                              uVar19 = 0x1d7;
                                              plVar9 = (longlong *)0x0;
                                              *(undefined1 (*) [16])(param_1 + 0x60) =
                                                   (undefined1  [16])0x0;
                                              pcVar17 = (code *)0x0;
                                              uVar8 = *(undefined8 *)(param_1 + 0x68);
                                              goto LAB_23e7a416b;
                                            }
                                            *plVar9 = *plVar9 + -1;
                                            if (*plVar9 == 0) {
                                              FUN_23a334bc0(plVar9);
                                            }
                                            lVar7 = *(longlong *)pcVar21 + 1;
                                            goto LAB_23e7a1e73;
                                          }
                                          uVar8 = FUN_23a3a0d40(DAT_23ed6cf28);
                                          plVar9 = _DAT_23eed86a0;
                                          plVar12 = (longlong *)
                                                    FUN_23e916ad0(*(undefined8 *)(param_1 + 0x10),2)
                                          ;
                                          *plVar9 = *plVar9 + 1;
                                          plVar12[3] = (longlong)plVar9;
                                          plVar9 = (longlong *)FUN_23e8bd600(param_1,local_110);
                                          if (plVar9 == (longlong *)0x0) {
LAB_23e7a5f6b:
                                            local_88._0_8_ = *(undefined8 *)(param_1 + 0x60);
                                            local_88._8_8_ = *(undefined8 *)(param_1 + 0x68);
                                            local_78[0] = *(longlong **)(param_1 + 0x70);
                                            *(undefined8 *)(param_1 + 0x70) = 0;
                                            *(undefined1 (*) [16])(param_1 + 0x60) =
                                                 (undefined1  [16])0x0;
                                            *plVar12 = *plVar12 + -1;
                                            if (*plVar12 == 0) {
                                              FUN_23a334bc0(plVar12);
                                            }
                                          }
                                          else {
                                            lVar7 = FUN_23e94f9d0(param_1,plVar9,DAT_23ed6cd28);
                                            *plVar9 = *plVar9 + -1;
                                            if (*plVar9 == 0) {
                                              FUN_23a334bc0(plVar9);
                                            }
                                            if (lVar7 == 0) goto LAB_23e7a5f6b;
                                            plVar12[4] = lVar7;
                                            plVar9 = (longlong *)(*local_f8)(DAT_23ed6cd28,plVar12);
                                            *plVar12 = *plVar12 + -1;
                                            if (*plVar12 == 0) {
                                              FUN_23a334bc0(plVar12);
                                            }
                                            if (plVar9 == (longlong *)0x0) {
                                              pcVar21 = *(code **)(param_1 + 0x60);
                                              plVar13 = *(longlong **)(param_1 + 0x70);
                                              plVar12 = (longlong *)0x0;
                                              *(undefined8 *)(param_1 + 0x70) = 0;
                                              plVar9 = (longlong *)0x0;
                                              uVar19 = 0x1da;
                                              *(undefined1 (*) [16])(param_1 + 0x60) =
                                                   (undefined1  [16])0x0;
                                              pcVar17 = (code *)0x0;
                                              uVar8 = *(undefined8 *)(param_1 + 0x68);
                                              goto LAB_23e7a416b;
                                            }
                                            *(undefined4 *)(plVar20 + 5) = 0x1da;
                                            plVar12 = (longlong *)FUN_23e914090(param_1,uVar8);
                                            *plVar9 = *plVar9 + -1;
                                            if (*plVar9 == 0) {
                                              FUN_23a334bc0(plVar9);
                                            }
                                            if (plVar12 != (longlong *)0x0) {
                                              *plVar12 = *plVar12 + -1;
                                              if (*plVar12 == 0) {
                                                FUN_23a334bc0(plVar12);
                                              }
                                              uVar8 = FUN_23a3a0d40(DAT_23ed6cf28);
                                              *(undefined4 *)(plVar20 + 5) = 0x1db;
                                              plVar9 = (longlong *)
                                                       FUN_23e94bb80(param_1,uVar8,_DAT_23eed8630);
                                              if (plVar9 == (longlong *)0x0) {
                                                pcVar21 = *(code **)(param_1 + 0x60);
                                                plVar13 = *(longlong **)(param_1 + 0x70);
                                                plVar12 = (longlong *)0x0;
                                                *(undefined8 *)(param_1 + 0x70) = 0;
                                                plVar9 = (longlong *)0x0;
                                                uVar19 = 0x1db;
                                                *(undefined1 (*) [16])(param_1 + 0x60) =
                                                     (undefined1  [16])0x0;
                                                pcVar17 = (code *)0x0;
                                                uVar8 = *(undefined8 *)(param_1 + 0x68);
                                                goto LAB_23e7a416b;
                                              }
                                              *plVar9 = *plVar9 + -1;
                                              if (*plVar9 == 0) {
                                                FUN_23a334bc0(plVar9);
                                              }
                                              pcVar3 = PyEnum_Type_exref;
                                              uStack_a0 = DAT_23ed6ccf8;
                                              pcVar17 = DAT_23ed6ccf0;
                                              *(longlong *)DAT_23ed6ccf0 =
                                                   *(longlong *)DAT_23ed6ccf0 + 1;
                                              *(undefined4 *)(plVar20 + 5) = 0x1df;
                                              local_a8 = local_110;
                                              plVar9 = (longlong *)
                                                       FUN_23e94ed00(param_1,pcVar3,local_100);
                                              if (plVar9 == (longlong *)0x0) {
                                                pcVar21 = *(code **)(param_1 + 0x60);
                                                plVar13 = *(longlong **)(param_1 + 0x70);
                                                plVar12 = (longlong *)0x0;
                                                *(undefined8 *)(param_1 + 0x70) = 0;
                                                uVar19 = 0x1df;
                                                *(undefined1 (*) [16])(param_1 + 0x60) =
                                                     (undefined1  [16])0x0;
                                                plVar9 = (longlong *)0x0;
                                                uVar8 = *(undefined8 *)(param_1 + 0x68);
                                                goto LAB_23e7a416b;
                                              }
                                              plVar11 = (longlong *)FUN_23ebf7180(plVar9);
                                              *plVar9 = *plVar9 + -1;
                                              if (*plVar9 == 0) {
                                                FUN_23a334bc0(plVar9);
                                              }
                                              if (plVar11 == (longlong *)0x0) {
                                                pcVar21 = *(code **)(param_1 + 0x60);
                                                plVar13 = *(longlong **)(param_1 + 0x70);
                                                plVar12 = (longlong *)0x0;
                                                plVar9 = (longlong *)0x0;
                                                uVar19 = 0x1df;
                                                *(undefined8 *)(param_1 + 0x70) = 0;
                                                *(undefined1 (*) [16])(param_1 + 0x60) =
                                                     (undefined1  [16])0x0;
                                                uVar8 = *(undefined8 *)(param_1 + 0x68);
                                                goto LAB_23e7a416b;
                                              }
                                              local_d0 = (longlong *)0x0;
                                              plVar9 = (longlong *)0x0;
                                              plVar12 = (longlong *)0x0;
                                              goto LAB_23e7a4ad6;
                                            }
                                            local_78[0] = *(longlong **)(param_1 + 0x70);
                                            local_88._0_8_ = *(undefined8 *)(param_1 + 0x60);
                                            local_88._8_8_ = *(undefined8 *)(param_1 + 0x68);
                                            *(undefined8 *)(param_1 + 0x70) = 0;
                                            *(undefined1 (*) [16])(param_1 + 0x60) =
                                                 (undefined1  [16])0x0;
                                          }
                                          uVar19 = 0x1da;
                                          plVar12 = (longlong *)0x0;
                                          plVar9 = (longlong *)0x0;
                                          pcVar17 = (code *)0x0;
                                          plVar13 = local_78[0];
                                          pcVar21 = (code *)local_88._0_8_;
                                          uVar8 = local_88._8_8_;
                                          goto LAB_23e7a416b;
                                        }
                                      }
                                      plVar13 = *(longlong **)(param_1 + 0x70);
                                      pcVar21 = *(code **)(param_1 + 0x60);
                                      uVar19 = 0x1ce;
                                      pcVar17 = (code *)0x0;
                                      plVar12 = (longlong *)0x0;
                                      plVar9 = (longlong *)0x0;
                                      pcVar14 = (code *)0x0;
                                      *(undefined8 *)(param_1 + 0x70) = 0;
                                      local_110 = (code *)0x0;
                                      *(undefined1 (*) [16])(param_1 + 0x60) = (undefined1  [16])0x0
                                      ;
                                      uVar8 = *(undefined8 *)(param_1 + 0x68);
                                      goto LAB_23e7a416b;
                                    }
                                    plVar13 = (longlong *)(*pcVar14)(plVar11);
                                    if (plVar13 == (longlong *)0x0) goto LAB_23e7a3804;
                                    if ((plVar16 != (longlong *)0x0) &&
                                       (*plVar16 = *plVar16 + -1, *plVar16 == 0)) {
                                      (**(code **)(plVar16[1] + 0x30))(plVar16);
                                    }
                                    plVar9 = (longlong *)FUN_23a388310();
                                    plVar16 = plVar13;
                                    if (plVar9 == (longlong *)0x0) {
                                      pcVar17 = *(code **)(param_1 + 0x60);
                                      uVar8 = *(undefined8 *)(param_1 + 0x68);
                                      plVar15 = *(longlong **)(param_1 + 0x70);
                                      *(undefined8 *)(param_1 + 0x70) = 0;
                                      *(undefined1 (*) [16])(param_1 + 0x60) = (undefined1  [16])0x0
                                      ;
LAB_23e7a3bb7:
                                      uVar19 = 0x1c7;
                                      goto LAB_23e7a35db;
                                    }
                                    plVar12 = (longlong *)(**(code **)(plVar9[1] + 0xe0))(plVar9);
                                    if ((plVar12 == (longlong *)0x0) &&
                                       (plVar12 = (longlong *)FUN_23a3c1b70(param_1,local_88,0,2),
                                       plVar15 = local_78[0], uVar8 = local_88._8_8_,
                                       pcVar17 = (code *)local_88._0_8_, plVar12 == (longlong *)0x0)
                                       ) {
                                      local_78[0] = (longlong *)0x0;
                                      local_88 = (undefined1  [16])0x0;
                                      *plVar9 = *plVar9 + -1;
                                      if (*plVar9 == 0) {
                                        FUN_23a334bc0();
                                      }
                                      goto LAB_23e7a3bb7;
                                    }
                                    pcVar14 = (code *)(**(code **)(plVar9[1] + 0xe0))(plVar9);
                                    if ((pcVar14 == (code *)0x0) &&
                                       (pcVar14 = (code *)FUN_23a3c1b70(param_1,local_88,1,2),
                                       pcVar14 == (code *)0x0)) {
                                      lVar7 = *plVar9;
LAB_23e7a3afc:
                                      plVar15 = local_78[0];
                                      uVar8 = local_88._8_8_;
                                      pcVar17 = (code *)local_88._0_8_;
                                      local_88 = (undefined1  [16])0x0;
                                      local_78[0] = (longlong *)0x0;
                                      *plVar9 = lVar7 + -1;
                                      if (lVar7 + -1 == 0) {
                                        FUN_23a334bc0();
                                      }
                                      local_78[0] = (longlong *)0x0;
                                      local_88 = (undefined1  [16])0x0;
                                      lVar7 = *plVar12;
                                      *plVar12 = lVar7 + -1;
                                      if (lVar7 + -1 == 0) {
                                        FUN_23a334bc0();
                                      }
                                      if ((pcVar14 != (code *)0x0) &&
                                         (*(longlong *)pcVar14 = *(longlong *)pcVar14 + -1,
                                         *(longlong *)pcVar14 == 0)) {
                                        FUN_23a334bc0();
                                      }
                                      goto LAB_23e7a3bb7;
                                    }
                                    cVar4 = FUN_23a3884a0(param_1,local_88,plVar9);
                                    lVar7 = *plVar9;
                                    if (cVar4 == '\0') goto LAB_23e7a3afc;
                                    *plVar9 = lVar7 + -1;
                                    if (lVar7 + -1 == 0) {
                                      (**(code **)(plVar9[1] + 0x30))(plVar9);
                                    }
                                    lVar7 = *plVar12;
                                    *plVar12 = lVar7 + 1;
                                    if (plVar6 != (longlong *)0x0) {
                                      *plVar6 = *plVar6 + -1;
                                      if (*plVar6 == 0) {
                                        (**(code **)(plVar6[1] + 0x30))(plVar6);
                                      }
                                      lVar7 = *plVar12 + -1;
                                    }
                                    *plVar12 = lVar7;
                                    if (lVar7 == 0) {
                                      (**(code **)(plVar12[1] + 0x30))(plVar12);
                                    }
                                    lVar7 = *(longlong *)pcVar14;
                                    *(longlong *)pcVar14 = lVar7 + 1;
                                    if (pcVar10 != (code *)0x0) {
                                      *(longlong *)pcVar10 = *(longlong *)pcVar10 + -1;
                                      if (*(longlong *)pcVar10 == 0) {
                                        (**(code **)(*(longlong *)(pcVar10 + 8) + 0x30))(pcVar10);
                                      }
                                      lVar7 = *(longlong *)pcVar14 + -1;
                                    }
                                    *(longlong *)pcVar14 = lVar7;
                                    if (lVar7 == 0) {
                                      (**(code **)(*(longlong *)(pcVar14 + 8) + 0x30))(pcVar14);
                                    }
                                    pcVar10 = (code *)FUN_23a3a0d40(DAT_23ed6cf28);
                                    plVar6 = _DAT_23eed8670;
                                    lVar7 = *(longlong *)(param_1 + 0x10);
                                    plVar9 = *(longlong **)(lVar7 + 0xe20);
                                    if (plVar9 == (longlong *)0x0) {
                                      plVar9 = (longlong *)FUN_23e916a20(PyTuple_Type_exref,2);
                                    }
                                    else {
                                      lVar1 = plVar9[3];
                                      *(int *)(lVar7 + 0xebc) = *(int *)(lVar7 + 0xebc) + -1;
                                      *(longlong *)(lVar7 + 0xe20) = lVar1;
                                      *plVar9 = 1;
                                    }
                                    plVar9[4] = 0;
                                    lVar7 = *(longlong *)
                                             (*(longlong *)(*(longlong *)(local_108 + 0x1f8) + 0x10)
                                             + 0x2e8);
                                    lVar1 = plVar9[-1];
                                    puVar2 = *(undefined8 **)(lVar7 + 8);
                                    *puVar2 = plVar9 + -2;
                                    plVar9[-2] = lVar7;
                                    plVar9[-1] = (ulonglong)((uint)lVar1 & 3) | (ulonglong)puVar2;
                                    *(longlong **)(lVar7 + 8) = plVar9 + -2;
                                    plVar15 = DAT_23ed6a4c0;
                                    *plVar6 = *plVar6 + 1;
                                    plVar9[3] = (longlong)plVar6;
                                    uVar8 = DAT_23ed6cd28;
                                    if (plVar15 == (longlong *)0x0) {
                                      plVar15 = (longlong *)
                                                PyDict_GetItemString(DAT_23ed6ccc0,"format");
                                      if (plVar15 == (longlong *)0x0) goto LAB_23e7a36a4;
                                      *plVar15 = *plVar15 + 1;
                                      DAT_23ed6a4c0 = plVar15;
                                    }
                                    uStack_a0 = uVar8;
                                    local_a8 = pcVar14;
                                    lVar7 = FUN_23e94ed00(param_1,plVar15,local_100);
                                    plVar6 = plVar12;
                                    pcVar10 = pcVar14;
                                    if (lVar7 == 0) {
                                      local_88._0_8_ = *(undefined8 *)(param_1 + 0x60);
                                      local_88._8_8_ = *(undefined8 *)(param_1 + 0x68);
                                      local_78[0] = *(longlong **)(param_1 + 0x70);
                                      *(undefined8 *)(param_1 + 0x70) = 0;
                                      *(undefined1 (*) [16])(param_1 + 0x60) = (undefined1  [16])0x0
                                      ;
                                      *plVar9 = *plVar9 + -1;
                                      if (*plVar9 == 0) {
                                        FUN_23a334bc0();
                                        uVar19 = 0x1c8;
                                        plVar15 = local_78[0];
                                        pcVar17 = (code *)local_88._0_8_;
                                        uVar8 = local_88._8_8_;
                                      }
                                      else {
                                        uVar19 = 0x1c8;
                                        plVar15 = local_78[0];
                                        pcVar17 = (code *)local_88._0_8_;
                                        uVar8 = local_88._8_8_;
                                      }
                                      goto LAB_23e7a35db;
                                    }
                                    plVar9[4] = lVar7;
                                    plVar12 = (longlong *)(*local_f8)();
                                    *plVar9 = *plVar9 + -1;
                                    if (*plVar9 == 0) {
                                      (**(code **)(plVar9[1] + 0x30))();
                                    }
                                    if (plVar12 == (longlong *)0x0) {
LAB_23e7a3db3:
                                      pcVar17 = *(code **)(param_1 + 0x60);
                                      plVar15 = *(longlong **)(param_1 + 0x70);
                                      *(undefined8 *)(param_1 + 0x70) = 0;
                                      uVar19 = 0x1c8;
                                      *(undefined1 (*) [16])(param_1 + 0x60) = (undefined1  [16])0x0
                                      ;
                                      uVar8 = *(undefined8 *)(param_1 + 0x68);
                                      goto LAB_23e7a35db;
                                    }
                                    *(undefined4 *)(plVar20 + 5) = 0x1c8;
                                    plVar9 = (longlong *)FUN_23e914090();
                                    *plVar12 = *plVar12 + -1;
                                    if (*plVar12 == 0) {
                                      (**(code **)(plVar12[1] + 0x30))();
                                    }
                                    if (plVar9 == (longlong *)0x0) goto LAB_23e7a3db3;
                                    *plVar9 = *plVar9 + -1;
                                    if (*plVar9 == 0) {
                                      (**(code **)(plVar9[1] + 0x30))();
                                    }
                                    lVar7 = *(longlong *)(param_1 + 0x10);
                                    if ((((*(int *)(*(longlong *)(lVar7 + 0x28) + 0x160) == 0) &&
                                         (*(int *)(lVar7 + 0x78) == 0)) ||
                                        (iVar5 = Py_MakePendingCalls(), -1 < iVar5)) ||
                                       (*(longlong *)(param_1 + 0x60) == 0)) goto LAB_23e7a2a76;
                                    goto LAB_23e7a35a3;
                                  }
                                  local_88 = *(undefined1 (*) [16])(param_1 + 0x60);
                                  local_78[0] = *(longlong **)(param_1 + 0x70);
                                  *(undefined8 *)(param_1 + 0x70) = 0;
                                  *(undefined1 (*) [16])(param_1 + 0x60) = (undefined1  [16])0x0;
                                  if (local_78[0] != (longlong *)0x0) {
                                    if ((longlong *)local_78[0][3] == plVar20) goto LAB_23e7a2eb0;
                                    plVar12 = (longlong *)0x0;
                                    plVar9 = (longlong *)0x0;
                                    pcVar17 = (code *)0x0;
                                    local_110 = (code *)0x0;
                                    uVar19 = 0x1c7;
                                    pcVar14 = (code *)0x0;
                                    goto LAB_23e7a2b85;
                                  }
                                }
                              }
                            }
                            plVar12 = (longlong *)0x0;
                            plVar9 = (longlong *)0x0;
                            pcVar17 = (code *)0x0;
                            local_110 = (code *)0x0;
                            pcVar14 = (code *)0x0;
                            pcVar10 = (code *)0x0;
                            plVar6 = (longlong *)0x0;
                            uVar19 = 0x1c7;
                            goto LAB_23e7a3300;
                          }
                          local_88 = *(undefined1 (*) [16])(param_1 + 0x60);
                          local_78[0] = *(longlong **)(param_1 + 0x70);
                          *(undefined8 *)(param_1 + 0x70) = 0;
                          *(undefined1 (*) [16])(param_1 + 0x60) = (undefined1  [16])0x0;
                          if (local_78[0] == (longlong *)0x0) {
                            plVar12 = (longlong *)0x0;
                            plVar9 = (longlong *)0x0;
                            pcVar17 = (code *)0x0;
                            local_110 = (code *)0x0;
                            pcVar14 = (code *)0x0;
                            uVar19 = 0x1c6;
                            pcVar10 = (code *)0x0;
                            plVar6 = (longlong *)0x0;
                            goto LAB_23e7a3300;
                          }
                          if ((longlong *)local_78[0][3] == plVar20) goto LAB_23e7a2eb0;
                          plVar12 = (longlong *)0x0;
                          plVar9 = (longlong *)0x0;
                          local_110 = (code *)0x0;
                          pcVar17 = (code *)0x0;
                          pcVar14 = (code *)0x0;
                          plVar6 = (longlong *)0x0;
                          uVar19 = 0x1c6;
                          pcVar10 = (code *)0x0;
                          goto LAB_23e7a2b85;
                        }
                        local_88 = *(undefined1 (*) [16])(param_1 + 0x60);
                        local_78[0] = *(longlong **)(param_1 + 0x70);
                        *(undefined8 *)(param_1 + 0x70) = 0;
                        *(undefined1 (*) [16])(param_1 + 0x60) = (undefined1  [16])0x0;
                        if (local_78[0] != (longlong *)0x0) {
                          if (plVar20 == (longlong *)local_78[0][3]) goto LAB_23e7a2eb0;
                          plVar12 = (longlong *)0x0;
                          plVar9 = (longlong *)0x0;
                          pcVar17 = (code *)0x0;
                          local_110 = (code *)0x0;
                          pcVar14 = (code *)0x0;
                          plVar6 = (longlong *)0x0;
                          uVar19 = 0x1c4;
                          pcVar10 = (code *)0x0;
                          goto LAB_23e7a2b85;
                        }
                      }
                      plVar12 = (longlong *)0x0;
                      plVar9 = (longlong *)0x0;
                      pcVar17 = (code *)0x0;
                      local_110 = (code *)0x0;
                      pcVar14 = (code *)0x0;
                      pcVar10 = (code *)0x0;
                      plVar6 = (longlong *)0x0;
                      uVar19 = 0x1c4;
                      goto LAB_23e7a3300;
                    }
                  }
                }
LAB_23e7a3170:
                local_88 = *(undefined1 (*) [16])(param_1 + 0x60);
                local_78[0] = *(longlong **)(param_1 + 0x70);
                uVar19 = 0x1c5;
              }
              *(undefined8 *)(param_1 + 0x70) = 0;
              *(undefined1 (*) [16])(param_1 + 0x60) = (undefined1  [16])0x0;
              *plVar6 = *plVar6 + -1;
              if (*plVar6 == 0) {
                (**(code **)(plVar6[1] + 0x30))();
                if (local_78[0] == (longlong *)0x0) goto LAB_23e7a3490;
                plVar6 = (longlong *)local_78[0][3];
              }
              else {
                if (local_78[0] == (longlong *)0x0) {
LAB_23e7a3490:
                  local_110 = (code *)0x0;
                  plVar12 = (longlong *)0x0;
                  pcVar17 = (code *)0x0;
                  plVar6 = (longlong *)0x0;
                  plVar9 = (longlong *)0x0;
                  pcVar14 = (code *)0x0;
                  pcVar10 = (code *)0x0;
                  goto LAB_23e7a3300;
                }
                plVar6 = (longlong *)local_78[0][3];
              }
              if (plVar20 != plVar6) {
                local_110 = (code *)0x0;
                plVar12 = (longlong *)0x0;
                pcVar17 = (code *)0x0;
                plVar6 = (longlong *)0x0;
                plVar9 = (longlong *)0x0;
                pcVar14 = (code *)0x0;
                pcVar10 = (code *)0x0;
                goto LAB_23e7a2b85;
              }
              goto LAB_23e7a2eb0;
            }
            local_88 = *(undefined1 (*) [16])(param_1 + 0x60);
            local_78[0] = *(longlong **)(param_1 + 0x70);
            *(undefined8 *)(param_1 + 0x70) = 0;
            *(undefined1 (*) [16])(param_1 + 0x60) = (undefined1  [16])0x0;
            if (local_78[0] != (longlong *)0x0) {
              if (plVar20 != (longlong *)local_78[0][3]) {
                plVar12 = (longlong *)0x0;
                plVar9 = (longlong *)0x0;
                pcVar17 = (code *)0x0;
                pcVar14 = (code *)0x0;
                local_110 = (code *)0x0;
                pcVar10 = (code *)0x0;
                uVar19 = 0x1c3;
                plVar6 = (longlong *)0x0;
                goto LAB_23e7a2b85;
              }
              goto LAB_23e7a2eb0;
            }
LAB_23e7a3410:
            local_110 = (code *)0x0;
            plVar12 = (longlong *)0x0;
            pcVar17 = (code *)0x0;
            plVar6 = (longlong *)0x0;
            plVar9 = (longlong *)0x0;
            pcVar14 = (code *)0x0;
            pcVar10 = (code *)0x0;
            uVar19 = 0x1c3;
            goto LAB_23e7a3300;
          }
LAB_23e7a2f00:
          local_88 = *(undefined1 (*) [16])(param_1 + 0x60);
          local_78[0] = *(longlong **)(param_1 + 0x70);
          *(undefined8 *)(param_1 + 0x70) = 0;
          *(undefined1 (*) [16])(param_1 + 0x60) = (undefined1  [16])0x0;
          *plVar6 = *plVar6 + -1;
          if (*plVar6 == 0) {
            (**(code **)(plVar6[1] + 0x30))();
            if (local_78[0] == (longlong *)0x0) goto LAB_23e7a3410;
            plVar6 = (longlong *)local_78[0][3];
          }
          else {
            if (local_78[0] == (longlong *)0x0) goto LAB_23e7a3410;
            plVar6 = (longlong *)local_78[0][3];
          }
          if (plVar20 != plVar6) {
            local_110 = (code *)0x0;
            plVar12 = (longlong *)0x0;
            pcVar17 = (code *)0x0;
            plVar6 = (longlong *)0x0;
            plVar9 = (longlong *)0x0;
            pcVar14 = (code *)0x0;
            pcVar10 = (code *)0x0;
            uVar19 = 0x1c3;
            goto LAB_23e7a2b85;
          }
        }
      }
    }
LAB_23e7a2eb0:
    local_110 = (code *)0x0;
    plVar12 = (longlong *)0x0;
    pcVar17 = (code *)0x0;
    plVar6 = (longlong *)0x0;
    plVar9 = (longlong *)0x0;
    pcVar14 = (code *)0x0;
    pcVar10 = (code *)0x0;
    plVar15 = local_78[0];
    goto LAB_23e7a2c44;
  }
  local_88 = *(undefined1 (*) [16])(param_1 + 0x60);
  local_78[0] = *(longlong **)(param_1 + 0x70);
  *(undefined8 *)(param_1 + 0x70) = 0;
  *(undefined1 (*) [16])(param_1 + 0x60) = (undefined1  [16])0x0;
  if (local_78[0] != (longlong *)0x0) {
    if ((longlong *)local_78[0][3] == plVar20) goto LAB_23e7a2eb0;
    plVar12 = (longlong *)0x0;
    plVar9 = (longlong *)0x0;
    pcVar17 = (code *)0x0;
    local_110 = (code *)0x0;
    pcVar14 = (code *)0x0;
    pcVar10 = (code *)0x0;
    uVar19 = 0x1bd;
    local_108 = _PyRuntime_exref;
    plVar6 = (longlong *)0x0;
    goto LAB_23e7a2b85;
  }
LAB_23e7a32d0:
  plVar12 = (longlong *)0x0;
  plVar9 = (longlong *)0x0;
  pcVar17 = (code *)0x0;
  pcVar14 = (code *)0x0;
  pcVar10 = (code *)0x0;
  plVar6 = (longlong *)0x0;
  uVar19 = 0x1bd;
  local_110 = (code *)0x0;
  local_108 = _PyRuntime_exref;
LAB_23e7a3300:
  plVar15 = DAT_23ed6a4f8;
  if (DAT_23ed6a4f8 == (longlong *)0x0) {
    plVar15 = (longlong *)FUN_23a33a530(PyTraceBack_Type_exref);
    plVar13 = local_78[0];
  }
  else {
    plVar13 = (longlong *)*DAT_23ed6a4f8;
    *DAT_23ed6a4f8 = 1;
    DAT_23ed6a4f8 = plVar13;
    DAT_23ed6a4f0 = DAT_23ed6a4f0 + -1;
    plVar13 = (longlong *)0x0;
  }
  plVar15[2] = 0;
  plVar15[3] = (longlong)plVar20;
  *plVar20 = *plVar20 + 1;
  lVar7 = *(longlong *)(local_108 + 0x1f8);
  *(undefined4 *)((longlong)plVar15 + 0x24) = uVar19;
  lVar7 = *(longlong *)(lVar7 + 0x10);
  *(undefined4 *)(plVar15 + 4) = 0xffffffff;
  lVar7 = *(longlong *)(lVar7 + 0x2e8);
  lVar1 = plVar15[-1];
  puVar2 = *(undefined8 **)(lVar7 + 8);
  *puVar2 = plVar15 + -2;
  plVar15[-2] = lVar7;
  plVar15[-1] = (ulonglong)((uint)lVar1 & 3) | (ulonglong)puVar2;
  *(longlong **)(lVar7 + 8) = plVar15 + -2;
  goto joined_r0x00023e7a338e;
LAB_23e7a2a76:
  if (*(int *)(lVar7 + 0x68) == 0) {
    plVar9 = *(longlong **)(param_1 + 0x90);
  }
  else {
    PyEval_SaveThread();
    PyEval_AcquireThread(param_1);
    plVar9 = *(longlong **)(param_1 + 0x90);
  }
  if (plVar9 != (longlong *)0x0) {
    plVar12 = *(longlong **)(param_1 + 0x60);
    plVar13 = *(longlong **)(param_1 + 0x68);
    plVar15 = *(longlong **)(param_1 + 0x70);
    *(longlong **)(param_1 + 0x60) = plVar9;
    *(undefined8 *)(param_1 + 0x90) = 0;
    *plVar9 = *plVar9 + 1;
    *(undefined8 *)(param_1 + 0x68) = 0;
    *(undefined8 *)(param_1 + 0x70) = 0;
    if ((plVar12 != (longlong *)0x0) && (*plVar12 = *plVar12 + -1, *plVar12 == 0)) {
      (**(code **)(plVar12[1] + 0x30))();
    }
    if ((plVar13 != (longlong *)0x0) && (*plVar13 = *plVar13 + -1, *plVar13 == 0)) {
      (**(code **)(plVar13[1] + 0x30))();
    }
    if ((plVar15 != (longlong *)0x0) && (*plVar15 = *plVar15 + -1, *plVar15 == 0)) {
      (**(code **)(plVar15[1] + 0x30))();
    }
LAB_23e7a35a3:
    plVar15 = *(longlong **)(param_1 + 0x70);
    *(undefined8 *)(param_1 + 0x70) = 0;
    uVar19 = 0x1c7;
    pcVar17 = *(code **)(param_1 + 0x60);
    *(undefined1 (*) [16])(param_1 + 0x60) = (undefined1  [16])0x0;
    uVar8 = *(undefined8 *)(param_1 + 0x68);
LAB_23e7a35db:
    local_78[0] = (longlong *)0x0;
    local_88 = (undefined1  [16])0x0;
    lVar7 = *plVar16;
    *plVar16 = lVar7 + -1;
    if (lVar7 + -1 == 0) {
      (**(code **)(plVar16[1] + 0x30))();
    }
LAB_23e7a361e:
    *plVar11 = *plVar11 + -1;
    if (*plVar11 == 0) {
      (**(code **)(plVar11[1] + 0x30))();
    }
    local_88._8_8_ = uVar8;
    local_88._0_8_ = pcVar17;
    if (plVar15 == (longlong *)0x0) {
      plVar12 = (longlong *)0x0;
      plVar9 = (longlong *)0x0;
      pcVar17 = (code *)0x0;
      local_110 = (code *)0x0;
      pcVar14 = (code *)0x0;
      local_78[0] = plVar15;
      goto LAB_23e7a3300;
    }
    plVar12 = (longlong *)0x0;
    plVar9 = (longlong *)0x0;
    pcVar17 = (code *)0x0;
    plVar13 = (longlong *)plVar15[3];
    local_110 = (code *)0x0;
    pcVar14 = (code *)0x0;
    goto joined_r0x00023e7a4748;
  }
  goto LAB_23e7a27b0;
LAB_23e7a4ad6:
  do {
    uVar19 = (undefined4)((ulonglong)in_stack_fffffffffffffeb8 >> 0x20);
    plVar13 = (longlong *)FUN_23a388450(plVar11);
    if (plVar13 == (longlong *)0x0) {
      cVar4 = FUN_23a3591a0(param_1,*(undefined8 *)PyExc_StopIteration_exref);
      if (cVar4 == '\0') {
        plVar13 = *(longlong **)(param_1 + 0x70);
        pcVar21 = *(code **)(param_1 + 0x60);
        uVar8 = *(undefined8 *)(param_1 + 0x68);
        *(undefined8 *)(param_1 + 0x70) = 0;
        uVar19 = 0x1df;
        local_78[0] = (longlong *)0x0;
        *(undefined1 (*) [16])(param_1 + 0x60) = (undefined1  [16])0x0;
        local_88 = (undefined1  [16])0x0;
        if (local_d0 != (longlong *)0x0) goto LAB_23e7a4ffc;
        goto LAB_23e7a502c;
      }
      if ((local_d0 != (longlong *)0x0) && (*local_d0 = *local_d0 + -1, *local_d0 == 0)) {
        FUN_23a334bc0(local_d0);
      }
      lVar7 = *plVar11;
      *plVar11 = lVar7 + -1;
      if (lVar7 + -1 == 0) {
        FUN_23a334bc0(plVar11);
      }
      uVar8 = FUN_23a3a0d40(DAT_23ed6cf28);
      *(undefined4 *)(plVar20 + 5) = 0x1e9;
      plVar13 = (longlong *)FUN_23e94bb80(param_1,uVar8);
      if (plVar13 == (longlong *)0x0) {
        pcVar21 = *(code **)(param_1 + 0x60);
        plVar13 = *(longlong **)(param_1 + 0x70);
        uVar19 = 0x1e9;
        *(undefined8 *)(param_1 + 0x70) = 0;
        *(undefined1 (*) [16])(param_1 + 0x60) = (undefined1  [16])0x0;
        uVar8 = *(undefined8 *)(param_1 + 0x68);
        goto LAB_23e7a416b;
      }
      *plVar13 = *plVar13 + -1;
      if (*plVar13 == 0) {
        FUN_23a334bc0(plVar13);
      }
      uVar8 = FUN_23a3a0d40(DAT_23ed6cf28);
      *(undefined4 *)(plVar20 + 5) = 0x1ea;
      plVar13 = (longlong *)FUN_23e94bb80(param_1,uVar8,_DAT_23eed86e0);
      if (plVar13 == (longlong *)0x0) {
        pcVar21 = *(code **)(param_1 + 0x60);
        plVar13 = *(longlong **)(param_1 + 0x70);
        uVar19 = 0x1ea;
        *(undefined8 *)(param_1 + 0x70) = 0;
        *(undefined1 (*) [16])(param_1 + 0x60) = (undefined1  [16])0x0;
        uVar8 = *(undefined8 *)(param_1 + 0x68);
        goto LAB_23e7a416b;
      }
      *plVar13 = *plVar13 + -1;
      if (*plVar13 == 0) {
        FUN_23a334bc0();
      }
      uVar8 = FUN_23a3a0d40(DAT_23ed6cf28);
      *(undefined4 *)(plVar20 + 5) = 0x1eb;
      plVar13 = (longlong *)FUN_23e94bb80(param_1,uVar8,_DAT_23eed8630);
      if (plVar13 == (longlong *)0x0) {
        pcVar21 = *(code **)(param_1 + 0x60);
        plVar13 = *(longlong **)(param_1 + 0x70);
        *(undefined8 *)(param_1 + 0x70) = 0;
        uVar19 = 0x1eb;
        *(undefined1 (*) [16])(param_1 + 0x60) = (undefined1  [16])0x0;
        uVar8 = *(undefined8 *)(param_1 + 0x68);
        goto LAB_23e7a416b;
      }
      *plVar13 = *plVar13 + -1;
      if (*plVar13 == 0) {
        FUN_23a334bc0(plVar13);
      }
      uVar8 = FUN_23a3a0d40(DAT_23ed6cf28);
      plVar13 = _DAT_23eed86e8;
      plVar11 = (longlong *)FUN_23e916ad0(*(undefined8 *)(param_1 + 0x10),4);
      *plVar13 = *plVar13 + 1;
      plVar11[3] = (longlong)plVar13;
      if (pcVar17 == (code *)0x0) {
        FUN_23e8ba2b0(local_88,_DAT_23eed86c8);
        if (((code *)local_88._0_8_ != pcVar21) && ((code *)local_88._0_8_ != (code *)0x0)) {
          FUN_23e91b1b0(param_1,local_88,local_88 + 8,local_78);
        }
        FUN_23ebf6a40(*(undefined8 *)(param_1 + 0x138),local_88._8_8_);
LAB_23e7a626c:
        lVar7 = *plVar11;
        *plVar11 = lVar7 + -1;
        if (lVar7 + -1 == 0) {
          FUN_23a334bc0(plVar11);
        }
      }
      else {
        lVar7 = FUN_23e94f9d0(param_1,pcVar17,DAT_23ed6cd28);
        if (lVar7 == 0) {
LAB_23e7a62d8:
          local_88._0_8_ = *(undefined8 *)(param_1 + 0x60);
          local_88._8_8_ = *(undefined8 *)(param_1 + 0x68);
          local_78[0] = *(longlong **)(param_1 + 0x70);
          *(undefined8 *)(param_1 + 0x70) = 0;
          *(undefined1 (*) [16])(param_1 + 0x60) = (undefined1  [16])0x0;
          goto LAB_23e7a626c;
        }
        plVar11[4] = lVar7;
        plVar13 = _DAT_23eed86f0;
        *_DAT_23eed86f0 = *_DAT_23eed86f0 + 1;
        plVar11[5] = (longlong)plVar13;
        plVar13 = (longlong *)FUN_23e8bd600(param_1,local_110);
        if (plVar13 == (longlong *)0x0) goto LAB_23e7a62d8;
        lVar7 = FUN_23e94f9d0(param_1,plVar13,DAT_23ed6cd28);
        *plVar13 = *plVar13 + -1;
        if (*plVar13 == 0) {
          FUN_23a334bc0(plVar13);
        }
        if (lVar7 == 0) goto LAB_23e7a62d8;
        plVar11[6] = lVar7;
        plVar13 = (longlong *)(*local_f8)(DAT_23ed6cd28);
        lVar7 = *plVar11;
        *plVar11 = lVar7 + -1;
        if (lVar7 + -1 == 0) {
          FUN_23a334bc0();
        }
        if (plVar13 != (longlong *)0x0) {
          *(undefined4 *)(plVar20 + 5) = 0x1ec;
          plVar11 = (longlong *)FUN_23e914090(param_1,uVar8);
          *plVar13 = *plVar13 + -1;
          if (*plVar13 == 0) {
            FUN_23a334bc0(plVar13);
          }
          if (plVar11 != (longlong *)0x0) {
            *plVar11 = *plVar11 + -1;
            if (*plVar11 == 0) {
              FUN_23a334bc0(plVar11);
            }
            uVar8 = FUN_23a3a0d40(DAT_23ed6cf28);
            *(undefined4 *)(plVar20 + 5) = 0x1ed;
            plVar13 = (longlong *)FUN_23e94bb80(param_1,uVar8,_DAT_23eed8630);
            if (plVar13 == (longlong *)0x0) {
              pcVar21 = *(code **)(param_1 + 0x60);
              plVar13 = *(longlong **)(param_1 + 0x70);
              uVar19 = 0x1ed;
              *(undefined8 *)(param_1 + 0x70) = 0;
              *(undefined1 (*) [16])(param_1 + 0x60) = (undefined1  [16])0x0;
              uVar8 = *(undefined8 *)(param_1 + 0x68);
              goto LAB_23e7a416b;
            }
            *plVar13 = *plVar13 + -1;
            if (*plVar13 == 0) {
              FUN_23a334bc0(plVar13);
            }
            goto LAB_23e7a43f8;
          }
        }
        local_78[0] = *(longlong **)(param_1 + 0x70);
        local_88._0_8_ = *(undefined8 *)(param_1 + 0x60);
        local_88._8_8_ = *(undefined8 *)(param_1 + 0x68);
        *(undefined8 *)(param_1 + 0x70) = 0;
        *(undefined1 (*) [16])(param_1 + 0x60) = (undefined1  [16])0x0;
      }
      uVar19 = 0x1ec;
      plVar13 = local_78[0];
      pcVar21 = (code *)local_88._0_8_;
      uVar8 = local_88._8_8_;
      goto LAB_23e7a416b;
    }
    if ((local_d0 != (longlong *)0x0) && (*local_d0 = *local_d0 + -1, *local_d0 == 0)) {
      FUN_23a334bc0(local_d0);
    }
    plVar16 = (longlong *)FUN_23a388310(plVar13);
    local_d0 = plVar13;
    if (plVar16 == (longlong *)0x0) {
      pcVar21 = *(code **)(param_1 + 0x60);
      uVar8 = *(undefined8 *)(param_1 + 0x68);
      plVar13 = *(longlong **)(param_1 + 0x70);
      *(undefined8 *)(param_1 + 0x70) = 0;
      *(undefined1 (*) [16])(param_1 + 0x60) = (undefined1  [16])0x0;
LAB_23e7a57da:
      uVar19 = 0x1df;
      goto LAB_23e7a4ffc;
    }
    uVar8 = CONCAT44(uVar19,2);
    plVar15 = (longlong *)FUN_23a3c1d30(param_1,local_88,plVar16,0,uVar8);
    if (plVar15 == (longlong *)0x0) {
      *plVar16 = *plVar16 + -1;
      local_f0 = (longlong *)0x0;
      plVar13 = local_78[0];
      pcVar21 = (code *)local_88._0_8_;
      uVar8 = local_88._8_8_;
      if (*plVar16 != 0) goto LAB_23e7a57da;
LAB_23e7a585a:
      local_88._8_8_ = 0;
      local_88._0_8_ = 0;
      local_78[0] = (longlong *)0x0;
      FUN_23a334bc0(plVar16);
      local_78[0] = (longlong *)0x0;
      local_88._0_8_ = 0;
      local_88._8_8_ = 0;
      if (plVar15 != (longlong *)0x0) {
LAB_23e7a5768:
        local_88._8_8_ = 0;
        local_88._0_8_ = 0;
        local_78[0] = (longlong *)0x0;
        lVar7 = *plVar15;
        *plVar15 = lVar7 + -1;
        if (lVar7 + -1 == 0) {
          FUN_23a334bc0(plVar15);
        }
      }
      if ((local_f0 != (longlong *)0x0) &&
         (lVar7 = *local_f0, *local_f0 = lVar7 + -1, lVar7 + -1 == 0)) {
        FUN_23a334bc0(local_f0);
      }
      goto LAB_23e7a57da;
    }
    in_stack_fffffffffffffeb8 = CONCAT44((int)((ulonglong)uVar8 >> 0x20),2);
    local_f0 = (longlong *)FUN_23a3c1d30(param_1,local_88,plVar16,1,in_stack_fffffffffffffeb8);
    if (local_f0 == (longlong *)0x0) {
      lVar7 = *plVar16;
LAB_23e7a5721:
      *plVar16 = lVar7 + -1;
      plVar13 = local_78[0];
      pcVar21 = (code *)local_88._0_8_;
      uVar8 = local_88._8_8_;
      if (lVar7 + -1 == 0) goto LAB_23e7a585a;
      goto LAB_23e7a5768;
    }
    cVar4 = FUN_23a3884a0(param_1,local_88,plVar16);
    lVar7 = *plVar16;
    if (cVar4 == '\0') goto LAB_23e7a5721;
    *plVar16 = lVar7 + -1;
    if (lVar7 + -1 == 0) {
      FUN_23a334bc0(plVar16);
    }
    *plVar15 = *plVar15 + 1;
    if ((plVar9 != (longlong *)0x0) && (*plVar9 = *plVar9 + -1, *plVar9 == 0)) {
      FUN_23a334bc0(plVar9);
    }
    *plVar15 = *plVar15 + -1;
    if (*plVar15 == 0) {
      FUN_23a334bc0(plVar15);
    }
    *local_f0 = *local_f0 + 1;
    if ((plVar12 != (longlong *)0x0) && (*plVar12 = *plVar12 + -1, *plVar12 == 0)) {
      FUN_23a334bc0(plVar12);
    }
    *local_f0 = *local_f0 + -1;
    if (*local_f0 == 0) {
      FUN_23a334bc0(local_f0);
    }
    uVar8 = FUN_23a3a0d40(DAT_23ed6cf28);
    plVar9 = _DAT_23eed86a8;
    plVar13 = (longlong *)FUN_23e916ad0(*(undefined8 *)(param_1 + 0x10),5);
    *plVar9 = *plVar9 + 1;
    plVar13[3] = (longlong)plVar9;
    lVar7 = FUN_23e94f9d0(param_1,plVar15,DAT_23ed6cd28);
    plVar9 = plVar15;
    plVar12 = local_f0;
    if (lVar7 == 0) {
LAB_23e7a5674:
      local_88._0_8_ = *(undefined8 *)(param_1 + 0x60);
      local_88._8_8_ = *(undefined8 *)(param_1 + 0x68);
      local_78[0] = *(longlong **)(param_1 + 0x70);
      *(undefined8 *)(param_1 + 0x70) = 0;
      *(undefined1 (*) [16])(param_1 + 0x60) = (undefined1  [16])0x0;
      *plVar13 = *plVar13 + -1;
      if (*plVar13 == 0) {
        FUN_23a334bc0(plVar13);
      }
LAB_23e7a566a:
      uVar19 = 0x1e0;
      plVar13 = local_78[0];
      pcVar21 = (code *)local_88._0_8_;
      uVar8 = local_88._8_8_;
      goto LAB_23e7a4ffc;
    }
    plVar13[4] = lVar7;
    plVar16 = DAT_23ed6cea0;
    *DAT_23ed6cea0 = *DAT_23ed6cea0 + 1;
    plVar13[5] = (longlong)plVar16;
    plVar16 = (longlong *)FUN_23e8bd600(param_1,local_110);
    if (plVar16 == (longlong *)0x0) goto LAB_23e7a5674;
    lVar7 = FUN_23e94f9d0(param_1,plVar16);
    *plVar16 = *plVar16 + -1;
    if (*plVar16 == 0) {
      FUN_23a334bc0(plVar16);
    }
    plVar16 = _DAT_23eed86b0;
    if (lVar7 == 0) goto LAB_23e7a5674;
    plVar13[6] = lVar7;
    *plVar16 = *plVar16 + 1;
    plVar13[7] = (longlong)plVar16;
    lVar7 = (*local_f8)(DAT_23ed6cd28,plVar13);
    *plVar13 = *plVar13 + -1;
    if (*plVar13 == 0) {
      FUN_23a334bc0(plVar13);
    }
    if (lVar7 == 0) {
LAB_23e7a561b:
      local_78[0] = *(longlong **)(param_1 + 0x70);
      local_88._0_8_ = *(undefined8 *)(param_1 + 0x60);
      local_88._8_8_ = *(undefined8 *)(param_1 + 0x68);
      *(undefined8 *)(param_1 + 0x70) = 0;
      *(undefined1 (*) [16])(param_1 + 0x60) = (undefined1  [16])0x0;
      goto LAB_23e7a566a;
    }
    plVar13 = (longlong *)FUN_23e916ad0(*(undefined8 *)(param_1 + 0x10),1);
    uVar22 = _DAT_23eed86b8;
    plVar13[3] = lVar7;
    plVar16 = (longlong *)FUN_23e8d7870(param_1,uVar22);
    *(undefined4 *)(plVar20 + 5) = 0x1e0;
    plVar15 = (longlong *)FUN_23a334c60(param_1,uVar8,plVar13,plVar16);
    *plVar13 = *plVar13 + -1;
    if (*plVar13 == 0) {
      FUN_23a334bc0(plVar13);
    }
    *plVar16 = *plVar16 + -1;
    if (*plVar16 == 0) {
      FUN_23a334bc0(plVar16);
    }
    if (plVar15 == (longlong *)0x0) goto LAB_23e7a561b;
    *plVar15 = *plVar15 + -1;
    if (*plVar15 == 0) {
      FUN_23a334bc0(plVar15);
    }
    if (plVar18 == (longlong *)0x0) {
      FUN_23e8ba2b0(local_88,DAT_23eed80d0);
      if (((code *)local_88._0_8_ != pcVar21) && ((code *)local_88._0_8_ != (code *)0x0)) {
        FUN_23e91b1b0(param_1,local_88,local_88 + 8,local_78);
      }
      FUN_23ebf6a40(*(undefined8 *)(param_1 + 0x138),local_88._8_8_);
LAB_23e7a52d2:
      uVar19 = 0x1e2;
      plVar13 = local_78[0];
      pcVar21 = (code *)local_88._0_8_;
      uVar8 = local_88._8_8_;
      goto LAB_23e7a4ffc;
    }
    *(undefined4 *)(plVar20 + 5) = 0x1e2;
    plVar13 = (longlong *)FUN_23e915840(param_1,plVar18,DAT_23eed86c0);
    if (plVar13 == (longlong *)0x0) {
      local_88._0_8_ = *(undefined8 *)(param_1 + 0x60);
      local_88._8_8_ = *(undefined8 *)(param_1 + 0x68);
      local_78[0] = *(longlong **)(param_1 + 0x70);
      *(undefined8 *)(param_1 + 0x70) = 0;
      *(undefined1 (*) [16])(param_1 + 0x60) = (undefined1  [16])0x0;
      goto LAB_23e7a52d2;
    }
    iVar5 = FUN_23a35f020(plVar13);
    lVar7 = *plVar13 + -1;
    if (iVar5 == -1) {
      local_88._0_8_ = *(undefined8 *)(param_1 + 0x60);
      local_88._8_8_ = *(undefined8 *)(param_1 + 0x68);
      local_78[0] = *(longlong **)(param_1 + 0x70);
      *(undefined8 *)(param_1 + 0x70) = 0;
      *(undefined1 (*) [16])(param_1 + 0x60) = (undefined1  [16])0x0;
      *plVar13 = lVar7;
      if (lVar7 == 0) {
        FUN_23a334bc0(plVar13);
      }
      goto LAB_23e7a52d2;
    }
    *plVar13 = lVar7;
    if (lVar7 == 0) {
      FUN_23a334bc0(plVar13);
    }
    if (iVar5 != 0) {
      if (pcVar17 == (code *)0x0) {
        FUN_23e8ba2b0(local_88,_DAT_23eed86c8);
        if (((code *)local_88._0_8_ != pcVar21) && ((code *)local_88._0_8_ != (code *)0x0)) {
          FUN_23e91b1b0(param_1,local_88,local_88 + 8,local_78);
        }
        FUN_23ebf6a40(*(undefined8 *)(param_1 + 0x138),local_88._8_8_);
      }
      else {
        local_a8 = pcVar17;
        cVar4 = FUN_23e8c72f0(local_100,DAT_23ed6ccf8);
        pcVar3 = local_a8;
        if (cVar4 != '\0') {
          uVar8 = FUN_23a3a0d40(DAT_23ed6cf28);
          plVar13 = _DAT_23eed86d0;
          plVar16 = (longlong *)FUN_23e916ad0(*(undefined8 *)(param_1 + 0x10),4);
          *plVar13 = *plVar13 + 1;
          plVar16[3] = (longlong)plVar13;
          lVar7 = FUN_23e94f9d0(param_1,pcVar3,DAT_23ed6cd28);
          pcVar17 = pcVar3;
          if (lVar7 == 0) {
LAB_23e7a553c:
            local_88._0_8_ = *(undefined8 *)(param_1 + 0x60);
            local_88._8_8_ = *(undefined8 *)(param_1 + 0x68);
            local_78[0] = *(longlong **)(param_1 + 0x70);
            *(undefined8 *)(param_1 + 0x70) = 0;
            *(undefined1 (*) [16])(param_1 + 0x60) = (undefined1  [16])0x0;
            *plVar16 = *plVar16 + -1;
            if (*plVar16 == 0) {
              FUN_23a334bc0(plVar16);
            }
          }
          else {
            plVar16[4] = lVar7;
            plVar13 = DAT_23ed6cea0;
            *DAT_23ed6cea0 = *DAT_23ed6cea0 + 1;
            plVar16[5] = (longlong)plVar13;
            plVar13 = (longlong *)FUN_23e8bd600(param_1,local_110);
            if (plVar13 == (longlong *)0x0) goto LAB_23e7a553c;
            lVar7 = FUN_23e94f9d0(param_1,plVar13,DAT_23ed6cd28);
            *plVar13 = *plVar13 + -1;
            if (*plVar13 == 0) {
              FUN_23a334bc0(plVar13);
            }
            if (lVar7 == 0) goto LAB_23e7a553c;
            plVar16[6] = lVar7;
            plVar13 = (longlong *)(*local_f8)(DAT_23ed6cd28,plVar16);
            *plVar16 = *plVar16 + -1;
            if (*plVar16 == 0) {
              FUN_23a334bc0(plVar16);
            }
            if (plVar13 != (longlong *)0x0) {
              *(undefined4 *)(plVar20 + 5) = 0x1e4;
              plVar16 = (longlong *)FUN_23e914090(param_1,uVar8,plVar13);
              *plVar13 = *plVar13 + -1;
              if (*plVar13 == 0) {
                FUN_23a334bc0(plVar13);
              }
              if (plVar16 != (longlong *)0x0) goto LAB_23e7a4f45;
            }
            local_78[0] = *(longlong **)(param_1 + 0x70);
            local_88._0_8_ = *(undefined8 *)(param_1 + 0x60);
            local_88._8_8_ = *(undefined8 *)(param_1 + 0x68);
            *(undefined8 *)(param_1 + 0x70) = 0;
            *(undefined1 (*) [16])(param_1 + 0x60) = (undefined1  [16])0x0;
          }
          uVar19 = 0x1e4;
          plVar13 = local_78[0];
          pcVar21 = (code *)local_88._0_8_;
          uVar8 = local_88._8_8_;
          goto LAB_23e7a4ffc;
        }
        local_78[0] = *(longlong **)(param_1 + 0x70);
        local_88._0_8_ = *(undefined8 *)(param_1 + 0x60);
        local_88._8_8_ = *(undefined8 *)(param_1 + 0x68);
        *(undefined8 *)(param_1 + 0x70) = 0;
        *(undefined1 (*) [16])(param_1 + 0x60) = (undefined1  [16])0x0;
      }
      uVar19 = 0x1e3;
      plVar13 = local_78[0];
      pcVar21 = (code *)local_88._0_8_;
      uVar8 = local_88._8_8_;
      goto LAB_23e7a4ffc;
    }
    uVar8 = FUN_23a3a0d40(DAT_23ed6cf28);
    plVar13 = _DAT_23eed86d8;
    plVar16 = (longlong *)FUN_23e916ad0(*(undefined8 *)(param_1 + 0x10),2);
    *plVar13 = *plVar13 + 1;
    plVar16[3] = (longlong)plVar13;
    plVar13 = (longlong *)FUN_23a38cc10(param_1,local_f0,DAT_23ed6ce48);
    if (plVar13 == (longlong *)0x0) {
LAB_23e7a51d0:
      local_88._0_8_ = *(undefined8 *)(param_1 + 0x60);
      local_88._8_8_ = *(undefined8 *)(param_1 + 0x68);
      local_78[0] = *(longlong **)(param_1 + 0x70);
      *(undefined8 *)(param_1 + 0x70) = 0;
      *(undefined1 (*) [16])(param_1 + 0x60) = (undefined1  [16])0x0;
      *plVar16 = *plVar16 + -1;
      if (*plVar16 == 0) {
        FUN_23a334bc0(plVar16);
      }
LAB_23e7a51c6:
      uVar19 = 0x1e7;
      plVar13 = local_78[0];
      pcVar21 = (code *)local_88._0_8_;
      uVar8 = local_88._8_8_;
      goto LAB_23e7a4ffc;
    }
    lVar7 = FUN_23e94f9d0(param_1,plVar13,DAT_23ed6cd28);
    *plVar13 = *plVar13 + -1;
    if (*plVar13 == 0) {
      FUN_23a334bc0(plVar13);
    }
    if (lVar7 == 0) goto LAB_23e7a51d0;
    plVar16[4] = lVar7;
    plVar13 = (longlong *)(*local_f8)(DAT_23ed6cd28,plVar16);
    *plVar16 = *plVar16 + -1;
    if (*plVar16 == 0) {
      FUN_23a334bc0(plVar16);
    }
    if (plVar13 == (longlong *)0x0) {
LAB_23e7a5177:
      local_78[0] = *(longlong **)(param_1 + 0x70);
      local_88._0_8_ = *(undefined8 *)(param_1 + 0x60);
      local_88._8_8_ = *(undefined8 *)(param_1 + 0x68);
      *(undefined8 *)(param_1 + 0x70) = 0;
      *(undefined1 (*) [16])(param_1 + 0x60) = (undefined1  [16])0x0;
      goto LAB_23e7a51c6;
    }
    *(undefined4 *)(plVar20 + 5) = 0x1e7;
    plVar16 = (longlong *)FUN_23e914090(param_1,uVar8,plVar13);
    *plVar13 = *plVar13 + -1;
    if (*plVar13 == 0) {
      FUN_23a334bc0(plVar13);
    }
    if (plVar16 == (longlong *)0x0) goto LAB_23e7a5177;
LAB_23e7a4f45:
    *plVar16 = *plVar16 + -1;
    if (*plVar16 == 0) {
      FUN_23a334bc0(plVar16);
    }
    cVar4 = FUN_23a3a5fe0(param_1);
  } while (cVar4 != '\0');
  pcVar21 = *(code **)(param_1 + 0x60);
  plVar13 = *(longlong **)(param_1 + 0x70);
  *(undefined8 *)(param_1 + 0x70) = 0;
  uVar19 = 0x1df;
  *(undefined1 (*) [16])(param_1 + 0x60) = (undefined1  [16])0x0;
  uVar8 = *(undefined8 *)(param_1 + 0x68);
LAB_23e7a4ffc:
  local_78[0] = (longlong *)0x0;
  local_88 = (undefined1  [16])0x0;
  *local_d0 = *local_d0 + -1;
  if (*local_d0 == 0) {
    FUN_23a334bc0(local_d0);
  }
LAB_23e7a502c:
  lVar7 = *plVar11;
  *plVar11 = lVar7 + -1;
  if (lVar7 + -1 == 0) {
    FUN_23a334bc0();
  }
LAB_23e7a416b:
  local_88._8_8_ = uVar8;
  local_88._0_8_ = pcVar21;
  local_78[0] = plVar13;
  plVar11 = local_78[0];
  local_78[0] = (longlong *)0x0;
  local_98 = plVar11;
  plVar13 = *(longlong **)(param_1 + 0x138);
  local_a8 = (code *)local_88._0_8_;
  uStack_a0 = local_88._8_8_;
  local_88._0_8_ = (code *)0x0;
  local_88._8_8_ = 0;
  if (plVar13 != (longlong *)0x0) {
    *plVar13 = *plVar13 + 1;
  }
  if (plVar11 == (longlong *)0x0) {
    lVar7 = FUN_23e8d6280(plVar20,uVar19);
    if ((local_98 != (longlong *)0x0) && (*local_98 = *local_98 + -1, *local_98 == 0)) {
      FUN_23a334bc0();
    }
  }
  else {
    lVar7 = FUN_23e8d6280(plVar20,uVar19);
    *(longlong **)(lVar7 + 0x10) = plVar11;
    *plVar11 = *plVar11 + 1;
    if ((local_98 != (longlong *)0x0) && (*local_98 = *local_98 + -1, *local_98 == 0)) {
      FUN_23a334bc0();
    }
  }
  local_98 = (longlong *)lVar7;
  FUN_23a35ef40(param_1,local_100);
  iVar5 = FUN_23a35ebd0(param_1,*(undefined8 *)(*(longlong *)(param_1 + 0x138) + 8),
                        *(undefined8 *)PyExc_KeyboardInterrupt_exref);
  if (iVar5 == 0) {
    cVar4 = FUN_23e8ba320(*(undefined8 *)(param_1 + 0x138),local_88);
    plVar15 = local_78[0];
    uVar22 = local_88._8_8_;
    uVar8 = local_88._0_8_;
    iVar5 = 0;
    if (cVar4 == '\0') {
      iVar5 = 0x1cb;
    }
    if (local_78[0] == (longlong *)0x0) {
      local_88 = (undefined1  [16])0x0;
      FUN_23ebf6ae0(param_1,plVar13);
      local_78[0] = (longlong *)0x0;
      uVar19 = 0x1cb;
      local_88 = CONCAT88(uVar22,uVar8);
      if (iVar5 == 0) {
        uVar19 = (undefined4)plVar20[5];
      }
      goto LAB_23e7a3300;
    }
    if ((longlong *)local_78[0][3] == plVar20) {
      *(undefined4 *)(plVar20 + 5) = *(undefined4 *)((longlong)local_78[0] + 0x24);
    }
    local_78[0] = (longlong *)0x0;
    local_88 = (undefined1  [16])0x0;
    FUN_23ebf6ae0(param_1,plVar13);
    local_88 = CONCAT88(uVar22,uVar8);
    if ((longlong *)plVar15[3] == plVar20) goto LAB_23e7a2c44;
    local_78[0] = plVar15;
    if (iVar5 == 0) {
      uVar19 = (undefined4)plVar20[5];
    }
    else {
      uVar19 = 0x1cb;
    }
  }
  else {
    uVar8 = FUN_23a3a0d40(DAT_23ed6cf28);
    *(undefined4 *)(plVar20 + 5) = 0x1f0;
    plVar11 = (longlong *)FUN_23e94bb80(param_1,uVar8,_DAT_23eed86f8);
    if (plVar11 == (longlong *)0x0) {
      uVar8 = *(undefined8 *)(param_1 + 0x60);
      uVar22 = *(undefined8 *)(param_1 + 0x68);
      plVar15 = *(longlong **)(param_1 + 0x70);
      uVar19 = 0x1f0;
    }
    else {
      *plVar11 = *plVar11 + -1;
      if (*plVar11 == 0) {
        FUN_23a334bc0(plVar11);
      }
      uVar8 = FUN_23a3a0d40(DAT_23ed6cf28);
      *(undefined4 *)(plVar20 + 5) = 0x1f1;
      plVar11 = (longlong *)FUN_23e94bb80(param_1,uVar8,_DAT_23eed8700);
      if (plVar11 == (longlong *)0x0) {
        uVar8 = *(undefined8 *)(param_1 + 0x60);
        uVar22 = *(undefined8 *)(param_1 + 0x68);
        plVar15 = *(longlong **)(param_1 + 0x70);
        uVar19 = 0x1f1;
      }
      else {
        *plVar11 = *plVar11 + -1;
        if (*plVar11 == 0) {
          FUN_23a334bc0(plVar11);
        }
        uVar8 = FUN_23a3a0d40(DAT_23ed6cf28);
        *(undefined4 *)(plVar20 + 5) = 0x1f2;
        plVar11 = (longlong *)FUN_23e94bb80(param_1,uVar8,_DAT_23eed8630);
        if (plVar11 != (longlong *)0x0) {
          *plVar11 = *plVar11 + -1;
          if (*plVar11 == 0) {
            FUN_23a334bc0(plVar11);
          }
          FUN_23ebf6ae0(param_1,plVar13);
          pcVar21 = _Py_NoneStruct_exref;
LAB_23e7a43f8:
          FUN_23ebf6b20(*(undefined8 *)(param_1 + 0x38));
          *(longlong *)pcVar21 = *(longlong *)pcVar21 + 1;
          goto LAB_23e7a1edd;
        }
        uVar8 = *(undefined8 *)(param_1 + 0x60);
        uVar22 = *(undefined8 *)(param_1 + 0x68);
        plVar15 = *(longlong **)(param_1 + 0x70);
        uVar19 = 0x1f2;
      }
    }
    *(undefined8 *)(param_1 + 0x70) = 0;
    *(undefined1 (*) [16])(param_1 + 0x60) = (undefined1  [16])0x0;
    local_78[0] = (longlong *)0x0;
    local_88 = (undefined1  [16])0x0;
    FUN_23ebf6ae0(param_1,plVar13);
    local_88._8_8_ = uVar22;
    local_88._0_8_ = uVar8;
    local_78[0] = plVar15;
    if (plVar15 == (longlong *)0x0) goto LAB_23e7a3300;
    plVar13 = (longlong *)plVar15[3];
joined_r0x00023e7a4748:
    local_78[0] = plVar15;
    if (plVar13 == plVar20) goto LAB_23e7a2c44;
  }
LAB_23e7a2b85:
  plVar13 = local_78[0];
  plVar15 = DAT_23ed6a4f8;
  if (DAT_23ed6a4f8 == (longlong *)0x0) {
    plVar15 = (longlong *)FUN_23a33a530(PyTraceBack_Type_exref);
  }
  else {
    plVar11 = (longlong *)*DAT_23ed6a4f8;
    *DAT_23ed6a4f8 = 1;
    DAT_23ed6a4f8 = plVar11;
    DAT_23ed6a4f0 = DAT_23ed6a4f0 + -1;
  }
  plVar15[3] = (longlong)plVar20;
  *plVar20 = *plVar20 + 1;
  lVar7 = *(longlong *)(local_108 + 0x1f8);
  *(undefined4 *)((longlong)plVar15 + 0x24) = uVar19;
  *(undefined4 *)(plVar15 + 4) = 0xffffffff;
  lVar7 = *(longlong *)(*(longlong *)(lVar7 + 0x10) + 0x2e8);
  lVar1 = plVar15[-1];
  puVar2 = *(undefined8 **)(lVar7 + 8);
  *puVar2 = plVar15 + -2;
  plVar15[-2] = lVar7;
  plVar15[-1] = (ulonglong)((uint)lVar1 & 3) | (ulonglong)puVar2;
  *(longlong **)(lVar7 + 8) = plVar15 + -2;
  plVar15[2] = (longlong)plVar13;
  *plVar13 = *plVar13 + 1;
  plVar13 = local_78[0];
joined_r0x00023e7a338e:
  if ((plVar13 != (longlong *)0x0) && (*plVar13 = *plVar13 + -1, *plVar13 == 0)) {
    (**(code **)(plVar13[1] + 0x30))();
  }
LAB_23e7a2c44:
  local_78[0] = plVar15;
  FUN_23e8bba40(plVar20,"oooooooo",plVar18,plVar6,pcVar10,pcVar14,local_110,pcVar17,plVar9,plVar12);
  if (_DAT_23eedabd0 == plVar20) {
    *plVar20 = *plVar20 + -1;
    if (*plVar20 == 0) {
      (**(code **)(plVar20[1] + 0x30))(plVar20);
    }
    _DAT_23eedabd0 = (longlong *)0x0;
  }
  lVar7 = *(longlong *)(*(longlong *)(param_1 + 0x38) + 8);
  plVar20 = *(longlong **)(lVar7 + 0x28);
  plVar13 = (longlong *)plVar20[2];
  *(undefined8 *)(*(longlong *)(param_1 + 0x38) + 8) = *(undefined8 *)(lVar7 + 0x30);
  *(undefined4 *)(plVar20 + 8) = 0xffffffff;
  if (plVar13 != (longlong *)0x0) {
    plVar20[2] = 0;
    *plVar13 = *plVar13 + -1;
    if (*plVar13 == 0) {
      (**(code **)(plVar13[1] + 0x30))();
    }
  }
  *plVar20 = *plVar20 + -1;
  if (*plVar20 == 0) {
    (**(code **)(plVar20[1] + 0x30))(plVar20);
  }
  plVar13 = local_78[0];
  plVar20[0xf] = 0;
  uVar8 = local_88._0_8_;
  uVar22 = local_88._8_8_;
  local_88 = (undefined1  [16])0x0;
  local_78[0] = (longlong *)0x0;
  if ((plVar6 != (longlong *)0x0) && (*plVar6 = *plVar6 + -1, *plVar6 == 0)) {
    (**(code **)(plVar6[1] + 0x30))(plVar6);
  }
  if ((pcVar10 != (code *)0x0) &&
     (*(longlong *)pcVar10 = *(longlong *)pcVar10 + -1, *(longlong *)pcVar10 == 0)) {
    (**(code **)(*(longlong *)(pcVar10 + 8) + 0x30))(pcVar10);
  }
  if ((pcVar14 != (code *)0x0) &&
     (*(longlong *)pcVar14 = *(longlong *)pcVar14 + -1, *(longlong *)pcVar14 == 0)) {
    (**(code **)(*(longlong *)(pcVar14 + 8) + 0x30))(pcVar14);
  }
  if ((local_110 != (code *)0x0) &&
     (lVar7 = *(longlong *)local_110, *(longlong *)local_110 = lVar7 + -1, lVar7 + -1 == 0)) {
    (**(code **)(*(longlong *)(local_110 + 8) + 0x30))(local_110);
  }
  if ((pcVar17 != (code *)0x0) &&
     (*(longlong *)pcVar17 = *(longlong *)pcVar17 + -1, *(longlong *)pcVar17 == 0)) {
    (**(code **)(*(longlong *)(pcVar17 + 8) + 0x30))(pcVar17);
  }
  if ((plVar9 != (longlong *)0x0) && (*plVar9 = *plVar9 + -1, *plVar9 == 0)) {
    (**(code **)(plVar9[1] + 0x30))(plVar9);
  }
  if ((plVar12 != (longlong *)0x0) && (*plVar12 = *plVar12 + -1, *plVar12 == 0)) {
    (**(code **)(plVar12[1] + 0x30))(plVar12);
  }
  *plVar18 = *plVar18 + -1;
  local_78[0] = plVar13;
  local_88._0_8_ = uVar8;
  local_88._8_8_ = uVar22;
  if (*plVar18 == 0) {
    (**(code **)(plVar18[1] + 0x30))(plVar18);
  }
  FUN_23a33aa70(param_1,local_88._0_8_,local_88._8_8_,local_78[0]);
  return (code *)0x0;
}
