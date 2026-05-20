/* ===== 23c0002b0 config_manager:59 ===== */
/* ghidra_name=FUN_23c0002b0 entry=23c0002b0 size=7078 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

code * FUN_23c0002b0(longlong param_1,undefined8 param_2,longlong *param_3)

{
  undefined1 (*pauVar1) [16];
  longlong *plVar2;
  longlong *plVar3;
  undefined8 *puVar4;
  longlong *plVar5;
  code *pcVar6;
  undefined1 auVar7 [16];
  bool bVar8;
  code *pcVar9;
  code *pcVar10;
  int iVar11;
  code *pcVar12;
  longlong *plVar13;
  longlong *plVar14;
  longlong *plVar15;
  longlong lVar16;
  longlong *plVar17;
  longlong *plVar18;
  longlong *plVar19;
  longlong *plVar20;
  longlong lVar21;
  undefined8 uVar22;
  code *pcVar23;
  code *pcVar24;
  code *pcVar25;
  code *pcVar26;
  code *pcVar27;
  longlong *plVar28;
  undefined4 uVar29;
  code *local_110;
  code *local_108;
  code *local_e8;
  undefined8 uStack_e0;
  undefined1 local_d8 [16];
  code *local_c8 [2];
  undefined1 local_b8 [16];
  code *local_a8 [2];
  undefined8 local_98;
  undefined8 uStack_90;
  code *local_88;
  code *local_78;
  code *pcStack_70;
  code *local_68;
  
  plVar13 = _DAT_23ee0b650;
  plVar2 = (longlong *)*param_3;
  plVar3 = (longlong *)param_3[1];
  if (_DAT_23ee0b650 == (longlong *)0x0) {
LAB_23c000303:
    _DAT_23ee0b650 = (longlong *)FUN_23e91f3b0(param_1,_DAT_23ee0b648,DAT_23ee0b670,0x28);
  }
  else {
    lVar16 = *_DAT_23ee0b650;
    if (1 < lVar16) {
      *_DAT_23ee0b650 = lVar16 + -1;
      goto LAB_23c000303;
    }
    if (_DAT_23ee0b650[2] != 0) {
      *_DAT_23ee0b650 = lVar16 + -1;
      if (lVar16 + -1 == 0) {
        (**(code **)(plVar13[1] + 0x30))(plVar13);
      }
      goto LAB_23c000303;
    }
  }
  plVar5 = _DAT_23ee0b650;
  lVar16 = *(longlong *)(param_1 + 0x38);
  plVar13 = _DAT_23ee0b650 + 9;
  lVar21 = *(longlong *)(lVar16 + 8);
  _DAT_23ee0b650[0xf] = lVar21;
  *(longlong **)(lVar16 + 8) = plVar13;
  if ((lVar21 != 0) &&
     (((*(char *)(lVar21 + 0x45) == '\x01' ||
       ((ulonglong)
        (*(longlong *)(lVar21 + 0x20) + 0xb8 +
        (longlong)*(int *)(*(longlong *)(lVar21 + 0x20) + 0xa8) * 2) <=
        *(ulonglong *)(lVar21 + 0x38))) && (plVar5[0xe] != 0)))) {
    plVar13 = *(longlong **)(lVar21 + 0x28);
    *(longlong **)(plVar5[0xe] + 0x10) = plVar13;
    if (plVar13 != (longlong *)0x0) {
      *plVar13 = *plVar13 + 1;
    }
  }
  *plVar5 = *plVar5 + 1;
  *(undefined4 *)(plVar5 + 8) = 0;
  pcVar12 = (code *)FUN_23e8d7f30(param_1,plVar3);
  pcVar27 = _Py_NoneStruct_exref;
  if (pcVar12 != (code *)0x0) {
    local_68 = _Py_NoneStruct_exref;
    pcStack_70 = _DAT_23ee07610;
    local_78 = pcVar12;
    plVar13 = (longlong *)
              (**(code **)(DAT_23ed79760 + *(longlong *)(*(longlong *)(DAT_23ed79760 + 8) + 0x38)))
                        (DAT_23ed79760,&local_78,3,0);
    *plVar13 = *plVar13 + -1;
    if (*plVar13 == 0) {
      (**(code **)(plVar13[1] + 0x30))(plVar13);
    }
    plVar13 = (longlong *)FUN_23e8bc2f0(plVar2,DAT_23ee07598);
    if (plVar13 == (longlong *)0x0) {
      local_d8 = *(undefined1 (*) [16])(param_1 + 0x60);
      local_c8[0] = *(code **)(param_1 + 0x70);
      *(undefined8 *)(param_1 + 0x70) = 0;
      plVar13 = *(longlong **)(param_1 + 0x138);
      *(undefined1 (*) [16])(param_1 + 0x60) = (undefined1  [16])0x0;
      plVar28 = (longlong *)0x0;
      if (plVar13 != (longlong *)0x0) {
        *plVar13 = *plVar13 + 1;
        goto joined_r0x00023c000781;
      }
      if (local_c8[0] != (code *)0x0) goto LAB_23c000787;
LAB_23c000f19:
      plVar13 = (longlong *)0x0;
      plVar28 = (longlong *)0x0;
      uVar29 = 0x41;
      goto LAB_23c0014bd;
    }
    plVar14 = (longlong *)FUN_23e91c870(param_1,plVar13,DAT_23ed6ce88,DAT_23ee075c0);
    *plVar13 = *plVar13 + -1;
    if (*plVar13 == 0) {
      (**(code **)(plVar13[1] + 0x30))(plVar13);
    }
    if (plVar14 == (longlong *)0x0) {
      local_d8 = *(undefined1 (*) [16])(param_1 + 0x60);
      local_c8[0] = *(code **)(param_1 + 0x70);
      *(undefined8 *)(param_1 + 0x70) = 0;
      plVar13 = *(longlong **)(param_1 + 0x138);
      *(undefined1 (*) [16])(param_1 + 0x60) = (undefined1  [16])0x0;
      if (plVar13 == (longlong *)0x0) {
        plVar28 = (longlong *)0x0;
        uVar29 = 0x41;
        if (local_c8[0] == (code *)0x0) goto LAB_23c000f19;
        goto LAB_23c0007e2;
      }
      *plVar13 = *plVar13 + 1;
joined_r0x00023c000781:
      plVar28 = (longlong *)0x0;
      if (local_c8[0] == (code *)0x0) {
LAB_23c001201:
        uVar29 = 0x41;
        goto LAB_23c0014bd;
      }
LAB_23c000787:
      uVar29 = 0x41;
LAB_23c0007e2:
      pcVar24 = local_c8[0];
      pcVar23 = DAT_23ed6a4f8;
      if (DAT_23ed6a4f8 == (code *)0x0) {
        pcVar23 = (code *)FUN_23a33a530(PyTraceBack_Type_exref);
      }
      else {
        pcVar25 = *(code **)DAT_23ed6a4f8;
        *(longlong *)DAT_23ed6a4f8 = 1;
        DAT_23ed6a4f8 = pcVar25;
        DAT_23ed6a4f0 = DAT_23ed6a4f0 + -1;
      }
      pcVar25 = _PyRuntime_exref;
      *(longlong **)(pcVar23 + 0x18) = plVar5;
      *plVar5 = *plVar5 + 1;
      lVar16 = *(longlong *)(pcVar25 + 0x1f8);
      *(undefined4 *)(pcVar23 + 0x20) = 0xffffffff;
      *(undefined4 *)(pcVar23 + 0x24) = uVar29;
      lVar16 = *(longlong *)(*(longlong *)(lVar16 + 0x10) + 0x2e8);
      lVar21 = *(longlong *)(pcVar23 + -8);
      puVar4 = *(undefined8 **)(lVar16 + 8);
      *puVar4 = pcVar23 + -0x10;
      *(longlong *)(pcVar23 + -0x10) = lVar16;
      *(ulonglong *)(pcVar23 + -8) = (ulonglong)((uint)lVar21 & 3) | (ulonglong)puVar4;
      *(code **)(lVar16 + 8) = pcVar23 + -0x10;
      *(code **)(pcVar23 + 0x10) = pcVar24;
      *(longlong *)pcVar24 = *(longlong *)pcVar24 + 1;
      plVar15 = plVar28;
      if (local_c8[0] != (code *)0x0) {
        *(longlong *)local_c8[0] = *(longlong *)local_c8[0] + -1;
        lVar16 = *(longlong *)local_c8[0];
        pcVar24 = local_c8[0];
        goto joined_r0x00023c000878;
      }
      goto LAB_23c00087e;
    }
    plVar13 = (longlong *)FUN_23e8d9880(plVar14,DAT_23ed6cd90);
    if (plVar13 == (longlong *)0x0) {
LAB_23c000eb0:
      pauVar1 = (undefined1 (*) [16])(param_1 + 0x60);
      pcVar24 = *(code **)*pauVar1;
      auVar7 = *pauVar1;
      local_d8 = *pauVar1;
      pcVar23 = *(code **)(param_1 + 0x70);
      *(undefined8 *)(param_1 + 0x70) = 0;
      *(undefined1 (*) [16])(param_1 + 0x60) = (undefined1  [16])0x0;
      *plVar14 = *plVar14 + -1;
      local_c8[0] = pcVar23;
      if (*plVar14 == 0) {
        (**(code **)(plVar14[1] + 0x30))(plVar14);
        plVar13 = *(longlong **)(param_1 + 0x138);
        if (plVar13 != (longlong *)0x0) {
          iVar11 = 0x41;
          plVar28 = (longlong *)0x0;
          local_d8 = auVar7;
LAB_23c001440:
          *plVar13 = *plVar13 + 1;
          local_c8[0] = pcVar23;
          goto LAB_23c001445;
        }
      }
      else {
        plVar13 = *(longlong **)(param_1 + 0x138);
        if (plVar13 != (longlong *)0x0) {
          *plVar13 = *plVar13 + 1;
          if (pcVar23 != (code *)0x0) {
            uVar29 = 0x41;
            plVar28 = (longlong *)0x0;
            goto LAB_23c0007e2;
          }
          plVar28 = (longlong *)0x0;
          uVar29 = 0x41;
          goto LAB_23c0014bd;
        }
      }
      local_d8 = *pauVar1;
      if (pcVar23 == (code *)0x0) goto LAB_23c000f19;
      plVar28 = (longlong *)0x0;
      uVar29 = 0x41;
      goto LAB_23c0007e2;
    }
    *(undefined4 *)(plVar5 + 5) = 0x41;
    plVar15 = (longlong *)FUN_23e91a870(param_1,plVar13);
    *plVar13 = *plVar13 + -1;
    if (*plVar13 == 0) {
      (**(code **)(plVar13[1] + 0x30))(plVar13);
    }
    if (plVar15 == (longlong *)0x0) goto LAB_23c000eb0;
    plVar13 = (longlong *)FUN_23e8d9880(plVar14,DAT_23ed6cd98);
    if (plVar13 == (longlong *)0x0) {
      pcVar23 = *(code **)(param_1 + 0x70);
      pcVar24 = *(code **)(param_1 + 0x60);
      *(undefined8 *)(param_1 + 0x70) = 0;
      iVar11 = 0x41;
      *(undefined1 (*) [16])(param_1 + 0x60) = (undefined1  [16])0x0;
      plVar28 = (longlong *)0x0;
      pcVar25 = *(code **)(param_1 + 0x68);
      pcVar6 = local_78;
      pcVar9 = pcStack_70;
      pcVar10 = local_68;
LAB_23c001679:
      local_68 = pcVar10;
      pcStack_70 = pcVar9;
      local_78 = pcVar6;
      *plVar14 = *plVar14 + -1;
      if (*plVar14 == 0) {
        (**(code **)(plVar14[1] + 0x30))(plVar14);
      }
      *plVar15 = *plVar15 + -1;
      if (*plVar15 == 0) {
        (**(code **)(plVar15[1] + 0x30))(plVar15);
      }
      if ((plVar13 != (longlong *)0x0) && (*plVar13 = *plVar13 + -1, *plVar13 == 0)) {
        (**(code **)(plVar13[1] + 0x30))(plVar13);
      }
      plVar13 = *(longlong **)(param_1 + 0x138);
      local_d8._8_8_ = pcVar25;
      local_d8._0_8_ = pcVar24;
      local_c8[0] = pcVar23;
      if (plVar13 != (longlong *)0x0) goto LAB_23c001440;
LAB_23c001445:
      if (local_c8[0] == (code *)0x0) {
        if (iVar11 == 0) {
          uVar29 = (undefined4)plVar5[5];
          goto LAB_23c0014bd;
        }
        goto LAB_23c001201;
      }
      plVar15 = plVar28;
      if (iVar11 != 0) goto LAB_23c000787;
      goto LAB_23c00088e;
    }
    *plVar15 = *plVar15 + 1;
    lVar16 = FUN_23eb1ba00();
    plVar28 = plVar15;
    if (lVar16 == 0) {
      FUN_23e915740(param_1,&local_98,DAT_23ee075c8);
      local_110 = _PyRuntime_exref;
      pcVar23 = local_88;
LAB_23c001795:
      plVar17 = *(longlong **)(param_1 + 0x138);
      local_b8._8_8_ = uStack_90;
      local_b8._0_8_ = local_98;
      if (plVar17 != (longlong *)0x0) {
        *plVar17 = *plVar17 + 1;
      }
      pcVar24 = DAT_23ed6a4f8;
      local_a8[0] = pcVar23;
      if (pcVar23 == (code *)0x0) {
        if (DAT_23ed6a4f8 == (code *)0x0) {
          pcVar24 = (code *)FUN_23a33a530(PyTraceBack_Type_exref);
        }
        else {
          pcVar23 = *(code **)DAT_23ed6a4f8;
          *(longlong *)DAT_23ed6a4f8 = 1;
          DAT_23ed6a4f8 = pcVar23;
          DAT_23ed6a4f0 = DAT_23ed6a4f0 + -1;
        }
        *(longlong *)(pcVar24 + 0x10) = 0;
        *(longlong **)(pcVar24 + 0x18) = plVar5;
        *plVar5 = *plVar5 + 1;
        *(longlong *)(pcVar24 + 0x20) = 0x42ffffffff;
        lVar16 = *(longlong *)(*(longlong *)(*(longlong *)(local_110 + 0x1f8) + 0x10) + 0x2e8);
        lVar21 = *(longlong *)(pcVar24 + -8);
        puVar4 = *(undefined8 **)(lVar16 + 8);
        *puVar4 = pcVar24 + -0x10;
        *(longlong *)(pcVar24 + -0x10) = lVar16;
        *(ulonglong *)(pcVar24 + -8) = (ulonglong)((uint)lVar21 & 3) | (ulonglong)puVar4;
        *(code **)(lVar16 + 8) = pcVar24 + -0x10;
        if ((local_a8[0] != (code *)0x0) &&
           (*(longlong *)local_a8[0] = *(longlong *)local_a8[0] + -1, *(longlong *)local_a8[0] == 0)
           ) {
          (**(code **)(*(longlong *)(local_a8[0] + 8) + 0x30))(local_a8[0]);
        }
      }
      else {
        if (DAT_23ed6a4f8 == (code *)0x0) {
          pcVar24 = (code *)FUN_23a33a530(PyTraceBack_Type_exref);
        }
        else {
          pcVar25 = *(code **)DAT_23ed6a4f8;
          *(longlong *)DAT_23ed6a4f8 = 1;
          DAT_23ed6a4f8 = pcVar25;
          DAT_23ed6a4f0 = DAT_23ed6a4f0 + -1;
        }
        *(longlong **)(pcVar24 + 0x18) = plVar5;
        *plVar5 = *plVar5 + 1;
        *(longlong *)(pcVar24 + 0x20) = 0x42ffffffff;
        lVar16 = *(longlong *)(*(longlong *)(*(longlong *)(local_110 + 0x1f8) + 0x10) + 0x2e8);
        lVar21 = *(longlong *)(pcVar24 + -8);
        puVar4 = *(undefined8 **)(lVar16 + 8);
        *puVar4 = pcVar24 + -0x10;
        *(longlong *)(pcVar24 + -0x10) = lVar16;
        *(ulonglong *)(pcVar24 + -8) = (ulonglong)((uint)lVar21 & 3) | (ulonglong)puVar4;
        *(code **)(lVar16 + 8) = pcVar24 + -0x10;
        *(code **)(pcVar24 + 0x10) = pcVar23;
        *(longlong *)pcVar23 = *(longlong *)pcVar23 + 1;
        if ((local_a8[0] != (code *)0x0) &&
           (*(longlong *)local_a8[0] = *(longlong *)local_a8[0] + -1, *(longlong *)local_a8[0] == 0)
           ) {
          (**(code **)(*(longlong *)(local_a8[0] + 8) + 0x30))();
        }
      }
      local_a8[0] = pcVar24;
      if (((code *)local_b8._0_8_ != pcVar27) && ((code *)local_b8._0_8_ != (code *)0x0)) {
        FUN_23e91b1b0(param_1,local_b8,local_b8 + 8,local_a8);
      }
      plVar20 = *(longlong **)(local_b8._8_8_ + 0x28);
      if (local_a8[0] == pcVar27) {
        pcVar23 = (code *)0x0;
      }
      else {
        pcVar23 = local_a8[0];
        if (local_a8[0] != (code *)0x0) {
          *(longlong *)local_a8[0] = *(longlong *)local_a8[0] + 1;
        }
      }
      *(code **)(local_b8._8_8_ + 0x28) = pcVar23;
      if ((plVar20 != (longlong *)0x0) && (*plVar20 = *plVar20 + -1, *plVar20 == 0)) {
        (**(code **)(plVar20[1] + 0x30))();
      }
      plVar20 = *(longlong **)(param_1 + 0x138);
      *(undefined8 *)(param_1 + 0x138) = local_b8._8_8_;
      if ((plVar20 != (longlong *)0x0) && (*plVar20 = *plVar20 + -1, *plVar20 == 0)) {
        (**(code **)(plVar20[1] + 0x30))();
      }
      *(longlong *)local_b8._0_8_ = *(longlong *)local_b8._0_8_ + -1;
      if (*(longlong *)local_b8._0_8_ == 0) {
        (**(code **)(*(longlong *)(local_b8._0_8_ + 8) + 0x30))();
      }
      if ((local_a8[0] != (code *)0x0) &&
         (*(longlong *)local_a8[0] = *(longlong *)local_a8[0] + -1, *(longlong *)local_a8[0] == 0))
      {
        (**(code **)(*(longlong *)(local_a8[0] + 8) + 0x30))();
      }
      local_a8[0] = (code *)0x0;
      local_b8 = (undefined1  [16])0x0;
      iVar11 = FUN_23a35ebd0(param_1,*(undefined8 *)(*(longlong *)(param_1 + 0x138) + 8),
                             *(undefined8 *)PyExc_BaseException_exref);
      if (iVar11 == 0) {
        pcVar26 = *(code **)(param_1 + 0x138);
        if ((pcVar26 != pcVar27) && (pcVar26 != (code *)0x0)) {
          pcVar24 = *(code **)(pcVar26 + 8);
          pcVar23 = *(code **)(pcVar26 + 0x28);
          *(longlong *)pcVar26 = *(longlong *)pcVar26 + 1;
          *(longlong *)pcVar24 = *(longlong *)pcVar24 + 1;
          if ((pcVar23 != (code *)0x0) &&
             (*(longlong *)pcVar23 = *(longlong *)pcVar23 + 1,
             plVar5 == *(longlong **)(pcVar23 + 0x18))) {
            *(undefined4 *)(plVar5 + 5) = *(undefined4 *)(pcVar23 + 0x24);
          }
          *(longlong **)(param_1 + 0x138) = plVar17;
          bVar8 = true;
          iVar11 = 0;
          pcVar25 = pcVar26;
          goto LAB_23c001a40;
        }
        pcVar24 = *(code **)PyExc_RuntimeError_exref;
        pcVar25 = (code *)PyUnicode_FromString("No active exception to reraise");
        pcVar26 = *(code **)(param_1 + 0x138);
        *(longlong *)pcVar24 = *(longlong *)pcVar24 + 1;
        *(longlong **)(param_1 + 0x138) = plVar17;
        if (pcVar26 != (code *)0x0) {
          pcVar23 = (code *)0x0;
          iVar11 = 0x41;
          bVar8 = true;
          goto LAB_23c001a40;
        }
        iVar11 = 0x41;
        local_68 = (code *)0x0;
        local_78 = pcVar24;
        pcStack_70 = pcVar25;
      }
      else {
        pcStack_70 = *(code **)(param_1 + 0x138);
        local_78 = *(code **)(pcStack_70 + 8);
        local_68 = *(code **)(pcStack_70 + 0x28);
        *(undefined4 *)(plVar5 + 5) = 0x41;
        if (local_68 == (code *)0x0) {
          local_68 = pcVar27;
        }
        plVar20 = (longlong *)FUN_23e956150(param_1,plVar13);
        if (plVar20 == (longlong *)0x0) {
          pcVar23 = *(code **)(param_1 + 0x70);
          pcVar24 = *(code **)(param_1 + 0x60);
          pcVar25 = *(code **)(param_1 + 0x68);
          *(undefined1 (*) [16])(param_1 + 0x60) = (undefined1  [16])0x0;
        }
        else {
          iVar11 = FUN_23a35f020(plVar20);
          *plVar20 = *plVar20 + -1;
          if (*plVar20 == 0) {
            (**(code **)(plVar20[1] + 0x30))(plVar20);
          }
          if (iVar11 != -1) {
            if (iVar11 == 0) {
              pcVar26 = *(code **)(param_1 + 0x138);
              bVar8 = false;
              if ((pcVar26 == pcVar27) || (pcVar26 == (code *)0x0)) {
                pcVar24 = *(code **)PyExc_RuntimeError_exref;
                pcVar25 = (code *)PyUnicode_FromString("No active exception to reraise");
                pcVar26 = *(code **)(param_1 + 0x138);
                *(longlong *)pcVar24 = *(longlong *)pcVar24 + 1;
                *(longlong **)(param_1 + 0x138) = plVar17;
                if (pcVar26 == (code *)0x0) {
                  iVar11 = 0x41;
                  local_68 = (code *)0x0;
                  pcVar23 = local_68;
                  pcVar6 = pcVar24;
                  pcVar9 = pcVar25;
                  pcVar10 = local_68;
                  goto LAB_23c001679;
                }
                pcVar23 = (code *)0x0;
                iVar11 = 0x41;
              }
              else {
                pcVar24 = *(code **)(pcVar26 + 8);
                pcVar23 = *(code **)(pcVar26 + 0x28);
                *(longlong *)pcVar26 = *(longlong *)pcVar26 + 1;
                *(longlong *)pcVar24 = *(longlong *)pcVar24 + 1;
                pcVar25 = pcVar26;
                if ((pcVar23 == (code *)0x0) ||
                   (*(longlong *)pcVar23 = *(longlong *)pcVar23 + 1,
                   plVar5 != *(longlong **)(pcVar23 + 0x18))) {
                  *(longlong **)(param_1 + 0x138) = plVar17;
                  iVar11 = 0;
                }
                else {
                  iVar11 = 0;
                  *(undefined4 *)(plVar5 + 5) = *(undefined4 *)(pcVar23 + 0x24);
                  *(longlong **)(param_1 + 0x138) = plVar17;
                }
              }
              goto LAB_23c001a40;
            }
            plVar20 = *(longlong **)(param_1 + 0x138);
            *(longlong **)(param_1 + 0x138) = plVar17;
            if (plVar20 != (longlong *)0x0) goto LAB_23c00064d;
            goto LAB_23c00065a;
          }
          pcVar24 = *(code **)(param_1 + 0x60);
          pcVar25 = *(code **)(param_1 + 0x68);
          pcVar23 = *(code **)(param_1 + 0x70);
          *(undefined1 (*) [16])(param_1 + 0x60) = (undefined1  [16])0x0;
        }
        pcVar26 = *(code **)(param_1 + 0x138);
        *(undefined8 *)(param_1 + 0x70) = 0;
        iVar11 = 0x41;
        bVar8 = false;
        *(longlong **)(param_1 + 0x138) = plVar17;
        pcVar6 = pcVar24;
        pcVar9 = pcVar25;
        pcVar10 = pcVar23;
        if (pcVar26 == (code *)0x0) goto LAB_23c001679;
LAB_23c001a40:
        *(longlong *)pcVar26 = *(longlong *)pcVar26 + -1;
        if (*(longlong *)pcVar26 == 0) {
          (**(code **)(*(longlong *)(pcVar26 + 8) + 0x30))();
        }
        local_78 = pcVar24;
        pcVar6 = pcVar24;
        pcStack_70 = pcVar25;
        pcVar9 = pcVar25;
        local_68 = pcVar23;
        pcVar10 = pcVar23;
        if (!bVar8) goto LAB_23c001679;
      }
      *(undefined4 *)(plVar5 + 5) = 0x41;
      plVar17 = (longlong *)FUN_23e957a30(param_1,plVar13,DAT_23ee075f8);
      if (plVar17 == (longlong *)0x0) {
        pcVar23 = *(code **)(param_1 + 0x70);
        *(undefined8 *)(param_1 + 0x70) = 0;
        pcVar24 = *(code **)(param_1 + 0x60);
        pcVar25 = *(code **)(param_1 + 0x68);
        iVar11 = 0x41;
        *(undefined1 (*) [16])(param_1 + 0x60) = (undefined1  [16])0x0;
        FUN_23a35d6b0(&local_78);
        pcVar6 = local_78;
        pcVar9 = pcStack_70;
        pcVar10 = local_68;
      }
      else {
        *plVar17 = *plVar17 + -1;
        pcVar23 = local_68;
        pcVar24 = local_78;
        pcVar25 = pcStack_70;
        pcVar6 = local_78;
        pcVar9 = pcStack_70;
        pcVar10 = local_68;
        if (*plVar17 == 0) {
          (**(code **)(plVar17[1] + 0x30))(plVar17);
          pcVar23 = local_68;
          pcVar24 = local_78;
          pcVar25 = pcStack_70;
          pcVar6 = local_78;
          pcVar9 = pcStack_70;
          pcVar10 = local_68;
        }
      }
      goto LAB_23c001679;
    }
    plVar17 = (longlong *)FUN_23e8bc2f0(lVar16,_DAT_23ee07618);
    local_110 = _PyRuntime_exref;
    if (plVar17 == (longlong *)0x0) {
      pcVar23 = *(code **)(param_1 + 0x70);
      *(undefined8 *)(param_1 + 0x70) = 0;
      local_98 = *(undefined8 *)(param_1 + 0x60);
      uStack_90 = *(undefined8 *)(param_1 + 0x68);
      *(undefined1 (*) [16])(param_1 + 0x60) = (undefined1  [16])0x0;
      goto LAB_23c001795;
    }
    lVar16 = *(longlong *)(param_1 + 0x10);
    plVar20 = *(longlong **)(lVar16 + 0xe20);
    if (plVar20 == (longlong *)0x0) {
      plVar20 = (longlong *)FUN_23e916a20(PyTuple_Type_exref,2);
    }
    else {
      lVar21 = plVar20[3];
      *(int *)(lVar16 + 0xebc) = *(int *)(lVar16 + 0xebc) + -1;
      *(longlong *)(lVar16 + 0xe20) = lVar21;
      *plVar20 = 1;
    }
    local_110 = _PyRuntime_exref;
    lVar16 = *(longlong *)(*(longlong *)(*(longlong *)(_PyRuntime_exref + 0x1f8) + 0x10) + 0x2e8);
    lVar21 = plVar20[-1];
    puVar4 = *(undefined8 **)(lVar16 + 8);
    *puVar4 = plVar20 + -2;
    plVar20[-2] = lVar16;
    plVar20[-1] = (ulonglong)((uint)lVar21 & 3) | (ulonglong)puVar4;
    *(longlong **)(lVar16 + 8) = plVar20 + -2;
    uVar22 = _DAT_23ee07620;
    *(longlong *)pcVar12 = *(longlong *)pcVar12 + 1;
    plVar20[3] = (longlong)pcVar12;
    *plVar15 = *plVar15 + 1;
    plVar20[4] = (longlong)plVar15;
    plVar18 = (longlong *)FUN_23e8d7870(param_1,uVar22);
    *(undefined4 *)(plVar5 + 5) = 0x42;
    plVar19 = (longlong *)FUN_23a334c60(param_1,plVar17,plVar20,plVar18);
    *plVar17 = *plVar17 + -1;
    if (*plVar17 == 0) {
      (**(code **)(plVar17[1] + 0x30))(plVar17);
    }
    *plVar20 = *plVar20 + -1;
    if (*plVar20 == 0) {
      (**(code **)(plVar20[1] + 0x30))(plVar20);
    }
    *plVar18 = *plVar18 + -1;
    if (*plVar18 == 0) {
      (**(code **)(plVar18[1] + 0x30))(plVar18);
    }
    if (plVar19 == (longlong *)0x0) {
      local_98 = *(undefined8 *)(param_1 + 0x60);
      uStack_90 = *(undefined8 *)(param_1 + 0x68);
      pcVar23 = *(code **)(param_1 + 0x70);
      *(undefined8 *)(param_1 + 0x70) = 0;
      *(undefined1 (*) [16])(param_1 + 0x60) = (undefined1  [16])0x0;
      goto LAB_23c001795;
    }
    *plVar19 = *plVar19 + -1;
    if (*plVar19 == 0) {
      (**(code **)(plVar19[1] + 0x30))(plVar19);
    }
    *(undefined4 *)(plVar5 + 5) = 0x41;
    plVar20 = (longlong *)FUN_23e957a30(param_1,plVar13,DAT_23ee075f8);
    if (plVar20 == (longlong *)0x0) {
      pcVar24 = *(code **)(param_1 + 0x60);
      pcVar23 = *(code **)(param_1 + 0x70);
      *(undefined8 *)(param_1 + 0x70) = 0;
      iVar11 = 0x41;
      *(undefined1 (*) [16])(param_1 + 0x60) = (undefined1  [16])0x0;
      pcVar25 = *(code **)(param_1 + 0x68);
      pcVar6 = local_78;
      pcVar9 = pcStack_70;
      pcVar10 = local_68;
      goto LAB_23c001679;
    }
LAB_23c00064d:
    *plVar20 = *plVar20 + -1;
    if (*plVar20 == 0) {
      (**(code **)(plVar20[1] + 0x30))();
    }
LAB_23c00065a:
    lVar16 = *(longlong *)(*(longlong *)(param_1 + 0x38) + 8);
    plVar5 = *(longlong **)(lVar16 + 0x28);
    plVar28 = (longlong *)plVar5[2];
    *(undefined8 *)(*(longlong *)(param_1 + 0x38) + 8) = *(undefined8 *)(lVar16 + 0x30);
    *(undefined4 *)(plVar5 + 8) = 0xffffffff;
    if (plVar28 != (longlong *)0x0) {
      plVar5[2] = 0;
      *plVar28 = *plVar28 + -1;
      if (*plVar28 == 0) {
        (**(code **)(plVar28[1] + 0x30))();
      }
    }
    *plVar5 = *plVar5 + -1;
    if (*plVar5 == 0) {
      (**(code **)(plVar5[1] + 0x30))(plVar5);
    }
    plVar5[0xf] = 0;
    *plVar14 = *plVar14 + -1;
    if (*plVar14 == 0) {
      (**(code **)(plVar14[1] + 0x30))(plVar14);
    }
    *plVar15 = *plVar15 + -1;
    if (*plVar15 == 0) {
      (**(code **)(plVar15[1] + 0x30))(plVar15);
    }
    *plVar13 = *plVar13 + -1;
    if (*plVar13 == 0) {
      (**(code **)(plVar13[1] + 0x30))(plVar13);
    }
    pcVar27 = _Py_TrueStruct_exref;
    *(longlong *)_Py_TrueStruct_exref = *(longlong *)_Py_TrueStruct_exref + 1;
    lVar16 = *(longlong *)pcVar12;
    *(longlong *)pcVar12 = lVar16 + -1;
    if (lVar16 + -1 == 0) {
      (**(code **)(*(longlong *)(pcVar12 + 8) + 0x30))(pcVar12);
    }
LAB_23c000d68:
    *plVar15 = *plVar15 + -1;
    if (*plVar15 == 0) {
      (**(code **)(plVar15[1] + 0x30))(plVar15);
    }
LAB_23c000d78:
    lVar16 = *plVar2;
    *plVar2 = lVar16 + -1;
    if (lVar16 + -1 == 0) {
      (**(code **)(plVar2[1] + 0x30))(plVar2);
    }
    lVar16 = *plVar3;
    *plVar3 = lVar16 + -1;
    if (lVar16 + -1 == 0) {
      (**(code **)(plVar3[1] + 0x30))(plVar3);
      return pcVar27;
    }
    return pcVar27;
  }
  local_d8 = *(undefined1 (*) [16])(param_1 + 0x60);
  local_c8[0] = *(code **)(param_1 + 0x70);
  *(undefined8 *)(param_1 + 0x70) = 0;
  plVar13 = *(longlong **)(param_1 + 0x138);
  *(undefined1 (*) [16])(param_1 + 0x60) = (undefined1  [16])0x0;
  if (plVar13 != (longlong *)0x0) {
    *plVar13 = *plVar13 + 1;
  }
  plVar28 = (longlong *)0x0;
  pcVar27 = _Py_NoneStruct_exref;
  if (local_c8[0] != (code *)0x0) {
    uVar29 = 0x3f;
    goto LAB_23c0007e2;
  }
  uVar29 = 0x3f;
LAB_23c0014bd:
  pcVar23 = DAT_23ed6a4f8;
  if (DAT_23ed6a4f8 == (code *)0x0) {
    pcVar23 = (code *)FUN_23a33a530(PyTraceBack_Type_exref);
    pcVar24 = local_c8[0];
  }
  else {
    pcVar24 = *(code **)DAT_23ed6a4f8;
    *(longlong *)DAT_23ed6a4f8 = 1;
    DAT_23ed6a4f8 = pcVar24;
    DAT_23ed6a4f0 = DAT_23ed6a4f0 + -1;
    pcVar24 = (code *)0x0;
  }
  pcVar25 = _PyRuntime_exref;
  *(longlong *)(pcVar23 + 0x10) = 0;
  *(longlong **)(pcVar23 + 0x18) = plVar5;
  *plVar5 = *plVar5 + 1;
  lVar16 = *(longlong *)(pcVar25 + 0x1f8);
  *(undefined4 *)(pcVar23 + 0x20) = 0xffffffff;
  lVar16 = *(longlong *)(lVar16 + 0x10);
  *(undefined4 *)(pcVar23 + 0x24) = uVar29;
  lVar16 = *(longlong *)(lVar16 + 0x2e8);
  lVar21 = *(longlong *)(pcVar23 + -8);
  puVar4 = *(undefined8 **)(lVar16 + 8);
  *puVar4 = pcVar23 + -0x10;
  *(longlong *)(pcVar23 + -0x10) = lVar16;
  *(ulonglong *)(pcVar23 + -8) = (ulonglong)((uint)lVar21 & 3) | (ulonglong)puVar4;
  *(code **)(lVar16 + 8) = pcVar23 + -0x10;
  plVar15 = plVar28;
  if (pcVar24 != (code *)0x0) {
    *(longlong *)pcVar24 = *(longlong *)pcVar24 + -1;
    lVar16 = *(longlong *)pcVar24;
joined_r0x00023c000878:
    plVar15 = plVar28;
    if (lVar16 == 0) {
      (**(code **)(*(longlong *)(pcVar24 + 8) + 0x30))();
    }
  }
LAB_23c00087e:
  pcVar24 = (code *)local_d8._0_8_;
  local_c8[0] = pcVar23;
LAB_23c00088e:
  if ((pcVar24 != (code *)0x0) && (pcVar24 != pcVar27)) {
    FUN_23e91b1b0(param_1,local_d8,local_d8 + 8,local_c8);
  }
  plVar28 = *(longlong **)(local_d8._8_8_ + 0x28);
  if (local_c8[0] == pcVar27) {
    pcVar23 = (code *)0x0;
  }
  else {
    pcVar23 = local_c8[0];
    if (local_c8[0] != (code *)0x0) {
      *(longlong *)local_c8[0] = *(longlong *)local_c8[0] + 1;
    }
  }
  *(code **)(local_d8._8_8_ + 0x28) = pcVar23;
  if ((plVar28 != (longlong *)0x0) && (*plVar28 = *plVar28 + -1, *plVar28 == 0)) {
    (**(code **)(plVar28[1] + 0x30))();
  }
  plVar28 = *(longlong **)(param_1 + 0x138);
  *(undefined8 *)(param_1 + 0x138) = local_d8._8_8_;
  if ((plVar28 != (longlong *)0x0) && (*plVar28 = *plVar28 + -1, *plVar28 == 0)) {
    (**(code **)(plVar28[1] + 0x30))();
  }
  *(longlong *)local_d8._0_8_ = *(longlong *)local_d8._0_8_ + -1;
  if (*(longlong *)local_d8._0_8_ == 0) {
    (**(code **)(*(longlong *)(local_d8._0_8_ + 8) + 0x30))();
  }
  if ((local_c8[0] != (code *)0x0) &&
     (*(longlong *)local_c8[0] = *(longlong *)local_c8[0] + -1, *(longlong *)local_c8[0] == 0)) {
    (**(code **)(*(longlong *)(local_c8[0] + 8) + 0x30))();
  }
  pcVar25 = *(code **)(param_1 + 0x138);
  local_c8[0] = (code *)0x0;
  local_d8 = (undefined1  [16])0x0;
  pcVar23 = *(code **)PyExc_Exception_exref;
  pcVar24 = *(code **)(pcVar25 + 8);
  if ((*(uint *)(*(longlong *)(pcVar23 + 8) + 0xa8) & 0x4000000) == 0) {
    if (((int)*(uint *)(*(longlong *)(pcVar23 + 8) + 0xa8) < 0) &&
       (((byte)pcVar23[0xab] & 0x40) != 0)) {
      pcVar6 = *(code **)(pcVar24 + 8);
      if ((*(uint *)(pcVar6 + 0xa8) & 0x40000000) == 0) {
        if ((-1 < (int)*(uint *)(pcVar6 + 0xa8)) || (((byte)pcVar24[0xab] & 0x40) == 0))
        goto LAB_23c001589;
      }
      else {
        pcVar24 = pcVar6;
        if (-1 < *(int *)(*(longlong *)(pcVar6 + 8) + 0xa8)) {
LAB_23c001589:
          if (pcVar24 != pcVar23) goto LAB_23c000a0d;
          goto LAB_23c000b65;
        }
      }
      lVar16 = *(longlong *)(pcVar24 + 0x158);
      if (lVar16 == 0) {
        do {
          if (pcVar23 == pcVar24) goto LAB_23c000b65;
          pcVar24 = *(code **)(pcVar24 + 0x100);
        } while (pcVar24 != (code *)0x0);
        if (pcVar23 == PyBaseObject_Type_exref) goto LAB_23c000b65;
      }
      else if (0 < *(longlong *)(lVar16 + 0x10)) {
        lVar21 = 0;
        do {
          if (pcVar23 == *(code **)(lVar16 + 0x18 + lVar21 * 8)) goto LAB_23c000b65;
          lVar21 = lVar21 + 1;
        } while (*(longlong *)(lVar16 + 0x10) != lVar21);
      }
      goto LAB_23c000a0d;
    }
    plVar28 = *(longlong **)PyExc_TypeError_exref;
    uVar22 = PyUnicode_FromString
                       ("catching classes that do not inherit from BaseException is not allowed");
    plVar14 = *(longlong **)(param_1 + 0x60);
    plVar17 = *(longlong **)(param_1 + 0x68);
    plVar20 = *(longlong **)(param_1 + 0x70);
    *(longlong **)(param_1 + 0x60) = plVar28;
    *plVar28 = *plVar28 + 1;
    *(undefined8 *)(param_1 + 0x68) = uVar22;
    *(undefined8 *)(param_1 + 0x70) = 0;
    if ((plVar14 != (longlong *)0x0) && (*plVar14 = *plVar14 + -1, *plVar14 == 0)) {
      (**(code **)(plVar14[1] + 0x30))();
    }
    if ((plVar17 != (longlong *)0x0) && (*plVar17 = *plVar17 + -1, *plVar17 == 0)) {
      (**(code **)(plVar17[1] + 0x30))(plVar17);
    }
    if ((plVar20 == (longlong *)0x0) || (*plVar20 = *plVar20 + -1, *plVar20 != 0)) {
LAB_23c000b5e:
      pcVar25 = *(code **)(param_1 + 0x138);
    }
    else {
      (**(code **)(plVar20[1] + 0x30))(plVar20);
      pcVar25 = *(code **)(param_1 + 0x138);
    }
LAB_23c000b65:
    plVar28 = &DAT_23ed6cce0;
    *(longlong *)pcVar25 = *(longlong *)pcVar25 + 1;
    local_108 = (code *)FUN_23a3a0d40(DAT_23ed6cf28);
    plVar17 = _DAT_23ee07628;
    lVar16 = *(longlong *)(param_1 + 0x10);
    plVar14 = *(longlong **)(lVar16 + 0xe20);
    if (plVar14 == (longlong *)0x0) {
      plVar14 = (longlong *)FUN_23e916a20(PyTuple_Type_exref,2);
    }
    else {
      lVar21 = plVar14[3];
      *(int *)(lVar16 + 0xebc) = *(int *)(lVar16 + 0xebc) + -1;
      *(longlong *)(lVar16 + 0xe20) = lVar21;
      *plVar14 = 1;
    }
    local_110 = _PyRuntime_exref;
    plVar14[4] = 0;
    lVar16 = *(longlong *)(*(longlong *)(*(longlong *)(local_110 + 0x1f8) + 0x10) + 0x2e8);
    lVar21 = plVar14[-1];
    puVar4 = *(undefined8 **)(lVar16 + 8);
    *puVar4 = plVar14 + -2;
    plVar14[-2] = lVar16;
    plVar14[-1] = (ulonglong)((uint)lVar21 & 3) | (ulonglong)puVar4;
    *(longlong **)(lVar16 + 8) = plVar14 + -2;
    *plVar17 = *plVar17 + 1;
    plVar14[3] = (longlong)plVar17;
    uVar22 = DAT_23ed6cd28;
    if (DAT_23ed6a4c0 == (longlong *)0x0) {
      plVar17 = (longlong *)PyDict_GetItemString(DAT_23ed6ccc0,"format");
      if (plVar17 != (longlong *)0x0) {
        *plVar17 = *plVar17 + 1;
        DAT_23ed6a4c0 = plVar17;
        goto LAB_23c000c2f;
      }
      PyErr_PrintEx(0);
      iVar11 = (int)plVar17;
      Py_Exit(1);
LAB_23c001cb1:
      if (iVar11 == 0) goto LAB_23c000f42;
      goto LAB_23c000f4a;
    }
LAB_23c000c2f:
    uStack_e0 = uVar22;
    local_e8 = pcVar25;
    lVar16 = FUN_23e94ed00(param_1,DAT_23ed6a4c0,&local_e8);
    if (lVar16 == 0) {
      local_108 = *(code **)(param_1 + 0x68);
      plVar28 = *(longlong **)(param_1 + 0x60);
      pcVar27 = *(code **)(param_1 + 0x70);
      *(undefined1 (*) [16])(param_1 + 0x60) = (undefined1  [16])0x0;
      *(undefined8 *)(param_1 + 0x70) = 0;
      *plVar14 = *plVar14 + -1;
      if (*plVar14 == 0) {
        (**(code **)(plVar14[1] + 0x30))(plVar14);
      }
    }
    else {
      plVar14[4] = lVar16;
      plVar28 = (longlong *)PyUnicode_Join(DAT_23ed6cd28,plVar14);
      *plVar14 = *plVar14 + -1;
      if (*plVar14 == 0) {
        (**(code **)(plVar14[1] + 0x30))(plVar14);
      }
      if (plVar28 != (longlong *)0x0) {
        *(undefined4 *)(plVar5 + 5) = 0x45;
        plVar14 = (longlong *)FUN_23e914090(param_1,local_108,plVar28);
        *plVar28 = *plVar28 + -1;
        if (*plVar28 == 0) {
          (**(code **)(plVar28[1] + 0x30))(plVar28);
        }
        if (plVar14 != (longlong *)0x0) {
          *plVar14 = *plVar14 + -1;
          if (*plVar14 == 0) {
            (**(code **)(plVar14[1] + 0x30))(plVar14);
          }
          pcVar27 = _Py_FalseStruct_exref;
          *(longlong *)_Py_FalseStruct_exref = *(longlong *)_Py_FalseStruct_exref + 1;
          *(longlong *)pcVar25 = *(longlong *)pcVar25 + -1;
          if (*(longlong *)pcVar25 == 0) {
            (**(code **)(*(longlong *)(pcVar25 + 8) + 0x30))(pcVar25);
          }
          plVar5 = *(longlong **)(param_1 + 0x138);
          *(longlong **)(param_1 + 0x138) = plVar13;
          if ((plVar5 != (longlong *)0x0) && (*plVar5 = *plVar5 + -1, *plVar5 == 0)) {
            (**(code **)(plVar5[1] + 0x30))();
          }
          lVar16 = *(longlong *)(*(longlong *)(param_1 + 0x38) + 8);
          plVar13 = *(longlong **)(lVar16 + 0x28);
          plVar5 = (longlong *)plVar13[2];
          *(undefined8 *)(*(longlong *)(param_1 + 0x38) + 8) = *(undefined8 *)(lVar16 + 0x30);
          *(undefined4 *)(plVar13 + 8) = 0xffffffff;
          if (plVar5 != (longlong *)0x0) {
            plVar13[2] = 0;
            *plVar5 = *plVar5 + -1;
            if (*plVar5 == 0) {
              (**(code **)(plVar5[1] + 0x30))();
            }
          }
          *plVar13 = *plVar13 + -1;
          if (*plVar13 == 0) {
            (**(code **)(plVar13[1] + 0x30))(plVar13);
          }
          plVar13[0xf] = 0;
          if ((pcVar12 != (code *)0x0) &&
             (lVar16 = *(longlong *)pcVar12, *(longlong *)pcVar12 = lVar16 + -1, lVar16 + -1 == 0))
          {
            (**(code **)(*(longlong *)(pcVar12 + 8) + 0x30))(pcVar12);
          }
          if (plVar15 == (longlong *)0x0) goto LAB_23c000d78;
          goto LAB_23c000d68;
        }
      }
      local_108 = *(code **)(param_1 + 0x68);
      plVar28 = *(longlong **)(param_1 + 0x60);
      pcVar27 = *(code **)(param_1 + 0x70);
      *(undefined1 (*) [16])(param_1 + 0x60) = (undefined1  [16])0x0;
      *(undefined8 *)(param_1 + 0x70) = 0;
    }
    *(longlong *)pcVar25 = *(longlong *)pcVar25 + -1;
    if (*(longlong *)pcVar25 == 0) {
      (**(code **)(*(longlong *)(pcVar25 + 8) + 0x30))(pcVar25);
    }
    pcVar25 = *(code **)(param_1 + 0x138);
    *(longlong **)(param_1 + 0x138) = plVar13;
    if (pcVar25 != (code *)0x0) {
      *(longlong *)pcVar25 = *(longlong *)pcVar25 + -1;
      if (*(longlong *)pcVar25 != 0) {
        if (pcVar27 == (code *)0x0) goto LAB_23c001c18;
        plVar13 = *(longlong **)(pcVar27 + 0x18);
        goto joined_r0x00023c0011a1;
      }
      iVar11 = 0x45;
      goto LAB_23c001275;
    }
    if (pcVar27 == (code *)0x0) {
LAB_23c001c18:
      iVar11 = 0x45;
      goto LAB_23c000f56;
    }
    plVar13 = *(longlong **)(pcVar27 + 0x18);
joined_r0x00023c0011a1:
    pcVar23 = pcVar27;
    if (plVar5 == plVar13) goto LAB_23c000fe0;
    iVar11 = 0x45;
LAB_23c0012b4:
    pcVar23 = DAT_23ed6a4f8;
    if (DAT_23ed6a4f8 == (code *)0x0) {
      pcVar23 = (code *)FUN_23a33a530(PyTraceBack_Type_exref);
    }
    else {
      pcVar24 = *(code **)DAT_23ed6a4f8;
      *(longlong *)DAT_23ed6a4f8 = 1;
      DAT_23ed6a4f8 = pcVar24;
      DAT_23ed6a4f0 = DAT_23ed6a4f0 + -1;
    }
    *(longlong **)(pcVar23 + 0x18) = plVar5;
    *plVar5 = *plVar5 + 1;
    lVar16 = *(longlong *)(local_110 + 0x1f8);
    *(int *)(pcVar23 + 0x24) = iVar11;
    *(undefined4 *)(pcVar23 + 0x20) = 0xffffffff;
    lVar16 = *(longlong *)(*(longlong *)(lVar16 + 0x10) + 0x2e8);
    lVar21 = *(longlong *)(pcVar23 + -8);
    puVar4 = *(undefined8 **)(lVar16 + 8);
    *puVar4 = pcVar23 + -0x10;
    *(longlong *)(pcVar23 + -0x10) = lVar16;
    *(ulonglong *)(pcVar23 + -8) = (ulonglong)((uint)lVar21 & 3) | (ulonglong)puVar4;
    lVar21 = *(longlong *)pcVar27;
    *(code **)(lVar16 + 8) = pcVar23 + -0x10;
    *(code **)(pcVar23 + 0x10) = pcVar27;
    if (lVar21 == 0) {
      (**(code **)(*(longlong *)(pcVar27 + 8) + 0x30))(pcVar27);
    }
  }
  else {
    lVar16 = *(longlong *)(pcVar23 + 0x10);
    if (0 < lVar16) {
      lVar21 = 0;
      do {
        if ((-1 < *(int *)(*(longlong *)(*(longlong *)(pcVar23 + lVar21 * 8 + 0x18) + 8) + 0xa8)) ||
           ((*(byte *)(*(longlong *)(pcVar23 + lVar21 * 8 + 0x18) + 0xab) & 0x40) == 0)) {
          plVar28 = *(longlong **)PyExc_TypeError_exref;
          uVar22 = PyUnicode_FromString
                             (
                             "catching classes that do not inherit from BaseException is not allowed"
                             );
          plVar14 = *(longlong **)(param_1 + 0x60);
          plVar17 = *(longlong **)(param_1 + 0x68);
          plVar20 = *(longlong **)(param_1 + 0x70);
          *(longlong **)(param_1 + 0x60) = plVar28;
          *plVar28 = *plVar28 + 1;
          *(undefined8 *)(param_1 + 0x68) = uVar22;
          *(undefined8 *)(param_1 + 0x70) = 0;
          if ((plVar14 != (longlong *)0x0) && (*plVar14 = *plVar14 + -1, *plVar14 == 0)) {
            (**(code **)(plVar14[1] + 0x30))();
          }
          if ((plVar17 != (longlong *)0x0) && (*plVar17 = *plVar17 + -1, *plVar17 == 0)) {
            (**(code **)(plVar17[1] + 0x30))(plVar17);
          }
          if ((plVar20 == (longlong *)0x0) || (*plVar20 = *plVar20 + -1, *plVar20 != 0))
          goto LAB_23c000b5e;
          (**(code **)(plVar20[1] + 0x30))(plVar20);
          pcVar25 = *(code **)(param_1 + 0x138);
          goto LAB_23c000b65;
        }
        lVar21 = lVar21 + 1;
      } while (lVar16 != lVar21);
      lVar21 = 0;
      do {
        iVar11 = FUN_23a35ebd0(param_1,pcVar24,*(undefined8 *)(pcVar23 + lVar21 * 8 + 0x18));
        if (iVar11 != 0) goto LAB_23c000b5e;
        lVar21 = lVar21 + 1;
      } while (lVar16 != lVar21);
      pcVar25 = *(code **)(param_1 + 0x138);
    }
LAB_23c000a0d:
    if ((pcVar25 == (code *)0x0) || (pcVar25 == pcVar27)) {
      plVar28 = *(longlong **)PyExc_RuntimeError_exref;
      local_108 = (code *)PyUnicode_FromString("No active exception to reraise");
      pcVar25 = *(code **)(param_1 + 0x138);
      *plVar28 = *plVar28 + 1;
      *(longlong **)(param_1 + 0x138) = plVar13;
      if ((pcVar25 != (code *)0x0) &&
         (*(longlong *)pcVar25 = *(longlong *)pcVar25 + -1, *(longlong *)pcVar25 == 0)) {
        pcVar27 = (code *)0x0;
        iVar11 = 0x3d;
LAB_23c001275:
        (**(code **)(*(longlong *)(pcVar25 + 8) + 0x30))(pcVar25);
        if (pcVar27 == (code *)0x0) goto LAB_23c001cb1;
LAB_23c001290:
        pcVar23 = pcVar27;
        if (plVar5 == *(longlong **)(pcVar27 + 0x18)) goto LAB_23c000fe0;
        if (iVar11 == 0) goto LAB_23c0012a5;
        local_110 = _PyRuntime_exref;
        goto LAB_23c0012b4;
      }
      local_110 = _PyRuntime_exref;
      iVar11 = 0x3d;
    }
    else {
      plVar28 = *(longlong **)(pcVar25 + 8);
      pcVar27 = *(code **)(pcVar25 + 0x28);
      *(longlong *)pcVar25 = *(longlong *)pcVar25 + 1;
      *plVar28 = *plVar28 + 1;
      local_108 = pcVar25;
      if (pcVar27 != (code *)0x0) {
        *(longlong *)pcVar27 = *(longlong *)pcVar27 + 1;
        if (plVar5 == *(longlong **)(pcVar27 + 0x18)) {
          *(undefined4 *)(plVar5 + 5) = *(undefined4 *)(pcVar27 + 0x24);
        }
        *(longlong **)(param_1 + 0x138) = plVar13;
        *(longlong *)pcVar25 = *(longlong *)pcVar25 + -1;
        if (*(longlong *)pcVar25 == 0) {
          (*(code *)plVar28[6])(pcVar25);
          iVar11 = 0;
          goto LAB_23c001290;
        }
        pcVar23 = pcVar27;
        if (*(longlong **)(pcVar27 + 0x18) == plVar5) goto LAB_23c000fe0;
LAB_23c0012a5:
        iVar11 = (int)plVar5[5];
        local_110 = _PyRuntime_exref;
        goto LAB_23c0012b4;
      }
      *(longlong **)(param_1 + 0x138) = plVar13;
      *(longlong *)pcVar25 = *(longlong *)pcVar25 + -1;
      if (*(longlong *)pcVar25 == 0) {
        iVar11 = 0;
        goto LAB_23c001275;
      }
LAB_23c000f42:
      iVar11 = (int)plVar5[5];
LAB_23c000f4a:
      local_110 = _PyRuntime_exref;
    }
LAB_23c000f56:
    pcVar23 = DAT_23ed6a4f8;
    if (DAT_23ed6a4f8 == (code *)0x0) {
      pcVar23 = (code *)FUN_23a33a530(PyTraceBack_Type_exref);
    }
    else {
      pcVar27 = *(code **)DAT_23ed6a4f8;
      *(longlong *)DAT_23ed6a4f8 = 1;
      DAT_23ed6a4f8 = pcVar27;
      DAT_23ed6a4f0 = DAT_23ed6a4f0 + -1;
    }
    *(longlong *)(pcVar23 + 0x10) = 0;
    *(longlong **)(pcVar23 + 0x18) = plVar5;
    *plVar5 = *plVar5 + 1;
    lVar16 = *(longlong *)(local_110 + 0x1f8);
    *(int *)(pcVar23 + 0x24) = iVar11;
    lVar16 = *(longlong *)(lVar16 + 0x10);
    *(undefined4 *)(pcVar23 + 0x20) = 0xffffffff;
    lVar16 = *(longlong *)(lVar16 + 0x2e8);
    lVar21 = *(longlong *)(pcVar23 + -8);
    puVar4 = *(undefined8 **)(lVar16 + 8);
    *puVar4 = pcVar23 + -0x10;
    *(longlong *)(pcVar23 + -0x10) = lVar16;
    *(ulonglong *)(pcVar23 + -8) = (ulonglong)((uint)lVar21 & 3) | (ulonglong)puVar4;
    *(code **)(lVar16 + 8) = pcVar23 + -0x10;
  }
LAB_23c000fe0:
  FUN_23e8bba40(plVar5,"ooooo",plVar2,plVar3,pcVar12,plVar15,0);
  if (_DAT_23ee0b650 == plVar5) {
    *plVar5 = *plVar5 + -1;
    if (*plVar5 == 0) {
      (**(code **)(plVar5[1] + 0x30))(plVar5);
    }
    _DAT_23ee0b650 = (longlong *)0x0;
  }
  lVar16 = *(longlong *)(*(longlong *)(param_1 + 0x38) + 8);
  plVar13 = *(longlong **)(lVar16 + 0x28);
  plVar5 = (longlong *)plVar13[2];
  *(undefined8 *)(*(longlong *)(param_1 + 0x38) + 8) = *(undefined8 *)(lVar16 + 0x30);
  *(undefined4 *)(plVar13 + 8) = 0xffffffff;
  if (plVar5 != (longlong *)0x0) {
    plVar13[2] = 0;
    *plVar5 = *plVar5 + -1;
    if (*plVar5 == 0) {
      (**(code **)(plVar5[1] + 0x30))();
    }
  }
  *plVar13 = *plVar13 + -1;
  if (*plVar13 == 0) {
    (**(code **)(plVar13[1] + 0x30))(plVar13);
  }
  plVar13[0xf] = 0;
  if ((pcVar12 != (code *)0x0) &&
     (lVar16 = *(longlong *)pcVar12, *(longlong *)pcVar12 = lVar16 + -1, lVar16 + -1 == 0)) {
    (**(code **)(*(longlong *)(pcVar12 + 8) + 0x30))(pcVar12);
  }
  if ((plVar15 != (longlong *)0x0) && (*plVar15 = *plVar15 + -1, *plVar15 == 0)) {
    (**(code **)(plVar15[1] + 0x30))(plVar15);
  }
  lVar16 = *plVar2;
  *plVar2 = lVar16 + -1;
  if (lVar16 + -1 == 0) {
    (**(code **)(plVar2[1] + 0x30))(plVar2);
  }
  lVar16 = *plVar3;
  *plVar3 = lVar16 + -1;
  if (lVar16 + -1 == 0) {
    (**(code **)(plVar3[1] + 0x30))(plVar3);
  }
  FUN_23a33aa70(param_1,plVar28,local_108,pcVar23);
  return (code *)0x0;
}
