/* ===== 23e749a20 workers.fishing.fishing_bot:FishingBot._brain_loop ===== */
/* ghidra_name=FUN_23e749a20 entry=23e749a20 size=8727 */

code * FUN_23e749a20(longlong param_1,undefined8 param_2,undefined8 *param_3)

{
  longlong *plVar1;
  undefined8 *puVar2;
  longlong *plVar3;
  undefined8 uVar4;
  int iVar5;
  longlong *plVar6;
  longlong *plVar7;
  longlong lVar8;
  code *pcVar9;
  longlong *plVar10;
  longlong *plVar11;
  longlong *plVar12;
  code *pcVar13;
  longlong lVar14;
  longlong *plVar15;
  longlong *plVar16;
  code *pcVar17;
  code *pcVar18;
  undefined4 uVar19;
  undefined1 auVar20 [8];
  longlong *local_f0;
  code *local_e8;
  longlong *local_e0;
  code *local_d0;
  longlong *local_c0;
  longlong *local_a8;
  undefined8 uStack_a0;
  undefined1 local_98 [16];
  code *local_88 [2];
  undefined1 local_78 [8];
  code *pcStack_70;
  code *local_68 [5];
  
  plVar6 = DAT_23eedae40;
  plVar1 = (longlong *)*param_3;
  local_68[0] = (code *)0x0;
  local_78 = (undefined1  [8])0x0;
  pcStack_70 = (code *)0x0;
  if (DAT_23eedae40 == (longlong *)0x0) {
LAB_23e749a7d:
    DAT_23eedae40 = (longlong *)FUN_23e91f3b0(param_1,DAT_23eedaf08,DAT_23eedaeb8,0x38);
  }
  else {
    lVar8 = *DAT_23eedae40;
    if (1 < lVar8) {
      *DAT_23eedae40 = lVar8 + -1;
      goto LAB_23e749a7d;
    }
    if (DAT_23eedae40[2] != 0) {
      *DAT_23eedae40 = lVar8 + -1;
      if (lVar8 + -1 == 0) {
        (**(code **)(plVar6[1] + 0x30))(plVar6);
      }
      goto LAB_23e749a7d;
    }
  }
  plVar3 = DAT_23eedae40;
  lVar8 = *(longlong *)(param_1 + 0x38);
  plVar6 = DAT_23eedae40 + 9;
  lVar14 = *(longlong *)(lVar8 + 8);
  DAT_23eedae40[0xf] = lVar14;
  *(longlong **)(lVar8 + 8) = plVar6;
  if ((lVar14 != 0) &&
     (((*(char *)(lVar14 + 0x45) == '\x01' ||
       ((ulonglong)
        (*(longlong *)(lVar14 + 0x20) + 0xb8 +
        (longlong)*(int *)(*(longlong *)(lVar14 + 0x20) + 0xa8) * 2) <=
        *(ulonglong *)(lVar14 + 0x38))) && (plVar3[0xe] != 0)))) {
    plVar6 = *(longlong **)(lVar14 + 0x28);
    *(longlong **)(plVar3[0xe] + 0x10) = plVar6;
    if (plVar6 != (longlong *)0x0) {
      *plVar6 = *plVar6 + 1;
    }
  }
  lVar8 = DAT_23eed90d0;
  *plVar3 = *plVar3 + 1;
  *(undefined4 *)(plVar3 + 8) = 0;
  uVar4 = DAT_23eed8b40;
  *(undefined4 *)(plVar3 + 5) = 0x2ca;
  plVar6 = (longlong *)FUN_23e915840(param_1,plVar1,uVar4,*(undefined8 *)(lVar8 + 0x18));
  if (plVar6 == (longlong *)0x0) {
    local_78 = *(undefined1 (*) [8])(param_1 + 0x60);
    pcStack_70 = *(code **)(param_1 + 0x68);
    local_68[0] = *(code **)(param_1 + 0x70);
    *(undefined8 *)(param_1 + 0x70) = 0;
    *(undefined1 (*) [16])(param_1 + 0x60) = (undefined1  [16])0x0;
    if (local_68[0] != (code *)0x0) {
      if (*(longlong **)(local_68[0] + 0x18) == plVar3) goto LAB_23e74ab7c;
      plVar6 = (longlong *)0x0;
      pcVar9 = (code *)0x0;
      plVar10 = (longlong *)0x0;
      local_f0 = (longlong *)0x0;
      iVar5 = 0x2ca;
      local_e8 = _PyRuntime_exref;
      local_e0 = (longlong *)&DAT_23ed6a4f8;
      plVar7 = (longlong *)0x0;
      goto LAB_23e74a8c0;
    }
    plVar6 = (longlong *)0x0;
    pcVar9 = (code *)0x0;
    plVar10 = (longlong *)0x0;
    local_f0 = (longlong *)0x0;
    iVar5 = 0x2ca;
    local_e8 = _PyRuntime_exref;
    local_e0 = (longlong *)&DAT_23ed6a4f8;
    plVar7 = (longlong *)0x0;
    goto LAB_23e74ae40;
  }
  *plVar6 = *plVar6 + -1;
  if (*plVar6 == 0) {
    (**(code **)(plVar6[1] + 0x30))(plVar6);
  }
  plVar6 = (longlong *)FUN_23e8bc2f0(plVar1,DAT_23eed8aa8);
  if (plVar6 == (longlong *)0x0) {
    local_78 = *(undefined1 (*) [8])(param_1 + 0x60);
    pcStack_70 = *(code **)(param_1 + 0x68);
    local_68[0] = *(code **)(param_1 + 0x70);
    *(undefined8 *)(param_1 + 0x70) = 0;
    *(undefined1 (*) [16])(param_1 + 0x60) = (undefined1  [16])0x0;
    if (local_68[0] != (code *)0x0) {
      plVar6 = *(longlong **)(local_68[0] + 0x18);
      goto joined_r0x00023e74a87e;
    }
LAB_23e74b9c0:
    plVar6 = (longlong *)0x0;
    pcVar9 = (code *)0x0;
    plVar10 = (longlong *)0x0;
    local_f0 = (longlong *)0x0;
    plVar7 = (longlong *)0x0;
    iVar5 = 0x2cd;
    local_e8 = _PyRuntime_exref;
    local_e0 = (longlong *)&DAT_23ed6a4f8;
    goto LAB_23e74ae40;
  }
  iVar5 = FUN_23e913250(plVar6,DAT_23eed90d8);
  *plVar6 = *plVar6 + -1;
  if (*plVar6 == 0) {
    (**(code **)(plVar6[1] + 0x30))();
  }
  if (iVar5 == -1) {
    local_78 = *(undefined1 (*) [8])(param_1 + 0x60);
    pcStack_70 = *(code **)(param_1 + 0x68);
    local_68[0] = *(code **)(param_1 + 0x70);
    *(undefined8 *)(param_1 + 0x70) = 0;
    *(undefined1 (*) [16])(param_1 + 0x60) = (undefined1  [16])0x0;
    if (local_68[0] == (code *)0x0) goto LAB_23e74b9c0;
    plVar6 = *(longlong **)(local_68[0] + 0x18);
joined_r0x00023e74a87e:
    if (plVar3 == plVar6) {
LAB_23e74ab7c:
      local_f0 = (longlong *)0x0;
      plVar6 = (longlong *)0x0;
      pcVar9 = (code *)0x0;
      plVar10 = (longlong *)0x0;
      plVar7 = (longlong *)0x0;
      pcVar13 = local_68[0];
      goto LAB_23e74a964;
    }
    plVar7 = (longlong *)0x0;
    local_f0 = (longlong *)0x0;
    pcVar9 = (code *)0x0;
    plVar6 = (longlong *)0x0;
    plVar10 = (longlong *)0x0;
    iVar5 = 0x2cd;
    local_e0 = (longlong *)&DAT_23ed6a4f8;
    local_e8 = _PyRuntime_exref;
LAB_23e74a8c0:
    pcVar17 = local_68[0];
    pcVar13 = (code *)*local_e0;
    if (pcVar13 == (code *)0x0) {
      pcVar13 = (code *)FUN_23a33a530(PyTraceBack_Type_exref);
    }
    else {
      *local_e0 = *(longlong *)pcVar13;
      *(longlong *)pcVar13 = 1;
      DAT_23ed6a4f0 = DAT_23ed6a4f0 + -1;
    }
    *(longlong **)(pcVar13 + 0x18) = plVar3;
    *plVar3 = *plVar3 + 1;
    lVar8 = *(longlong *)(local_e8 + 0x1f8);
    *(int *)(pcVar13 + 0x24) = iVar5;
    *(undefined4 *)(pcVar13 + 0x20) = 0xffffffff;
    lVar8 = *(longlong *)(*(longlong *)(lVar8 + 0x10) + 0x2e8);
    lVar14 = *(longlong *)(pcVar13 + -8);
    puVar2 = *(undefined8 **)(lVar8 + 8);
    *puVar2 = pcVar13 + -0x10;
    *(longlong *)(pcVar13 + -0x10) = lVar8;
    *(ulonglong *)(pcVar13 + -8) = (ulonglong)((uint)lVar14 & 3) | (ulonglong)puVar2;
    *(code **)(lVar8 + 8) = pcVar13 + -0x10;
    *(code **)(pcVar13 + 0x10) = pcVar17;
    *(longlong *)pcVar17 = *(longlong *)pcVar17 + 1;
    pcVar17 = local_68[0];
  }
  else {
    if (iVar5 == 1) {
      plVar7 = (longlong *)FUN_23e8e0660();
      if (plVar7 != (longlong *)0x0) goto LAB_23e749b94;
      FUN_23e915740(param_1,local_78,DAT_23eed90e0);
      if (local_68[0] == (code *)0x0) {
        plVar6 = (longlong *)0x0;
        pcVar9 = (code *)0x0;
        plVar10 = (longlong *)0x0;
        local_f0 = (longlong *)0x0;
        iVar5 = 0x2ce;
        local_e8 = _PyRuntime_exref;
        local_e0 = (longlong *)&DAT_23ed6a4f8;
        goto LAB_23e74ae40;
      }
      if (plVar3 == *(longlong **)(local_68[0] + 0x18)) goto LAB_23e74ab7c;
      plVar6 = (longlong *)0x0;
      pcVar9 = (code *)0x0;
      plVar10 = (longlong *)0x0;
      local_f0 = (longlong *)0x0;
      iVar5 = 0x2ce;
      local_e8 = _PyRuntime_exref;
      local_e0 = (longlong *)&DAT_23ed6a4f8;
      goto LAB_23e74a8c0;
    }
    plVar7 = (longlong *)FUN_23e8e0510();
    if (plVar7 == (longlong *)0x0) {
      FUN_23e915740(param_1,local_78,DAT_23eed90e8);
      if (local_68[0] == (code *)0x0) {
        local_e8 = _PyRuntime_exref;
        plVar6 = (longlong *)0x0;
        pcVar9 = (code *)0x0;
        plVar10 = (longlong *)0x0;
        local_f0 = (longlong *)0x0;
        iVar5 = 0x2d0;
        local_e0 = (longlong *)&DAT_23ed6a4f8;
        goto LAB_23e74ae40;
      }
      if (plVar3 != *(longlong **)(local_68[0] + 0x18)) {
        plVar6 = (longlong *)0x0;
        pcVar9 = (code *)0x0;
        plVar10 = (longlong *)0x0;
        local_f0 = (longlong *)0x0;
        iVar5 = 0x2d0;
        local_e8 = _PyRuntime_exref;
        local_e0 = (longlong *)&DAT_23ed6a4f8;
        goto LAB_23e74a8c0;
      }
      goto LAB_23e74ab7c;
    }
LAB_23e749b94:
    *plVar7 = *plVar7 + 1;
    lVar8 = FUN_23e8e03c0();
    if (lVar8 == 0) {
      FUN_23e915740(param_1,local_78,DAT_23eed90f0);
      local_f0 = (longlong *)0x0;
joined_r0x00023e74ae02:
      local_e8 = _PyRuntime_exref;
      if (local_68[0] != (code *)0x0) {
        plVar6 = (longlong *)0x0;
        pcVar9 = (code *)0x0;
        plVar10 = (longlong *)0x0;
        pcVar13 = local_68[0];
        if (*(longlong **)(local_68[0] + 0x18) == plVar3) goto LAB_23e74a964;
        iVar5 = 0x2d3;
        local_e0 = (longlong *)&DAT_23ed6a4f8;
        goto LAB_23e74a8c0;
      }
      plVar6 = (longlong *)0x0;
      pcVar9 = (code *)0x0;
      plVar10 = (longlong *)0x0;
      local_f0 = (longlong *)0x0;
      iVar5 = 0x2d3;
      local_e0 = (longlong *)&DAT_23ed6a4f8;
    }
    else {
      *(undefined4 *)(plVar3 + 5) = 0x2d3;
      local_f0 = (longlong *)FUN_23e914090(param_1,lVar8,plVar7);
      if (local_f0 == (longlong *)0x0) {
        local_78 = *(undefined1 (*) [8])(param_1 + 0x60);
        pcStack_70 = *(code **)(param_1 + 0x68);
        local_68[0] = *(code **)(param_1 + 0x70);
        *(undefined8 *)(param_1 + 0x70) = 0;
        *(undefined1 (*) [16])(param_1 + 0x60) = (undefined1  [16])0x0;
        goto joined_r0x00023e74ae02;
      }
      pcVar9 = (code *)FUN_23e8bc2f0(plVar1,DAT_23eed8b40);
      plVar10 = DAT_23eed90f8;
      if (pcVar9 == (code *)0x0) {
        local_78 = *(undefined1 (*) [8])(param_1 + 0x60);
        pcStack_70 = *(code **)(param_1 + 0x68);
        local_68[0] = *(code **)(param_1 + 0x70);
        *(undefined8 *)(param_1 + 0x70) = 0;
        *(undefined1 (*) [16])(param_1 + 0x60) = (undefined1  [16])0x0;
        if (local_68[0] == (code *)0x0) {
          local_e8 = _PyRuntime_exref;
          goto LAB_23e74b11c;
        }
        if (plVar3 != *(longlong **)(local_68[0] + 0x18)) {
          local_e8 = _PyRuntime_exref;
          plVar6 = (longlong *)0x0;
          plVar10 = (longlong *)0x0;
          iVar5 = 0x2d5;
          local_e0 = (longlong *)&DAT_23ed6a4f8;
          goto LAB_23e74a8c0;
        }
LAB_23e74b07b:
        plVar6 = (longlong *)0x0;
        pcVar9 = (code *)0x0;
        plVar10 = (longlong *)0x0;
        pcVar13 = local_68[0];
        goto LAB_23e74a964;
      }
      lVar8 = *(longlong *)(param_1 + 0x10);
      plVar6 = *(longlong **)(lVar8 + 0xe20);
      if (plVar6 == (longlong *)0x0) {
        plVar6 = (longlong *)FUN_23e916a20(PyTuple_Type_exref,2);
      }
      else {
        lVar14 = plVar6[3];
        *(int *)(lVar8 + 0xebc) = *(int *)(lVar8 + 0xebc) + -1;
        *(longlong *)(lVar8 + 0xe20) = lVar14;
        *plVar6 = 1;
      }
      local_e8 = _PyRuntime_exref;
      plVar6[4] = 0;
      lVar8 = *(longlong *)(*(longlong *)(*(longlong *)(local_e8 + 0x1f8) + 0x10) + 0x2e8);
      lVar14 = plVar6[-1];
      puVar2 = *(undefined8 **)(lVar8 + 8);
      *puVar2 = plVar6 + -2;
      plVar6[-2] = lVar8;
      plVar6[-1] = (ulonglong)((uint)lVar14 & 3) | (ulonglong)puVar2;
      *(longlong **)(lVar8 + 8) = plVar6 + -2;
      *plVar10 = *plVar10 + 1;
      plVar6[3] = (longlong)plVar10;
      uVar4 = DAT_23ed6cd28;
      if (DAT_23ed6a4c0 == (longlong *)0x0) {
        plVar11 = (longlong *)PyDict_GetItemString(DAT_23ed6ccc0,"format");
        if (plVar11 != (longlong *)0x0) {
          *plVar11 = *plVar11 + 1;
          DAT_23ed6a4c0 = plVar11;
          goto LAB_23e749c9c;
        }
LAB_23e74bb80:
        PyErr_PrintEx(0);
        Py_Exit(1);
LAB_23e74bb93:
        auVar20 = *(undefined1 (*) [8])PyExc_RuntimeError_exref;
        pcVar17 = (code *)PyUnicode_FromString("No active exception to reraise");
        pcVar13 = (code *)0x0;
        pcVar18 = *(code **)(param_1 + 0x138);
        iVar5 = 0x2da;
        *(longlong *)auVar20 = *(longlong *)auVar20 + 1;
LAB_23e74b4ca:
        *(longlong **)(param_1 + 0x138) = local_c0;
        if (pcVar18 == (code *)0x0) {
          local_68[0] = pcVar13;
          local_78 = auVar20;
          pcStack_70 = pcVar17;
          if (pcVar13 == (code *)0x0) goto LAB_23e74ae40;
        }
        else {
LAB_23e74b380:
          local_68[0] = (code *)0x0;
          _local_78 = (undefined1  [16])0x0;
          *(longlong *)pcVar18 = *(longlong *)pcVar18 + -1;
          if (*(longlong *)pcVar18 == 0) {
            (**(code **)(*(longlong *)(pcVar18 + 8) + 0x30))();
          }
          local_78 = auVar20;
          pcStack_70 = pcVar17;
          if (pcVar13 == (code *)0x0) {
            local_68[0] = pcVar13;
            if (iVar5 == 0) {
              iVar5 = (int)plVar3[5];
            }
            goto LAB_23e74ae40;
          }
        }
        if (*(longlong **)(pcVar13 + 0x18) == plVar3) goto LAB_23e74a964;
        local_68[0] = pcVar13;
        if (iVar5 == 0) {
          iVar5 = (int)plVar3[5];
        }
        goto LAB_23e74a8c0;
      }
LAB_23e749c9c:
      local_98._8_8_ = uVar4;
      local_98._0_8_ = plVar7;
      lVar8 = FUN_23e94ed00(param_1,DAT_23ed6a4c0,local_98);
      if (lVar8 == 0) {
        local_78 = *(undefined1 (*) [8])(param_1 + 0x60);
        pcStack_70 = *(code **)(param_1 + 0x68);
        local_68[0] = *(code **)(param_1 + 0x70);
        *(undefined8 *)(param_1 + 0x70) = 0;
        *(undefined1 (*) [16])(param_1 + 0x60) = (undefined1  [16])0x0;
        *(longlong *)pcVar9 = *(longlong *)pcVar9 + -1;
        if (*(longlong *)pcVar9 == 0) {
          (**(code **)(*(longlong *)(pcVar9 + 8) + 0x30))();
        }
        *plVar6 = *plVar6 + -1;
        if (*plVar6 == 0) {
          (**(code **)(plVar6[1] + 0x30))();
          if (local_68[0] == (code *)0x0) goto LAB_23e74b11c;
LAB_23e74ac16:
          plVar6 = *(longlong **)(local_68[0] + 0x18);
        }
        else {
LAB_23e74b068:
          if (local_68[0] == (code *)0x0) goto LAB_23e74b11c;
          plVar6 = *(longlong **)(local_68[0] + 0x18);
        }
        plVar10 = (longlong *)0x0;
        if (plVar6 != plVar3) {
          plVar6 = (longlong *)0x0;
          pcVar9 = (code *)0x0;
          iVar5 = 0x2d5;
          local_e0 = (longlong *)&DAT_23ed6a4f8;
          goto LAB_23e74a8c0;
        }
        goto LAB_23e74b07b;
      }
      plVar6[4] = lVar8;
      plVar10 = (longlong *)PyUnicode_Join(DAT_23ed6cd28,plVar6);
      *plVar6 = *plVar6 + -1;
      if (*plVar6 == 0) {
        (**(code **)(plVar6[1] + 0x30))();
      }
      if (plVar10 == (longlong *)0x0) {
        local_78 = *(undefined1 (*) [8])(param_1 + 0x60);
        pcStack_70 = *(code **)(param_1 + 0x68);
        local_68[0] = *(code **)(param_1 + 0x70);
        *(undefined8 *)(param_1 + 0x70) = 0;
        *(undefined1 (*) [16])(param_1 + 0x60) = (undefined1  [16])0x0;
        *(longlong *)pcVar9 = *(longlong *)pcVar9 + -1;
        if (*(longlong *)pcVar9 != 0) goto LAB_23e74b068;
        (**(code **)(*(longlong *)(pcVar9 + 8) + 0x30))();
        if (local_68[0] != (code *)0x0) goto LAB_23e74ac16;
      }
      else {
        *(undefined4 *)(plVar3 + 5) = 0x2d5;
        plVar6 = (longlong *)FUN_23e914090(param_1,pcVar9,plVar10);
        *(longlong *)pcVar9 = *(longlong *)pcVar9 + -1;
        if (*(longlong *)pcVar9 == 0) {
          (**(code **)(*(longlong *)(pcVar9 + 8) + 0x30))();
        }
        *plVar10 = *plVar10 + -1;
        if (*plVar10 == 0) {
          (**(code **)(plVar10[1] + 0x30))();
        }
        if (plVar6 != (longlong *)0x0) {
          *plVar6 = *plVar6 + -1;
          if (*plVar6 == 0) {
            (**(code **)(plVar6[1] + 0x30))(plVar6);
          }
          plVar10 = DAT_23ed6ccf0;
          *DAT_23ed6ccf0 = *DAT_23ed6ccf0 + 1;
          if (plVar1 == (longlong *)0x0) {
            pcStack_70 = (code *)PyUnicode_FromFormat
                                           ("cannot access local variable \'%U\' where it is not associated with a value"
                                            ,DAT_23eed8d30);
            pcVar9 = _Py_NoneStruct_exref;
            local_d0 = _Py_NoneStruct_exref;
            local_78 = *(undefined1 (*) [8])PyExc_UnboundLocalError_exref;
            *(longlong *)local_78 = *(longlong *)local_78 + 1;
            local_68[0] = (code *)0x0;
            if (local_78 != (undefined1  [8])pcVar9) {
              FUN_23e91b1b0(param_1,local_78,local_78 + 8,local_68);
            }
            plVar6 = (longlong *)0x0;
            pcVar9 = (code *)0x0;
            FUN_23ebf6a40(*(undefined8 *)(param_1 + 0x138),pcStack_70);
            uVar19 = 0x2db;
          }
          else {
            pcVar9 = (code *)0x0;
            plVar6 = (longlong *)0x0;
LAB_23e749d6a:
            do {
              plVar11 = (longlong *)FUN_23e8bc2f0(plVar1,DAT_23eed8a08);
              if (plVar11 == (longlong *)0x0) {
LAB_23e74a140:
                local_68[0] = *(code **)(param_1 + 0x70);
                local_78 = *(undefined1 (*) [8])(param_1 + 0x60);
                pcStack_70 = *(code **)(param_1 + 0x68);
                *(undefined8 *)(param_1 + 0x70) = 0;
                uVar19 = 0x2db;
                local_d0 = _Py_NoneStruct_exref;
                *(undefined1 (*) [16])(param_1 + 0x60) = (undefined1  [16])0x0;
                goto LAB_23e74a180;
              }
              *(undefined4 *)(plVar3 + 5) = 0x2db;
              plVar12 = (longlong *)FUN_23e91bfe0(param_1,plVar11,DAT_23eed8d38);
              *plVar11 = *plVar11 + -1;
              if (*plVar11 == 0) {
                (**(code **)(plVar11[1] + 0x30))(plVar11);
              }
              if (plVar12 == (longlong *)0x0) goto LAB_23e74a140;
              iVar5 = FUN_23a35f020(plVar12);
              *plVar12 = *plVar12 + -1;
              if (*plVar12 == 0) {
                (**(code **)(plVar12[1] + 0x30))(plVar12);
              }
              if (iVar5 == -1) goto LAB_23e74a140;
              pcVar13 = _Py_FalseStruct_exref;
              if (iVar5 == 0) {
                pcVar13 = _Py_TrueStruct_exref;
              }
              iVar5 = FUN_23a35f020(pcVar13);
              lVar8 = DAT_23eed8fe8;
              if (iVar5 == 1) {
                *(undefined4 *)(plVar3 + 5) = 0x2db;
                pcVar13 = (code *)FUN_23e915840(param_1,plVar1,DAT_23eed9100,
                                                *(undefined8 *)(lVar8 + 0x18));
                if (pcVar13 == (code *)0x0) goto LAB_23e74a140;
              }
              else {
                *(longlong *)pcVar13 = *(longlong *)pcVar13 + 1;
              }
              iVar5 = FUN_23a35f020(pcVar13);
              *(longlong *)pcVar13 = *(longlong *)pcVar13 + -1;
              if (*(longlong *)pcVar13 == 0) {
                (**(code **)(*(longlong *)(pcVar13 + 8) + 0x30))(pcVar13);
              }
              if (iVar5 == -1) goto LAB_23e74a140;
              if (iVar5 == 0) goto LAB_23e74a595;
              plVar11 = (longlong *)FUN_23e8bc2f0(plVar1,DAT_23eed8a98);
              if (plVar11 == (longlong *)0x0) {
LAB_23e74b2b0:
                local_68[0] = *(code **)(param_1 + 0x70);
                local_78 = *(undefined1 (*) [8])(param_1 + 0x60);
                pcStack_70 = *(code **)(param_1 + 0x68);
                *(undefined8 *)(param_1 + 0x70) = 0;
                uVar19 = 0x2dc;
                local_d0 = _Py_NoneStruct_exref;
                *(undefined1 (*) [16])(param_1 + 0x60) = (undefined1  [16])0x0;
                goto LAB_23e74a180;
              }
              *(undefined4 *)(plVar3 + 5) = 0x2dc;
              pcVar13 = (code *)FUN_23e91bfe0(param_1,plVar11,DAT_23eed8a98);
              *plVar11 = *plVar11 + -1;
              if (*plVar11 == 0) {
                (**(code **)(plVar11[1] + 0x30))(plVar11);
              }
              if (pcVar13 == (code *)0x0) goto LAB_23e74b2b0;
              if ((pcVar9 != (code *)0x0) &&
                 (*(longlong *)pcVar9 = *(longlong *)pcVar9 + -1, *(longlong *)pcVar9 == 0)) {
                (**(code **)(*(longlong *)(pcVar9 + 8) + 0x30))(pcVar9);
              }
              local_d0 = _Py_NoneStruct_exref;
              pcVar9 = pcVar13;
              if (pcVar13 == _Py_NoneStruct_exref) {
                lVar14 = FUN_23e8e0ba0();
                lVar8 = DAT_23eed8e78;
                if (lVar14 == 0) {
                  FUN_23e915740(param_1,local_78,DAT_23eed8c70);
                }
                else {
                  *(undefined4 *)(plVar3 + 5) = 0x2de;
                  plVar11 = (longlong *)
                            FUN_23e915840(param_1,lVar14,DAT_23eed8d40,*(undefined8 *)(lVar8 + 0x18)
                                         );
                  if (plVar11 != (longlong *)0x0) {
                    *plVar11 = *plVar11 + -1;
                    if (*plVar11 == 0) {
                      (**(code **)(plVar11[1] + 0x30))(plVar11);
                    }
                    goto LAB_23e749d6a;
                  }
                  local_78 = *(undefined1 (*) [8])(param_1 + 0x60);
                  pcStack_70 = *(code **)(param_1 + 0x68);
                  local_68[0] = *(code **)(param_1 + 0x70);
                  *(undefined8 *)(param_1 + 0x70) = 0;
                  *(undefined1 (*) [16])(param_1 + 0x60) = (undefined1  [16])0x0;
                }
                uVar19 = 0x2de;
                pcVar9 = _Py_NoneStruct_exref;
                goto LAB_23e74a180;
              }
              *(undefined4 *)(plVar3 + 5) = 0x2e2;
              plVar11 = (longlong *)FUN_23e915840(param_1,local_f0,DAT_23eed9108,pcVar13);
              if (plVar11 == (longlong *)0x0) {
                local_78 = *(undefined1 (*) [8])(param_1 + 0x60);
                pcStack_70 = *(code **)(param_1 + 0x68);
                local_68[0] = *(code **)(param_1 + 0x70);
                *(undefined8 *)(param_1 + 0x70) = 0;
                uVar19 = 0x2e2;
                *(undefined1 (*) [16])(param_1 + 0x60) = (undefined1  [16])0x0;
                goto LAB_23e74a180;
              }
              if ((plVar6 != (longlong *)0x0) && (*plVar6 = *plVar6 + -1, *plVar6 == 0)) {
                (**(code **)(plVar6[1] + 0x30))(plVar6);
              }
              plVar6 = plVar11;
              if (plVar10 == (longlong *)0x0) {
                pcStack_70 = (code *)PyUnicode_FromFormat
                                               ("cannot access local variable \'%U\' where it is not associated with a value"
                                                ,DAT_23eed9110);
                local_78 = *(undefined1 (*) [8])PyExc_UnboundLocalError_exref;
                *(longlong *)local_78 = *(longlong *)local_78 + 1;
                local_68[0] = (code *)0x0;
                if (local_78 != (undefined1  [8])_Py_NoneStruct_exref) {
                  FUN_23e91b1b0(param_1,local_78,local_78 + 8,local_68);
                }
                FUN_23ebf6a40(*(undefined8 *)(param_1 + 0x138),pcStack_70);
                uVar19 = 0x2e4;
                goto LAB_23e74a180;
              }
              local_98._0_8_ = plVar10;
              FUN_23e8d34a0(local_98);
              lVar8 = *(longlong *)(param_1 + 0x10);
              plVar10 = (longlong *)local_98._0_8_;
              if ((((*(int *)(*(longlong *)(lVar8 + 0x28) + 0x160) != 0) ||
                   (*(int *)(lVar8 + 0x78) != 0)) && (iVar5 = Py_MakePendingCalls(), iVar5 < 0)) &&
                 (pcVar13 = *(code **)(param_1 + 0x60), pcVar13 != (code *)0x0)) goto LAB_23e74b01b;
              if (*(int *)(lVar8 + 0x68) != 0) {
                PyEval_SaveThread();
                PyEval_AcquireThread(param_1);
              }
              plVar11 = *(longlong **)(param_1 + 0x90);
            } while (plVar11 == (longlong *)0x0);
            plVar12 = *(longlong **)(param_1 + 0x60);
            plVar15 = *(longlong **)(param_1 + 0x68);
            plVar16 = *(longlong **)(param_1 + 0x70);
            *(longlong **)(param_1 + 0x60) = plVar11;
            *(undefined8 *)(param_1 + 0x90) = 0;
            *plVar11 = *plVar11 + 1;
            *(undefined8 *)(param_1 + 0x68) = 0;
            *(undefined8 *)(param_1 + 0x70) = 0;
            if ((plVar12 != (longlong *)0x0) && (*plVar12 = *plVar12 + -1, *plVar12 == 0)) {
              (**(code **)(plVar12[1] + 0x30))();
            }
            if ((plVar15 != (longlong *)0x0) && (*plVar15 = *plVar15 + -1, *plVar15 == 0)) {
              (**(code **)(plVar15[1] + 0x30))(plVar15);
            }
            if ((plVar16 != (longlong *)0x0) && (*plVar16 = *plVar16 + -1, *plVar16 == 0)) {
              (**(code **)(plVar16[1] + 0x30))(plVar16);
            }
            pcVar13 = *(code **)(param_1 + 0x60);
LAB_23e74b01b:
            local_68[0] = *(code **)(param_1 + 0x70);
            *(undefined8 *)(param_1 + 0x70) = 0;
            pcStack_70 = *(code **)(param_1 + 0x68);
            uVar19 = 0x2db;
            *(undefined1 (*) [16])(param_1 + 0x60) = (undefined1  [16])0x0;
            local_78 = (undefined1  [8])pcVar13;
          }
LAB_23e74a180:
          pcVar13 = local_68[0];
          local_98._8_8_ = pcStack_70;
          local_98._0_8_ = local_78;
          local_68[0] = (code *)0x0;
          local_78 = (undefined1  [8])0x0;
          pcStack_70 = (code *)0x0;
          local_88[0] = pcVar13;
          local_c0 = *(longlong **)(param_1 + 0x138);
          if (local_c0 != (longlong *)0x0) {
            *local_c0 = *local_c0 + 1;
          }
          pcVar17 = DAT_23ed6a4f8;
          local_e0 = (longlong *)&DAT_23ed6a4f8;
          if (pcVar13 == (code *)0x0) {
            if (DAT_23ed6a4f8 == (code *)0x0) {
              pcVar17 = (code *)FUN_23a33a530(PyTraceBack_Type_exref);
            }
            else {
              pcVar13 = *(code **)DAT_23ed6a4f8;
              *(longlong *)DAT_23ed6a4f8 = 1;
              DAT_23ed6a4f8 = pcVar13;
              DAT_23ed6a4f0 = DAT_23ed6a4f0 + -1;
            }
            *(longlong *)(pcVar17 + 0x10) = 0;
            *(longlong **)(pcVar17 + 0x18) = plVar3;
            *plVar3 = *plVar3 + 1;
            lVar8 = *(longlong *)(local_e8 + 0x1f8);
            *(undefined4 *)(pcVar17 + 0x24) = uVar19;
            lVar8 = *(longlong *)(lVar8 + 0x10);
            *(undefined4 *)(pcVar17 + 0x20) = 0xffffffff;
            lVar8 = *(longlong *)(lVar8 + 0x2e8);
            lVar14 = *(longlong *)(pcVar17 + -8);
            puVar2 = *(undefined8 **)(lVar8 + 8);
            *puVar2 = pcVar17 + -0x10;
            *(longlong *)(pcVar17 + -0x10) = lVar8;
            *(ulonglong *)(pcVar17 + -8) = (ulonglong)((uint)lVar14 & 3) | (ulonglong)puVar2;
            *(code **)(lVar8 + 8) = pcVar17 + -0x10;
            if ((local_88[0] != (code *)0x0) &&
               (*(longlong *)local_88[0] = *(longlong *)local_88[0] + -1,
               *(longlong *)local_88[0] == 0)) {
              (**(code **)(*(longlong *)(local_88[0] + 8) + 0x30))(local_88[0]);
            }
          }
          else {
            if (DAT_23ed6a4f8 == (code *)0x0) {
              pcVar17 = (code *)FUN_23a33a530(PyTraceBack_Type_exref);
            }
            else {
              pcVar18 = *(code **)DAT_23ed6a4f8;
              *(longlong *)DAT_23ed6a4f8 = 1;
              DAT_23ed6a4f8 = pcVar18;
              DAT_23ed6a4f0 = DAT_23ed6a4f0 + -1;
            }
            *(longlong **)(pcVar17 + 0x18) = plVar3;
            *plVar3 = *plVar3 + 1;
            lVar8 = *(longlong *)(local_e8 + 0x1f8);
            *(undefined4 *)(pcVar17 + 0x24) = uVar19;
            *(undefined4 *)(pcVar17 + 0x20) = 0xffffffff;
            lVar8 = *(longlong *)(*(longlong *)(lVar8 + 0x10) + 0x2e8);
            lVar14 = *(longlong *)(pcVar17 + -8);
            puVar2 = *(undefined8 **)(lVar8 + 8);
            *puVar2 = pcVar17 + -0x10;
            *(longlong *)(pcVar17 + -0x10) = lVar8;
            *(ulonglong *)(pcVar17 + -8) = (ulonglong)((uint)lVar14 & 3) | (ulonglong)puVar2;
            *(code **)(lVar8 + 8) = pcVar17 + -0x10;
            *(code **)(pcVar17 + 0x10) = pcVar13;
            *(longlong *)pcVar13 = *(longlong *)pcVar13 + 1;
            if ((local_88[0] != (code *)0x0) &&
               (*(longlong *)local_88[0] = *(longlong *)local_88[0] + -1,
               *(longlong *)local_88[0] == 0)) {
              (**(code **)(*(longlong *)(local_88[0] + 8) + 0x30))();
            }
          }
          local_88[0] = pcVar17;
          if (((code *)local_98._0_8_ != local_d0) && ((code *)local_98._0_8_ != (code *)0x0)) {
            FUN_23e91b1b0(param_1,local_98,local_98 + 8,local_88);
          }
          plVar11 = *(longlong **)(local_98._8_8_ + 0x28);
          if (local_88[0] == local_d0) {
            pcVar13 = (code *)0x0;
          }
          else {
            pcVar13 = local_88[0];
            if (local_88[0] != (code *)0x0) {
              *(longlong *)local_88[0] = *(longlong *)local_88[0] + 1;
            }
          }
          *(code **)(local_98._8_8_ + 0x28) = pcVar13;
          if ((plVar11 != (longlong *)0x0) && (*plVar11 = *plVar11 + -1, *plVar11 == 0)) {
            (**(code **)(plVar11[1] + 0x30))();
          }
          plVar11 = *(longlong **)(param_1 + 0x138);
          *(undefined8 *)(param_1 + 0x138) = local_98._8_8_;
          if ((plVar11 != (longlong *)0x0) && (*plVar11 = *plVar11 + -1, *plVar11 == 0)) {
            (**(code **)(plVar11[1] + 0x30))();
          }
          *(longlong *)local_98._0_8_ = *(longlong *)local_98._0_8_ + -1;
          if (*(longlong *)local_98._0_8_ == 0) {
            (**(code **)(*(longlong *)(local_98._0_8_ + 8) + 0x30))();
          }
          if ((local_88[0] != (code *)0x0) &&
             (*(longlong *)local_88[0] = *(longlong *)local_88[0] + -1,
             *(longlong *)local_88[0] == 0)) {
            (**(code **)(*(longlong *)(local_88[0] + 8) + 0x30))();
          }
          local_88[0] = (code *)0x0;
          local_98 = (undefined1  [16])0x0;
          iVar5 = FUN_23a35ebd0(param_1,*(undefined8 *)(*(longlong *)(param_1 + 0x138) + 8),
                                *(undefined8 *)PyExc_Exception_exref);
          if (iVar5 != 0) {
            plVar11 = *(longlong **)(param_1 + 0x138);
            *plVar11 = *plVar11 + 1;
            if (plVar1 == (longlong *)0x0) {
              pcStack_70 = (code *)PyUnicode_FromFormat
                                             ("cannot access local variable \'%U\' where it is not associated with a value"
                                              ,DAT_23eed8d30);
              local_78 = *(undefined1 (*) [8])PyExc_UnboundLocalError_exref;
              *(longlong *)local_78 = *(longlong *)local_78 + 1;
              local_68[0] = (code *)0x0;
              if (local_78 != (undefined1  [8])local_d0) {
                FUN_23e91b1b0(param_1,local_78,local_78 + 8,local_68);
              }
              FUN_23ebf6a40(*(undefined8 *)(param_1 + 0x138),pcStack_70);
              pcVar17 = pcStack_70;
              pcVar13 = local_68[0];
              auVar20 = local_78;
            }
            else {
              plVar15 = (longlong *)FUN_23e8bc2f0(plVar1,DAT_23eed8b40);
              plVar12 = DAT_23eed9118;
              if (plVar15 == (longlong *)0x0) {
                auVar20 = *(undefined1 (*) [8])(param_1 + 0x60);
                *(undefined1 (*) [16])(param_1 + 0x60) = (undefined1  [16])0x0;
                pcVar13 = *(code **)(param_1 + 0x70);
                *(undefined8 *)(param_1 + 0x70) = 0;
                pcVar17 = *(code **)(param_1 + 0x68);
              }
              else {
                lVar8 = *(longlong *)(param_1 + 0x10);
                plVar16 = *(longlong **)(lVar8 + 0xe20);
                if (plVar16 == (longlong *)0x0) {
                  plVar16 = (longlong *)FUN_23e916a20(PyTuple_Type_exref,2);
                }
                else {
                  lVar14 = plVar16[3];
                  *(int *)(lVar8 + 0xebc) = *(int *)(lVar8 + 0xebc) + -1;
                  *(longlong *)(lVar8 + 0xe20) = lVar14;
                  *plVar16 = 1;
                }
                plVar16[4] = 0;
                lVar8 = *(longlong *)(*(longlong *)(*(longlong *)(local_e8 + 0x1f8) + 0x10) + 0x2e8)
                ;
                lVar14 = plVar16[-1];
                puVar2 = *(undefined8 **)(lVar8 + 8);
                *puVar2 = plVar16 + -2;
                plVar16[-2] = lVar8;
                plVar16[-1] = (ulonglong)((uint)lVar14 & 3) | (ulonglong)puVar2;
                *(longlong **)(lVar8 + 8) = plVar16 + -2;
                *plVar12 = *plVar12 + 1;
                plVar16[3] = (longlong)plVar12;
                uVar4 = DAT_23ed6cd28;
                if (DAT_23ed6a4c0 == (longlong *)0x0) {
                  plVar12 = (longlong *)PyDict_GetItemString(DAT_23ed6ccc0,"format");
                  if (plVar12 == (longlong *)0x0) goto LAB_23e74bb80;
                  *plVar12 = *plVar12 + 1;
                  DAT_23ed6a4c0 = plVar12;
                }
                uStack_a0 = uVar4;
                local_a8 = plVar11;
                lVar8 = FUN_23e94ed00(param_1,DAT_23ed6a4c0,&local_a8);
                if (lVar8 == 0) {
                  local_78 = *(undefined1 (*) [8])(param_1 + 0x60);
                  pcStack_70 = *(code **)(param_1 + 0x68);
                  local_68[0] = *(code **)(param_1 + 0x70);
                  *(undefined8 *)(param_1 + 0x70) = 0;
                  *(undefined1 (*) [16])(param_1 + 0x60) = (undefined1  [16])0x0;
                  *plVar15 = *plVar15 + -1;
                  if (*plVar15 == 0) {
                    (**(code **)(plVar15[1] + 0x30))(plVar15);
                  }
                  *plVar16 = *plVar16 + -1;
                  pcVar17 = pcStack_70;
                  pcVar13 = local_68[0];
                  auVar20 = local_78;
                  if (*plVar16 == 0) {
                    (**(code **)(plVar16[1] + 0x30))(plVar16);
                    pcVar17 = pcStack_70;
                    pcVar13 = local_68[0];
                    auVar20 = local_78;
                  }
                }
                else {
                  plVar16[4] = lVar8;
                  plVar12 = (longlong *)PyUnicode_Join(DAT_23ed6cd28,plVar16);
                  *plVar16 = *plVar16 + -1;
                  if (*plVar16 == 0) {
                    (**(code **)(plVar16[1] + 0x30))(plVar16);
                  }
                  if (plVar12 == (longlong *)0x0) {
                    local_78 = *(undefined1 (*) [8])(param_1 + 0x60);
                    pcStack_70 = *(code **)(param_1 + 0x68);
                    local_68[0] = *(code **)(param_1 + 0x70);
                    *(undefined1 (*) [16])(param_1 + 0x60) = (undefined1  [16])0x0;
                    *(undefined8 *)(param_1 + 0x70) = 0;
                    *plVar15 = *plVar15 + -1;
                    pcVar17 = pcStack_70;
                    pcVar13 = local_68[0];
                    auVar20 = local_78;
                    if (*plVar15 == 0) {
                      (**(code **)(plVar15[1] + 0x30))(plVar15);
                      pcVar17 = pcStack_70;
                      pcVar13 = local_68[0];
                      auVar20 = local_78;
                    }
                  }
                  else {
                    *(undefined4 *)(plVar3 + 5) = 0x2e7;
                    plVar16 = (longlong *)FUN_23e914090(param_1,plVar15);
                    *plVar15 = *plVar15 + -1;
                    if (*plVar15 == 0) {
                      (**(code **)(plVar15[1] + 0x30))(plVar15);
                    }
                    *plVar12 = *plVar12 + -1;
                    if (*plVar12 == 0) {
                      (**(code **)(plVar12[1] + 0x30))(plVar12);
                    }
                    if (plVar16 != (longlong *)0x0) {
                      *plVar16 = *plVar16 + -1;
                      if (*plVar16 == 0) {
                        (**(code **)(plVar16[1] + 0x30))(plVar16);
                      }
                      *plVar11 = *plVar11 + -1;
                      if (*plVar11 == 0) {
                        (**(code **)(plVar11[1] + 0x30))(plVar11);
                      }
                      plVar11 = *(longlong **)(param_1 + 0x138);
                      *(longlong **)(param_1 + 0x138) = local_c0;
                      if ((plVar11 != (longlong *)0x0) && (*plVar11 = *plVar11 + -1, *plVar11 == 0))
                      {
                        (**(code **)(plVar11[1] + 0x30))();
                      }
LAB_23e74a595:
                      local_e0 = (longlong *)FUN_23e8bc2f0(plVar1,DAT_23eed8b40);
                      plVar11 = DAT_23eed9120;
                      if (local_e0 == (longlong *)0x0) {
                        local_78 = *(undefined1 (*) [8])(param_1 + 0x60);
                        pcStack_70 = *(code **)(param_1 + 0x68);
                        local_68[0] = *(code **)(param_1 + 0x70);
                        *(undefined8 *)(param_1 + 0x70) = 0;
                        *(undefined1 (*) [16])(param_1 + 0x60) = (undefined1  [16])0x0;
joined_r0x00023e74b9ac:
                        if (local_68[0] == (code *)0x0) {
LAB_23e74b81d:
                          iVar5 = 0x2e9;
                          local_e0 = (longlong *)&DAT_23ed6a4f8;
                          goto LAB_23e74ae40;
                        }
                        plVar11 = *(longlong **)(local_68[0] + 0x18);
                      }
                      else {
                        lVar8 = *(longlong *)(param_1 + 0x10);
                        plVar12 = *(longlong **)(lVar8 + 0xe28);
                        if (plVar12 == (longlong *)0x0) {
                          plVar12 = (longlong *)FUN_23e916a20(PyTuple_Type_exref,3);
                        }
                        else {
                          lVar14 = plVar12[3];
                          *(int *)(lVar8 + 0xec0) = *(int *)(lVar8 + 0xec0) + -1;
                          *(longlong *)(lVar8 + 0xe28) = lVar14;
                          *plVar12 = 1;
                        }
                        *(undefined1 (*) [16])(plVar12 + 4) = (undefined1  [16])0x0;
                        lVar8 = *(longlong *)
                                 (*(longlong *)(*(longlong *)(local_e8 + 0x1f8) + 0x10) + 0x2e8);
                        lVar14 = plVar12[-1];
                        puVar2 = *(undefined8 **)(lVar8 + 8);
                        *puVar2 = plVar12 + -2;
                        plVar12[-2] = lVar8;
                        plVar12[-1] = (ulonglong)((uint)lVar14 & 3) | (ulonglong)puVar2;
                        *(longlong **)(lVar8 + 8) = plVar12 + -2;
                        *plVar11 = *plVar11 + 1;
                        plVar12[3] = (longlong)plVar11;
                        uVar4 = DAT_23ed6cd28;
                        if (plVar10 == (longlong *)0x0) {
                          pcStack_70 = (code *)PyUnicode_FromFormat
                                                         (
                                                  "cannot access local variable \'%U\' where it is not associated with a value"
                                                  ,DAT_23eed9110);
                          local_78 = *(undefined1 (*) [8])PyExc_UnboundLocalError_exref;
                          *(longlong *)local_78 = *(longlong *)local_78 + 1;
                          local_68[0] = (code *)0x0;
                          if (local_78 != (undefined1  [8])_Py_NoneStruct_exref) {
                            FUN_23e91b1b0(param_1,local_78,local_78 + 8,local_68);
                          }
                          FUN_23ebf6a40(*(undefined8 *)(param_1 + 0x138),pcStack_70);
LAB_23e74b799:
                          *local_e0 = *local_e0 + -1;
                          if (*local_e0 == 0) {
                            (**(code **)(local_e0[1] + 0x30))();
                          }
                          *plVar12 = *plVar12 + -1;
                          if (*plVar12 == 0) {
                            (**(code **)(plVar12[1] + 0x30))();
                          }
                          goto joined_r0x00023e74b9ac;
                        }
                        if (DAT_23ed6a4c0 == (longlong *)0x0) {
                          plVar11 = (longlong *)PyDict_GetItemString(DAT_23ed6ccc0,"format");
                          if (plVar11 == (longlong *)0x0) goto LAB_23e74bb80;
                          *plVar11 = *plVar11 + 1;
                          DAT_23ed6a4c0 = plVar11;
                        }
                        uStack_a0 = uVar4;
                        local_a8 = plVar10;
                        lVar8 = FUN_23e94ed00(param_1,DAT_23ed6a4c0,&local_a8);
                        if (lVar8 == 0) {
                          local_68[0] = *(code **)(param_1 + 0x70);
                          local_78 = *(undefined1 (*) [8])(param_1 + 0x60);
                          pcStack_70 = *(code **)(param_1 + 0x68);
                          *(undefined8 *)(param_1 + 0x70) = 0;
                          *(undefined1 (*) [16])(param_1 + 0x60) = (undefined1  [16])0x0;
                          goto LAB_23e74b799;
                        }
                        plVar12[4] = lVar8;
                        plVar11 = DAT_23eed9128;
                        *DAT_23eed9128 = *DAT_23eed9128 + 1;
                        plVar12[5] = (longlong)plVar11;
                        plVar11 = (longlong *)PyUnicode_Join(DAT_23ed6cd28,plVar12);
                        *plVar12 = *plVar12 + -1;
                        if (*plVar12 == 0) {
                          (**(code **)(plVar12[1] + 0x30))();
                        }
                        if (plVar11 != (longlong *)0x0) {
                          *(undefined4 *)(plVar3 + 5) = 0x2e9;
                          plVar12 = (longlong *)FUN_23e914090(param_1,local_e0);
                          *local_e0 = *local_e0 + -1;
                          if (*local_e0 == 0) {
                            (**(code **)(local_e0[1] + 0x30))();
                          }
                          *plVar11 = *plVar11 + -1;
                          if (*plVar11 == 0) {
                            (**(code **)(plVar11[1] + 0x30))();
                          }
                          if (plVar12 != (longlong *)0x0) {
                            *plVar12 = *plVar12 + -1;
                            if (*plVar12 == 0) {
                              (**(code **)(plVar12[1] + 0x30))(plVar12);
                            }
                            lVar8 = *(longlong *)(*(longlong *)(param_1 + 0x38) + 8);
                            plVar3 = *(longlong **)(lVar8 + 0x28);
                            plVar11 = (longlong *)plVar3[2];
                            *(undefined8 *)(*(longlong *)(param_1 + 0x38) + 8) =
                                 *(undefined8 *)(lVar8 + 0x30);
                            *(undefined4 *)(plVar3 + 8) = 0xffffffff;
                            if (plVar11 != (longlong *)0x0) {
                              plVar3[2] = 0;
                              *plVar11 = *plVar11 + -1;
                              if (*plVar11 == 0) {
                                (**(code **)(plVar11[1] + 0x30))();
                              }
                            }
                            *plVar3 = *plVar3 + -1;
                            if (*plVar3 == 0) {
                              (**(code **)(plVar3[1] + 0x30))(plVar3);
                            }
                            pcVar13 = _Py_NoneStruct_exref;
                            plVar3[0xf] = 0;
                            *(longlong *)pcVar13 = *(longlong *)pcVar13 + 1;
                            *plVar7 = *plVar7 + -1;
                            if (*plVar7 == 0) {
                              (**(code **)(plVar7[1] + 0x30))(plVar7);
                            }
                            lVar8 = *local_f0;
                            *local_f0 = lVar8 + -1;
                            if (lVar8 + -1 == 0) {
                              (**(code **)(local_f0[1] + 0x30))(local_f0);
                            }
                            *plVar10 = *plVar10 + -1;
                            if (*plVar10 == 0) {
                              (**(code **)(plVar10[1] + 0x30))(plVar10);
                            }
                            if ((pcVar9 != (code *)0x0) &&
                               (*(longlong *)pcVar9 = *(longlong *)pcVar9 + -1,
                               *(longlong *)pcVar9 == 0)) {
                              (**(code **)(*(longlong *)(pcVar9 + 8) + 0x30))(pcVar9);
                            }
                            if ((plVar6 != (longlong *)0x0) &&
                               (*plVar6 = *plVar6 + -1, *plVar6 == 0)) {
                              (**(code **)(plVar6[1] + 0x30))(plVar6);
                            }
                            *plVar1 = *plVar1 + -1;
                            if (*plVar1 != 0) {
                              return pcVar13;
                            }
                            (**(code **)(plVar1[1] + 0x30))(plVar1);
                            return pcVar13;
                          }
                          local_78 = *(undefined1 (*) [8])(param_1 + 0x60);
                          pcStack_70 = *(code **)(param_1 + 0x68);
                          local_68[0] = *(code **)(param_1 + 0x70);
                          *(undefined8 *)(param_1 + 0x70) = 0;
                          *(undefined1 (*) [16])(param_1 + 0x60) = (undefined1  [16])0x0;
                          if (local_68[0] != (code *)0x0) goto LAB_23e74b188;
                          goto LAB_23e74b81d;
                        }
                        local_78 = *(undefined1 (*) [8])(param_1 + 0x60);
                        pcStack_70 = *(code **)(param_1 + 0x68);
                        local_68[0] = *(code **)(param_1 + 0x70);
                        *(undefined8 *)(param_1 + 0x70) = 0;
                        *(undefined1 (*) [16])(param_1 + 0x60) = (undefined1  [16])0x0;
                        *local_e0 = *local_e0 + -1;
                        if (*local_e0 != 0) goto joined_r0x00023e74b9ac;
                        (**(code **)(local_e0[1] + 0x30))();
                        if (local_68[0] == (code *)0x0) goto LAB_23e74b81d;
LAB_23e74b188:
                        plVar11 = *(longlong **)(local_68[0] + 0x18);
                      }
                      pcVar13 = local_68[0];
                      if (plVar11 == plVar3) goto LAB_23e74a964;
                      iVar5 = 0x2e9;
                      local_e0 = (longlong *)&DAT_23ed6a4f8;
                      goto LAB_23e74a8c0;
                    }
                    auVar20 = *(undefined1 (*) [8])(param_1 + 0x60);
                    pcVar13 = *(code **)(param_1 + 0x70);
                    *(undefined1 (*) [16])(param_1 + 0x60) = (undefined1  [16])0x0;
                    *(undefined8 *)(param_1 + 0x70) = 0;
                    pcVar17 = *(code **)(param_1 + 0x68);
                  }
                }
              }
            }
            local_68[0] = (code *)0x0;
            _local_78 = (undefined1  [16])0x0;
            *plVar11 = *plVar11 + -1;
            if (*plVar11 == 0) {
              (**(code **)(plVar11[1] + 0x30))(plVar11);
            }
            pcVar18 = *(code **)(param_1 + 0x138);
            iVar5 = 0x2e7;
            goto LAB_23e74b4ca;
          }
          pcVar17 = *(code **)(param_1 + 0x138);
          pcStack_70 = pcVar17;
          if ((pcVar17 == local_d0) || (pcVar17 == (code *)0x0)) goto LAB_23e74bb93;
          auVar20 = *(undefined1 (*) [8])(pcVar17 + 8);
          pcVar13 = *(code **)(pcVar17 + 0x28);
          *(longlong *)pcVar17 = *(longlong *)pcVar17 + 1;
          *(longlong *)auVar20 = *(longlong *)auVar20 + 1;
          iVar5 = 0;
          pcVar18 = pcVar17;
          if (pcVar13 == (code *)0x0) {
            *(longlong **)(param_1 + 0x138) = local_c0;
          }
          else {
            *(longlong *)pcVar13 = *(longlong *)pcVar13 + 1;
            if (*(longlong **)(pcVar13 + 0x18) == plVar3) {
              *(undefined4 *)(plVar3 + 5) = *(undefined4 *)(pcVar13 + 0x24);
            }
            *(longlong **)(param_1 + 0x138) = local_c0;
          }
          goto LAB_23e74b380;
        }
        local_78 = *(undefined1 (*) [8])(param_1 + 0x60);
        pcStack_70 = *(code **)(param_1 + 0x68);
        local_68[0] = *(code **)(param_1 + 0x70);
        *(undefined8 *)(param_1 + 0x70) = 0;
        *(undefined1 (*) [16])(param_1 + 0x60) = (undefined1  [16])0x0;
        if (local_68[0] != (code *)0x0) {
          if (*(longlong **)(local_68[0] + 0x18) != plVar3) {
            pcVar9 = (code *)0x0;
            plVar10 = (longlong *)0x0;
            iVar5 = 0x2d5;
            local_e0 = (longlong *)&DAT_23ed6a4f8;
            plVar6 = (longlong *)0x0;
            goto LAB_23e74a8c0;
          }
          goto LAB_23e74b07b;
        }
      }
LAB_23e74b11c:
      plVar6 = (longlong *)0x0;
      pcVar9 = (code *)0x0;
      plVar10 = (longlong *)0x0;
      iVar5 = 0x2d5;
      local_e0 = (longlong *)&DAT_23ed6a4f8;
    }
LAB_23e74ae40:
    pcVar13 = (code *)*local_e0;
    if (pcVar13 == (code *)0x0) {
      pcVar13 = (code *)FUN_23a33a530(PyTraceBack_Type_exref);
      pcVar17 = local_68[0];
    }
    else {
      *local_e0 = *(longlong *)pcVar13;
      *(longlong *)pcVar13 = 1;
      DAT_23ed6a4f0 = DAT_23ed6a4f0 + -1;
      pcVar17 = (code *)0x0;
    }
    *(longlong *)(pcVar13 + 0x10) = 0;
    *(longlong **)(pcVar13 + 0x18) = plVar3;
    *plVar3 = *plVar3 + 1;
    lVar8 = *(longlong *)(local_e8 + 0x1f8);
    *(int *)(pcVar13 + 0x24) = iVar5;
    lVar8 = *(longlong *)(lVar8 + 0x10);
    *(undefined4 *)(pcVar13 + 0x20) = 0xffffffff;
    lVar8 = *(longlong *)(lVar8 + 0x2e8);
    lVar14 = *(longlong *)(pcVar13 + -8);
    puVar2 = *(undefined8 **)(lVar8 + 8);
    *puVar2 = pcVar13 + -0x10;
    *(longlong *)(pcVar13 + -0x10) = lVar8;
    *(ulonglong *)(pcVar13 + -8) = (ulonglong)((uint)lVar14 & 3) | (ulonglong)puVar2;
    *(code **)(lVar8 + 8) = pcVar13 + -0x10;
  }
  if ((pcVar17 != (code *)0x0) &&
     (*(longlong *)pcVar17 = *(longlong *)pcVar17 + -1, *(longlong *)pcVar17 == 0)) {
    (**(code **)(*(longlong *)(pcVar17 + 8) + 0x30))();
  }
LAB_23e74a964:
  local_68[0] = pcVar13;
  FUN_23e8bba40(plVar3,"ooooooo",plVar1,plVar7,local_f0,plVar10,pcVar9,plVar6,0);
  if (DAT_23eedae40 == plVar3) {
    *plVar3 = *plVar3 + -1;
    if (*plVar3 == 0) {
      (**(code **)(plVar3[1] + 0x30))(plVar3);
    }
    DAT_23eedae40 = (longlong *)0x0;
  }
  lVar8 = *(longlong *)(*(longlong *)(param_1 + 0x38) + 8);
  plVar3 = *(longlong **)(lVar8 + 0x28);
  plVar11 = (longlong *)plVar3[2];
  *(undefined8 *)(*(longlong *)(param_1 + 0x38) + 8) = *(undefined8 *)(lVar8 + 0x30);
  *(undefined4 *)(plVar3 + 8) = 0xffffffff;
  if (plVar11 != (longlong *)0x0) {
    plVar3[2] = 0;
    *plVar11 = *plVar11 + -1;
    if (*plVar11 == 0) {
      (**(code **)(plVar11[1] + 0x30))();
    }
  }
  *plVar3 = *plVar3 + -1;
  if (*plVar3 == 0) {
    (**(code **)(plVar3[1] + 0x30))(plVar3);
  }
  pcVar17 = local_68[0];
  pcVar13 = pcStack_70;
  auVar20 = local_78;
  plVar3[0xf] = 0;
  _local_78 = (undefined1  [16])0x0;
  local_68[0] = (code *)0x0;
  if ((plVar7 != (longlong *)0x0) && (*plVar7 = *plVar7 + -1, *plVar7 == 0)) {
    (**(code **)(plVar7[1] + 0x30))(plVar7);
  }
  if ((local_f0 != (longlong *)0x0) && (lVar8 = *local_f0, *local_f0 = lVar8 + -1, lVar8 + -1 == 0))
  {
    (**(code **)(local_f0[1] + 0x30))();
  }
  if ((plVar10 != (longlong *)0x0) && (*plVar10 = *plVar10 + -1, *plVar10 == 0)) {
    (**(code **)(plVar10[1] + 0x30))(plVar10);
  }
  if ((pcVar9 != (code *)0x0) &&
     (*(longlong *)pcVar9 = *(longlong *)pcVar9 + -1, *(longlong *)pcVar9 == 0)) {
    (**(code **)(*(longlong *)(pcVar9 + 8) + 0x30))(pcVar9);
  }
  if ((plVar6 != (longlong *)0x0) && (*plVar6 = *plVar6 + -1, *plVar6 == 0)) {
    (**(code **)(plVar6[1] + 0x30))(plVar6);
  }
  *plVar1 = *plVar1 + -1;
  local_68[0] = pcVar17;
  local_78 = auVar20;
  pcStack_70 = pcVar13;
  if (*plVar1 == 0) {
    (**(code **)(plVar1[1] + 0x30))(plVar1);
  }
  FUN_23a33aa70(param_1,local_78,pcStack_70,local_68[0]);
  return (code *)0x0;
}
