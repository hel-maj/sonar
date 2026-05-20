/* ===== 23c04ae50 config_manager:21 ===== */
/* ghidra_name=FUN_23c04ae50 entry=23c04ae50 size=8246 */

code * FUN_23c04ae50(longlong param_1,undefined8 param_2,undefined8 *param_3)

{
  undefined1 (*pauVar1) [16];
  undefined8 uVar2;
  longlong *plVar3;
  longlong lVar4;
  longlong *plVar5;
  undefined8 *puVar6;
  longlong lVar7;
  undefined1 auVar8 [16];
  bool bVar9;
  code *pcVar10;
  code *pcVar11;
  code *pcVar12;
  char cVar13;
  int iVar14;
  code *pcVar15;
  longlong *plVar16;
  longlong *plVar17;
  longlong lVar18;
  code *pcVar19;
  longlong *plVar20;
  longlong *plVar21;
  undefined8 uVar22;
  code *pcVar23;
  code *pcVar24;
  undefined8 *puVar25;
  code *pcVar26;
  code *pcVar27;
  code *pcVar28;
  undefined4 uVar29;
  code *local_120;
  code *local_118;
  code *local_110;
  code *local_108;
  longlong *local_e8;
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
  
  plVar3 = (longlong *)*param_3;
  pcVar15 = (code *)FUN_23e970f30(param_1,DAT_23ee075b8);
  plVar16 = DAT_23ee0b660;
  if (DAT_23ee0b660 == (longlong *)0x0) {
LAB_23c04aea4:
    DAT_23ee0b660 = (longlong *)FUN_23e91f3b0(param_1,DAT_23ee0b658,DAT_23ee0b670,0x30);
  }
  else {
    lVar18 = *DAT_23ee0b660;
    if (1 < lVar18) {
      *DAT_23ee0b660 = lVar18 + -1;
      goto LAB_23c04aea4;
    }
    if (DAT_23ee0b660[2] != 0) {
      *DAT_23ee0b660 = lVar18 + -1;
      if (lVar18 + -1 == 0) {
        (**(code **)(plVar16[1] + 0x30))(plVar16);
      }
      goto LAB_23c04aea4;
    }
  }
  plVar5 = DAT_23ee0b660;
  lVar18 = *(longlong *)(param_1 + 0x38);
  plVar16 = DAT_23ee0b660 + 9;
  lVar4 = *(longlong *)(lVar18 + 8);
  DAT_23ee0b660[0xf] = lVar4;
  *(longlong **)(lVar18 + 8) = plVar16;
  if ((lVar4 != 0) &&
     (((*(char *)(lVar4 + 0x45) == '\x01' ||
       ((ulonglong)
        (*(longlong *)(lVar4 + 0x20) + 0xb8 +
        (longlong)*(int *)(*(longlong *)(lVar4 + 0x20) + 0xa8) * 2) <= *(ulonglong *)(lVar4 + 0x38))
       ) && (plVar5[0xe] != 0)))) {
    plVar16 = *(longlong **)(lVar4 + 0x28);
    *(longlong **)(plVar5[0xe] + 0x10) = plVar16;
    if (plVar16 != (longlong *)0x0) {
      *plVar16 = *plVar16 + 1;
    }
  }
  *plVar5 = *plVar5 + 1;
  uVar22 = DAT_23ee07598;
  *(undefined4 *)(plVar5 + 8) = 0;
  plVar16 = (longlong *)FUN_23e8bc2f0(plVar3,uVar22);
  if (plVar16 == (longlong *)0x0) {
    local_118 = *(code **)(param_1 + 0x60);
    pcVar24 = *(code **)(param_1 + 0x70);
    *(undefined8 *)(param_1 + 0x70) = 0;
    local_120 = *(code **)(param_1 + 0x68);
    *(undefined1 (*) [16])(param_1 + 0x60) = (undefined1  [16])0x0;
    pcVar26 = (code *)0x0;
    if (pcVar24 == (code *)0x0) {
      pcVar19 = (code *)0x0;
      plVar16 = (longlong *)0x0;
      iVar14 = 0x26;
      local_110 = _PyRuntime_exref;
LAB_23c04bf26:
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
      *(longlong *)(pcVar23 + 0x10) = 0;
      *(longlong **)(pcVar23 + 0x18) = plVar5;
      *plVar5 = *plVar5 + 1;
      lVar18 = *(longlong *)(local_110 + 0x1f8);
      *(int *)(pcVar23 + 0x24) = iVar14;
      lVar18 = *(longlong *)(lVar18 + 0x10);
      *(undefined4 *)(pcVar23 + 0x20) = 0xffffffff;
      lVar18 = *(longlong *)(lVar18 + 0x2e8);
      lVar4 = *(longlong *)(pcVar23 + -8);
      puVar25 = *(undefined8 **)(lVar18 + 8);
      *puVar25 = pcVar23 + -0x10;
      *(longlong *)(pcVar23 + -0x10) = lVar18;
      *(ulonglong *)(pcVar23 + -8) = (ulonglong)((uint)lVar4 & 3) | (ulonglong)puVar25;
      *(code **)(lVar18 + 8) = pcVar23 + -0x10;
      goto LAB_23c04ba50;
    }
    if (plVar5 == *(longlong **)(pcVar24 + 0x18)) {
      pcVar19 = (code *)0x0;
      plVar16 = (longlong *)0x0;
      pcVar23 = pcVar24;
      goto LAB_23c04ba50;
    }
    pcVar19 = (code *)0x0;
    plVar16 = (longlong *)0x0;
    iVar14 = 0x26;
    local_110 = _PyRuntime_exref;
  }
  else {
    plVar17 = (longlong *)FUN_23e9367b0(param_1,plVar16);
    *plVar16 = *plVar16 + -1;
    if (*plVar16 == 0) {
      (**(code **)(plVar16[1] + 0x30))(plVar16);
    }
    if (plVar17 == (longlong *)0x0) {
      local_118 = *(code **)(param_1 + 0x60);
      pcVar24 = *(code **)(param_1 + 0x70);
      *(undefined8 *)(param_1 + 0x70) = 0;
      local_120 = *(code **)(param_1 + 0x68);
      *(undefined1 (*) [16])(param_1 + 0x60) = (undefined1  [16])0x0;
      plVar16 = (longlong *)0x0;
      if (pcVar24 == (code *)0x0) {
        pcVar19 = (code *)0x0;
        pcVar26 = (code *)0x0;
        iVar14 = 0x26;
        local_110 = _PyRuntime_exref;
        goto LAB_23c04bf26;
      }
      if (plVar5 == *(longlong **)(pcVar24 + 0x18)) {
        pcVar19 = (code *)0x0;
        pcVar26 = (code *)0x0;
        pcVar23 = pcVar24;
        goto LAB_23c04ba50;
      }
      pcVar19 = (code *)0x0;
      pcVar26 = (code *)0x0;
      iVar14 = 0x26;
LAB_23c04b0b7:
      local_110 = _PyRuntime_exref;
    }
    else {
      iVar14 = FUN_23a35f020(plVar17);
      *plVar17 = *plVar17 + -1;
      if (*plVar17 == 0) {
        (**(code **)(plVar17[1] + 0x30))(plVar17);
      }
      if (iVar14 != -1) {
        if (iVar14 == 0) {
          *(longlong *)pcVar15 = *(longlong *)pcVar15 + 1;
          pcVar19 = (code *)0x0;
          plVar16 = (longlong *)0x0;
          local_108 = (code *)0x0;
          local_118 = pcVar15;
LAB_23c04af98:
          lVar18 = *(longlong *)(*(longlong *)(param_1 + 0x38) + 8);
          plVar5 = *(longlong **)(lVar18 + 0x28);
          plVar17 = (longlong *)plVar5[2];
          *(undefined8 *)(*(longlong *)(param_1 + 0x38) + 8) = *(undefined8 *)(lVar18 + 0x30);
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
          *(longlong *)pcVar15 = *(longlong *)pcVar15 + -1;
          if (*(longlong *)pcVar15 == 0) {
            (**(code **)(*(longlong *)(pcVar15 + 8) + 0x30))(pcVar15);
          }
          if (local_108 != (code *)0x0) {
LAB_23c04affb:
            *(longlong *)local_108 = *(longlong *)local_108 + -1;
            if (*(longlong *)local_108 == 0) {
              (**(code **)(*(longlong *)(local_108 + 8) + 0x30))(local_108);
            }
          }
          if ((plVar16 != (longlong *)0x0) && (*plVar16 = *plVar16 + -1, *plVar16 == 0)) {
            (**(code **)(plVar16[1] + 0x30))(plVar16);
          }
          if ((pcVar19 != (code *)0x0) &&
             (*(longlong *)pcVar19 = *(longlong *)pcVar19 + -1, *(longlong *)pcVar19 == 0)) {
            (**(code **)(*(longlong *)(pcVar19 + 8) + 0x30))(pcVar19);
          }
          *plVar3 = *plVar3 + -1;
          if (*plVar3 != 0) {
            return local_118;
          }
          (**(code **)(plVar3[1] + 0x30))(plVar3);
          return local_118;
        }
        plVar16 = (longlong *)FUN_23e8bc2f0(plVar3,DAT_23ee07598);
        if (plVar16 == (longlong *)0x0) {
          local_d8 = *(undefined1 (*) [16])(param_1 + 0x60);
          local_c8[0] = *(code **)(param_1 + 0x70);
          *(undefined8 *)(param_1 + 0x70) = 0;
          local_108 = *(code **)(param_1 + 0x138);
          *(undefined1 (*) [16])(param_1 + 0x60) = (undefined1  [16])0x0;
          pcVar19 = (code *)0x0;
          if (local_108 == (code *)0x0) {
            if (local_c8[0] == (code *)0x0) goto LAB_23c04c9d7;
            local_118 = _Py_NoneStruct_exref;
            pcVar26 = (code *)0x0;
            plVar16 = (longlong *)0x0;
            goto LAB_23c04b4ac;
          }
          *(longlong *)local_108 = *(longlong *)local_108 + 1;
joined_r0x00023c04b49a:
          if (local_c8[0] == (code *)0x0) {
            pcVar19 = (code *)0x0;
            pcVar26 = (code *)0x0;
            plVar16 = (longlong *)0x0;
            uVar29 = 0x2a;
            local_118 = _Py_NoneStruct_exref;
            goto LAB_23c04b8c6;
          }
        }
        else {
          plVar17 = (longlong *)FUN_23e91c870(param_1,plVar16,DAT_23ed6ce80,DAT_23ee075c0);
          *plVar16 = *plVar16 + -1;
          if (*plVar16 == 0) {
            (**(code **)(plVar16[1] + 0x30))();
          }
          if (plVar17 == (longlong *)0x0) {
            local_d8 = *(undefined1 (*) [16])(param_1 + 0x60);
            local_c8[0] = *(code **)(param_1 + 0x70);
            *(undefined8 *)(param_1 + 0x70) = 0;
            local_108 = *(code **)(param_1 + 0x138);
            *(undefined1 (*) [16])(param_1 + 0x60) = (undefined1  [16])0x0;
joined_r0x00023c04bdc8:
            if (local_108 != (code *)0x0) {
              *(longlong *)local_108 = *(longlong *)local_108 + 1;
              goto joined_r0x00023c04b49a;
            }
          }
          else {
            plVar16 = (longlong *)FUN_23e8d9880(plVar17,DAT_23ed6cd90);
            if (plVar16 != (longlong *)0x0) {
              *(undefined4 *)(plVar5 + 5) = 0x2a;
              local_108 = (code *)FUN_23e91a870(param_1,plVar16);
              *plVar16 = *plVar16 + -1;
              if (*plVar16 == 0) {
                (**(code **)(plVar16[1] + 0x30))();
              }
              if (local_108 != (code *)0x0) {
                local_120 = (code *)FUN_23e8d9880(plVar17,DAT_23ed6cd98);
                local_118 = _Py_NoneStruct_exref;
                if (local_120 == (code *)0x0) {
                  pcVar24 = *(code **)(param_1 + 0x70);
                  pcVar19 = (code *)0x0;
                  plVar16 = (longlong *)0x0;
                  *(undefined8 *)(param_1 + 0x70) = 0;
                  pcVar23 = *(code **)(param_1 + 0x60);
                  local_110._0_4_ = 0x2a;
                  *(undefined1 (*) [16])(param_1 + 0x60) = (undefined1  [16])0x0;
                  pcVar26 = (code *)0x0;
                  pcVar27 = *(code **)(param_1 + 0x68);
                  pcVar10 = local_78;
                  pcVar11 = pcStack_70;
                  pcVar12 = local_68;
                  goto LAB_23c04c134;
                }
                *(longlong *)local_108 = *(longlong *)local_108 + 1;
                lVar18 = FUN_23eb1ba00();
                uVar22 = DAT_23ee075d0;
                if (lVar18 == 0) {
                  pcVar19 = (code *)0x0;
                  FUN_23e915740(param_1,&local_98,DAT_23ee075c8);
                  local_110 = _PyRuntime_exref;
                  local_118._0_4_ = 0x2b;
                  plVar16 = (longlong *)0x0;
                  pcVar24 = local_88;
                  goto LAB_23c04c2b1;
                }
                *(undefined4 *)(plVar5 + 5) = 0x2b;
                plVar16 = (longlong *)FUN_23e915840(param_1,lVar18,uVar22,local_108);
                local_110 = _PyRuntime_exref;
                if (plVar16 == (longlong *)0x0) {
                  pcVar24 = *(code **)(param_1 + 0x70);
                  local_98 = *(undefined8 *)(param_1 + 0x60);
                  uStack_90 = *(undefined8 *)(param_1 + 0x68);
                  pcVar19 = (code *)0x0;
                  *(undefined1 (*) [16])(param_1 + 0x60) = (undefined1  [16])0x0;
                  local_118._0_4_ = 0x2b;
                  *(undefined8 *)(param_1 + 0x70) = 0;
                  goto LAB_23c04c2b1;
                }
                lVar18 = *(longlong *)(param_1 + 0x10);
                puVar25 = *(undefined8 **)(lVar18 + 0xe20);
                if (puVar25 == (undefined8 *)0x0) {
                  puVar25 = (undefined8 *)FUN_23e916a20(PyTuple_Type_exref,2);
                }
                else {
                  uVar22 = puVar25[3];
                  *(int *)(lVar18 + 0xebc) = *(int *)(lVar18 + 0xebc) + -1;
                  *(undefined8 *)(lVar18 + 0xe20) = uVar22;
                  *puVar25 = 1;
                }
                local_110 = _PyRuntime_exref;
                lVar18 = *(longlong *)
                          (*(longlong *)(*(longlong *)(_PyRuntime_exref + 0x1f8) + 0x10) + 0x2e8);
                uVar22 = puVar25[-1];
                puVar6 = *(undefined8 **)(lVar18 + 8);
                *puVar6 = puVar25 + -2;
                puVar25[-2] = lVar18;
                puVar25[-1] = (ulonglong)((uint)uVar22 & 3) | (ulonglong)puVar6;
                *(undefined8 **)(lVar18 + 8) = puVar25 + -2;
                *(longlong *)pcVar15 = *(longlong *)pcVar15 + 1;
                puVar25[3] = pcVar15;
                *plVar16 = *plVar16 + 1;
                puVar25[4] = plVar16;
                pcVar19 = (code *)FUN_23ebf8230(param_1);
                pcVar26 = PySequence_Contains_exref;
                if (pcVar19 != (code *)0x0) {
                  iVar14 = PySequence_Contains(plVar16,DAT_23ee075d8);
                  if (iVar14 != -1) {
                    if (iVar14 == 1) goto LAB_23c04cab0;
                    goto LAB_23c04b2e7;
                  }
                  local_98 = *(undefined8 *)(param_1 + 0x60);
                  uStack_90 = *(undefined8 *)(param_1 + 0x68);
                  pcVar24 = *(code **)(param_1 + 0x70);
                  local_118._0_4_ = 0x2f;
                  *(undefined8 *)(param_1 + 0x70) = 0;
                  *(undefined1 (*) [16])(param_1 + 0x60) = (undefined1  [16])0x0;
                  goto LAB_23c04c2b1;
                }
                local_98 = *(undefined8 *)(param_1 + 0x60);
                uStack_90 = *(undefined8 *)(param_1 + 0x68);
                pcVar24 = *(code **)(param_1 + 0x70);
                local_118._0_4_ = 0x2d;
                *(undefined8 *)(param_1 + 0x70) = 0;
                *(undefined1 (*) [16])(param_1 + 0x60) = (undefined1  [16])0x0;
                goto LAB_23c04c2b1;
              }
            }
            pauVar1 = (undefined1 (*) [16])(param_1 + 0x60);
            pcVar23 = *(code **)*pauVar1;
            auVar8 = *pauVar1;
            local_d8 = *pauVar1;
            pcVar24 = *(code **)(param_1 + 0x70);
            *(undefined8 *)(param_1 + 0x70) = 0;
            *(undefined1 (*) [16])(param_1 + 0x60) = (undefined1  [16])0x0;
            *plVar17 = *plVar17 + -1;
            local_c8[0] = pcVar24;
            if (*plVar17 != 0) {
              local_108 = *(code **)(param_1 + 0x138);
              goto joined_r0x00023c04bdc8;
            }
            (**(code **)(plVar17[1] + 0x30))();
            local_108 = *(code **)(param_1 + 0x138);
            local_d8 = auVar8;
            if (local_108 != (code *)0x0) {
              pcVar26 = (code *)0x0;
              plVar16 = (longlong *)0x0;
              local_110._0_4_ = 0x2a;
              pcVar19 = (code *)0x0;
              local_118 = _Py_NoneStruct_exref;
              goto LAB_23c04bc70;
            }
          }
          if (local_c8[0] == (code *)0x0) {
LAB_23c04c9d7:
            local_118 = _Py_NoneStruct_exref;
            pcVar26 = (code *)0x0;
            plVar16 = (longlong *)0x0;
            pcVar19 = (code *)0x0;
            local_108 = (code *)0x0;
            uVar29 = 0x2a;
            goto LAB_23c04b8c6;
          }
        }
        pcVar19 = (code *)0x0;
        pcVar26 = (code *)0x0;
        plVar16 = (longlong *)0x0;
        local_118 = _Py_NoneStruct_exref;
LAB_23c04b4ac:
        pcVar23 = local_c8[0];
        pcVar24 = DAT_23ed6a4f8;
        if (DAT_23ed6a4f8 == (code *)0x0) {
          pcVar24 = (code *)FUN_23a33a530(PyTraceBack_Type_exref);
        }
        else {
          pcVar27 = *(code **)DAT_23ed6a4f8;
          *(longlong *)DAT_23ed6a4f8 = 1;
          DAT_23ed6a4f8 = pcVar27;
          DAT_23ed6a4f0 = DAT_23ed6a4f0 + -1;
        }
        *(longlong **)(pcVar24 + 0x18) = plVar5;
        *plVar5 = *plVar5 + 1;
        *(longlong *)(pcVar24 + 0x20) = 0x2affffffff;
        lVar18 = *(longlong *)
                  (*(longlong *)(*(longlong *)(_PyRuntime_exref + 0x1f8) + 0x10) + 0x2e8);
        lVar4 = *(longlong *)(pcVar24 + -8);
        puVar25 = *(undefined8 **)(lVar18 + 8);
        *puVar25 = pcVar24 + -0x10;
        *(longlong *)(pcVar24 + -0x10) = lVar18;
        *(ulonglong *)(pcVar24 + -8) = (ulonglong)((uint)lVar4 & 3) | (ulonglong)puVar25;
        *(code **)(lVar18 + 8) = pcVar24 + -0x10;
        *(code **)(pcVar24 + 0x10) = pcVar23;
        *(longlong *)pcVar23 = *(longlong *)pcVar23 + 1;
        pcVar23 = local_c8[0];
joined_r0x00023c04b53c:
        if ((pcVar23 != (code *)0x0) &&
           (*(longlong *)pcVar23 = *(longlong *)pcVar23 + -1, *(longlong *)pcVar23 == 0)) {
          (**(code **)(*(longlong *)(pcVar23 + 8) + 0x30))();
        }
        pcVar23 = (code *)local_d8._0_8_;
        local_c8[0] = pcVar24;
        do {
          if ((pcVar23 != local_118) && (pcVar23 != (code *)0x0)) {
            FUN_23e91b1b0(param_1,local_d8,local_d8 + 8,local_c8);
          }
          plVar17 = *(longlong **)(local_d8._8_8_ + 0x28);
          if (local_c8[0] == local_118) {
            pcVar24 = (code *)0x0;
          }
          else {
            pcVar24 = local_c8[0];
            if (local_c8[0] != (code *)0x0) {
              *(longlong *)local_c8[0] = *(longlong *)local_c8[0] + 1;
            }
          }
          *(code **)(local_d8._8_8_ + 0x28) = pcVar24;
          if ((plVar17 != (longlong *)0x0) && (*plVar17 = *plVar17 + -1, *plVar17 == 0)) {
            (**(code **)(plVar17[1] + 0x30))();
          }
          plVar17 = *(longlong **)(param_1 + 0x138);
          *(undefined8 *)(param_1 + 0x138) = local_d8._8_8_;
          if ((plVar17 != (longlong *)0x0) && (*plVar17 = *plVar17 + -1, *plVar17 == 0)) {
            (**(code **)(plVar17[1] + 0x30))();
          }
          *(longlong *)local_d8._0_8_ = *(longlong *)local_d8._0_8_ + -1;
          if (*(longlong *)local_d8._0_8_ == 0) {
            (**(code **)(*(longlong *)(local_d8._0_8_ + 8) + 0x30))();
          }
          if ((local_c8[0] != (code *)0x0) &&
             (*(longlong *)local_c8[0] = *(longlong *)local_c8[0] + -1,
             *(longlong *)local_c8[0] == 0)) {
            (**(code **)(*(longlong *)(local_c8[0] + 8) + 0x30))();
          }
          local_c8[0] = (code *)0x0;
          local_d8 = (undefined1  [16])0x0;
          iVar14 = FUN_23a35ebd0(param_1,*(undefined8 *)(*(longlong *)(param_1 + 0x138) + 8),
                                 *(undefined8 *)PyExc_Exception_exref);
          if (iVar14 == 0) {
            pcVar23 = *(code **)(param_1 + 0x138);
            if ((pcVar23 == local_118) || (pcVar23 == (code *)0x0)) {
              local_118 = *(code **)PyExc_RuntimeError_exref;
              local_120 = (code *)PyUnicode_FromString("No active exception to reraise");
              pcVar23 = *(code **)(param_1 + 0x138);
              *(longlong *)local_118 = *(longlong *)local_118 + 1;
              *(code **)(param_1 + 0x138) = local_108;
              if ((pcVar23 == (code *)0x0) ||
                 (*(longlong *)pcVar23 = *(longlong *)pcVar23 + -1, *(longlong *)pcVar23 != 0)) {
                iVar14 = 0x29;
                local_110 = _PyRuntime_exref;
                goto LAB_23c04bf26;
              }
              pcVar24 = (code *)0x0;
              iVar14 = 0x29;
LAB_23c04c006:
              (**(code **)(*(longlong *)(pcVar23 + 8) + 0x30))();
              if (pcVar24 != (code *)0x0) {
LAB_23c04bd63:
                pcVar23 = pcVar24;
                if (plVar5 == *(longlong **)(pcVar24 + 0x18)) goto LAB_23c04ba50;
                if (iVar14 != 0) goto LAB_23c04b0b7;
LAB_23c04bd76:
                local_110 = _PyRuntime_exref;
                iVar14 = (int)plVar5[5];
                goto LAB_23c04b9b7;
              }
              if (iVar14 != 0) goto LAB_23c04c23d;
            }
            else {
              local_118 = *(code **)(pcVar23 + 8);
              pcVar24 = *(code **)(pcVar23 + 0x28);
              *(longlong *)pcVar23 = *(longlong *)pcVar23 + 1;
              *(longlong *)local_118 = *(longlong *)local_118 + 1;
              iVar14 = 0;
              local_120 = pcVar23;
              if (pcVar24 != (code *)0x0) {
                *(longlong *)pcVar24 = *(longlong *)pcVar24 + 1;
                if (plVar5 == *(longlong **)(pcVar24 + 0x18)) {
                  *(undefined4 *)(plVar5 + 5) = *(undefined4 *)(pcVar24 + 0x24);
                }
                *(code **)(param_1 + 0x138) = local_108;
                lVar18 = *(longlong *)pcVar23;
                *(longlong *)pcVar23 = lVar18 + -1;
                if (lVar18 + -1 == 0) {
                  (**(code **)((longlong)local_118 + 0x30))();
                  goto LAB_23c04bd63;
                }
                pcVar23 = pcVar24;
                if (plVar5 != *(longlong **)(pcVar24 + 0x18)) goto LAB_23c04bd76;
                goto LAB_23c04ba50;
              }
              *(code **)(param_1 + 0x138) = local_108;
              lVar18 = *(longlong *)pcVar23;
              *(longlong *)pcVar23 = lVar18 + -1;
              if (lVar18 + -1 == 0) goto LAB_23c04c006;
            }
            local_110 = _PyRuntime_exref;
            iVar14 = (int)plVar5[5];
            goto LAB_23c04bf26;
          }
          plVar17 = *(longlong **)(param_1 + 0x138);
          *plVar17 = *plVar17 + 1;
          local_120 = (code *)&DAT_23ed6cce0;
          uVar22 = FUN_23a3a0d40(DAT_23ed6cf28);
          plVar21 = DAT_23ee07600;
          lVar18 = *(longlong *)(param_1 + 0x10);
          plVar20 = *(longlong **)(lVar18 + 0xe20);
          if (plVar20 == (longlong *)0x0) {
            plVar20 = (longlong *)FUN_23e916a20(PyTuple_Type_exref,2);
          }
          else {
            lVar4 = plVar20[3];
            *(int *)(lVar18 + 0xebc) = *(int *)(lVar18 + 0xebc) + -1;
            *(longlong *)(lVar18 + 0xe20) = lVar4;
            *plVar20 = 1;
          }
          local_110 = _PyRuntime_exref;
          plVar20[4] = 0;
          lVar18 = *(longlong *)(*(longlong *)(*(longlong *)(local_110 + 0x1f8) + 0x10) + 0x2e8);
          lVar4 = plVar20[-1];
          puVar25 = *(undefined8 **)(lVar18 + 8);
          *puVar25 = plVar20 + -2;
          plVar20[-2] = lVar18;
          plVar20[-1] = (ulonglong)((uint)lVar4 & 3) | (ulonglong)puVar25;
          *(longlong **)(lVar18 + 8) = plVar20 + -2;
          *plVar21 = *plVar21 + 1;
          plVar20[3] = (longlong)plVar21;
          uVar2 = DAT_23ed6cd28;
          if (DAT_23ed6a4c0 != (longlong *)0x0) {
LAB_23c04b743:
            local_e8 = plVar17;
            uStack_e0 = uVar2;
            lVar18 = FUN_23e94ed00(param_1,DAT_23ed6a4c0,&local_e8);
            if (lVar18 == 0) {
              local_118 = *(code **)(param_1 + 0x60);
              pcVar24 = *(code **)(param_1 + 0x70);
              *(undefined8 *)(param_1 + 0x70) = 0;
              local_120 = *(code **)(param_1 + 0x68);
              *(undefined1 (*) [16])(param_1 + 0x60) = (undefined1  [16])0x0;
              *plVar20 = *plVar20 + -1;
              if (*plVar20 == 0) {
                (**(code **)(plVar20[1] + 0x30))(plVar20);
              }
            }
            else {
              plVar20[4] = lVar18;
              plVar21 = (longlong *)PyUnicode_Join(DAT_23ed6cd28,plVar20);
              *plVar20 = *plVar20 + -1;
              if (*plVar20 == 0) {
                (**(code **)(plVar20[1] + 0x30))(plVar20);
              }
              if (plVar21 != (longlong *)0x0) {
                *(undefined4 *)(plVar5 + 5) = 0x38;
                plVar20 = (longlong *)FUN_23e914090(param_1,uVar22);
                *plVar21 = *plVar21 + -1;
                if (*plVar21 == 0) {
                  (**(code **)(plVar21[1] + 0x30))(plVar21);
                }
                if (plVar20 != (longlong *)0x0) {
                  *plVar20 = *plVar20 + -1;
                  if (*plVar20 == 0) {
                    (**(code **)(plVar20[1] + 0x30))(plVar20);
                  }
                  *(longlong *)pcVar15 = *(longlong *)pcVar15 + 1;
                  *plVar17 = *plVar17 + -1;
                  if (*plVar17 == 0) {
                    (**(code **)(plVar17[1] + 0x30))(plVar17);
                  }
                  plVar5 = *(longlong **)(param_1 + 0x138);
                  *(code **)(param_1 + 0x138) = local_108;
                  local_108 = pcVar26;
                  local_118 = pcVar15;
                  if ((plVar5 != (longlong *)0x0) && (*plVar5 = *plVar5 + -1, *plVar5 == 0)) {
                    (**(code **)(plVar5[1] + 0x30))();
                  }
                  goto LAB_23c04af98;
                }
              }
              local_118 = *(code **)(param_1 + 0x60);
              pcVar24 = *(code **)(param_1 + 0x70);
              *(undefined8 *)(param_1 + 0x70) = 0;
              local_120 = *(code **)(param_1 + 0x68);
              *(undefined1 (*) [16])(param_1 + 0x60) = (undefined1  [16])0x0;
            }
            *plVar17 = *plVar17 + -1;
            if (*plVar17 == 0) {
              (**(code **)(plVar17[1] + 0x30))(plVar17);
            }
            pcVar23 = *(code **)(param_1 + 0x138);
            *(code **)(param_1 + 0x138) = local_108;
            if (pcVar23 == (code *)0x0) {
              if (pcVar24 == (code *)0x0) {
LAB_23c04c9cc:
                iVar14 = 0x38;
                goto LAB_23c04bf26;
              }
              plVar17 = *(longlong **)(pcVar24 + 0x18);
            }
            else {
              *(longlong *)pcVar23 = *(longlong *)pcVar23 + -1;
              if (*(longlong *)pcVar23 == 0) {
                iVar14 = 0x38;
                goto LAB_23c04c006;
              }
              if (pcVar24 == (code *)0x0) goto LAB_23c04c9cc;
              plVar17 = *(longlong **)(pcVar24 + 0x18);
            }
            pcVar23 = pcVar24;
            if (plVar17 == plVar5) goto LAB_23c04ba50;
            iVar14 = 0x38;
            goto LAB_23c04b9b7;
          }
          plVar21 = (longlong *)PyDict_GetItemString(DAT_23ed6ccc0,"format");
          if (plVar21 != (longlong *)0x0) {
            *plVar21 = *plVar21 + 1;
            DAT_23ed6a4c0 = plVar21;
            goto LAB_23c04b743;
          }
          PyErr_PrintEx(0);
          Py_Exit(1);
LAB_23c04cab0:
          lVar18 = FUN_23e913e30(param_1,pcVar15,DAT_23ee075d8);
          if (lVar18 == 0) goto LAB_23c04cbc3;
          lVar4 = *(longlong *)(param_1 + 0x10);
          plVar20 = *(longlong **)(lVar4 + 0xe20);
          if (plVar20 == (longlong *)0x0) {
            plVar20 = (longlong *)FUN_23e916a20(PyTuple_Type_exref,2);
          }
          else {
            lVar7 = plVar20[3];
            *(int *)(lVar4 + 0xebc) = *(int *)(lVar4 + 0xebc) + -1;
            *(longlong *)(lVar4 + 0xe20) = lVar7;
            *plVar20 = 1;
          }
          plVar20[4] = 0;
          lVar4 = *(longlong *)(*(longlong *)(*(longlong *)(local_110 + 0x1f8) + 0x10) + 0x2e8);
          lVar7 = plVar20[-1];
          puVar25 = *(undefined8 **)(lVar4 + 8);
          *puVar25 = plVar20 + -2;
          uVar22 = DAT_23ee075d8;
          plVar20[-2] = lVar4;
          plVar20[-1] = (ulonglong)((uint)lVar7 & 3) | (ulonglong)puVar25;
          *(longlong **)(lVar4 + 8) = plVar20 + -2;
          plVar20[3] = lVar18;
          lVar18 = FUN_23a38cc10(param_1,plVar16,uVar22);
          if (lVar18 == 0) {
            local_98 = *(undefined8 *)(param_1 + 0x60);
            uStack_90 = *(undefined8 *)(param_1 + 0x68);
            pcVar24 = *(code **)(param_1 + 0x70);
            *(undefined1 (*) [16])(param_1 + 0x60) = (undefined1  [16])0x0;
            local_118._0_4_ = 0x30;
            *(undefined8 *)(param_1 + 0x70) = 0;
            *plVar20 = *plVar20 + -1;
            if (*plVar20 == 0) {
              FUN_23a334bc0(plVar20);
              local_118._0_4_ = 0x30;
            }
            goto LAB_23c04c2b1;
          }
          plVar20[4] = lVar18;
          plVar20 = (longlong *)FUN_23ebf8230(param_1,plVar20);
          if (plVar20 == (longlong *)0x0) {
LAB_23c04cbc3:
            local_98 = *(undefined8 *)(param_1 + 0x60);
            pcVar24 = *(code **)(param_1 + 0x70);
            local_118._0_4_ = 0x30;
            *(undefined8 *)(param_1 + 0x70) = 0;
            *(undefined1 (*) [16])(param_1 + 0x60) = (undefined1  [16])0x0;
            uStack_90 = *(undefined8 *)(param_1 + 0x68);
LAB_23c04c2b1:
            plVar20 = *(longlong **)(param_1 + 0x138);
            local_b8._8_8_ = uStack_90;
            local_b8._0_8_ = local_98;
            if (plVar20 != (longlong *)0x0) {
              *plVar20 = *plVar20 + 1;
            }
            pcVar26 = DAT_23ed6a4f8;
            local_a8[0] = pcVar24;
            if (pcVar24 == (code *)0x0) {
              if (DAT_23ed6a4f8 == (code *)0x0) {
                pcVar26 = (code *)FUN_23a33a530(PyTraceBack_Type_exref);
              }
              else {
                pcVar24 = *(code **)DAT_23ed6a4f8;
                *(longlong *)DAT_23ed6a4f8 = 1;
                DAT_23ed6a4f8 = pcVar24;
                DAT_23ed6a4f0 = DAT_23ed6a4f0 + -1;
              }
              *(longlong *)(pcVar26 + 0x10) = 0;
              *(longlong **)(pcVar26 + 0x18) = plVar5;
              *plVar5 = *plVar5 + 1;
              lVar18 = *(longlong *)(local_110 + 0x1f8);
              *(undefined4 *)(pcVar26 + 0x24) = local_118._0_4_;
              lVar18 = *(longlong *)(lVar18 + 0x10);
              *(undefined4 *)(pcVar26 + 0x20) = 0xffffffff;
              lVar18 = *(longlong *)(lVar18 + 0x2e8);
              lVar4 = *(longlong *)(pcVar26 + -8);
              puVar25 = *(undefined8 **)(lVar18 + 8);
              *puVar25 = pcVar26 + -0x10;
              *(longlong *)(pcVar26 + -0x10) = lVar18;
              *(ulonglong *)(pcVar26 + -8) = (ulonglong)((uint)lVar4 & 3) | (ulonglong)puVar25;
              *(code **)(lVar18 + 8) = pcVar26 + -0x10;
              if ((local_a8[0] != (code *)0x0) &&
                 (*(longlong *)local_a8[0] = *(longlong *)local_a8[0] + -1,
                 *(longlong *)local_a8[0] == 0)) {
                (**(code **)(*(longlong *)(local_a8[0] + 8) + 0x30))(local_a8[0]);
              }
            }
            else {
              if (DAT_23ed6a4f8 == (code *)0x0) {
                pcVar26 = (code *)FUN_23a33a530(PyTraceBack_Type_exref);
              }
              else {
                pcVar23 = *(code **)DAT_23ed6a4f8;
                *(longlong *)DAT_23ed6a4f8 = 1;
                DAT_23ed6a4f8 = pcVar23;
                DAT_23ed6a4f0 = DAT_23ed6a4f0 + -1;
              }
              *(longlong **)(pcVar26 + 0x18) = plVar5;
              *plVar5 = *plVar5 + 1;
              lVar18 = *(longlong *)(local_110 + 0x1f8);
              *(undefined4 *)(pcVar26 + 0x24) = local_118._0_4_;
              *(undefined4 *)(pcVar26 + 0x20) = 0xffffffff;
              lVar18 = *(longlong *)(*(longlong *)(lVar18 + 0x10) + 0x2e8);
              lVar4 = *(longlong *)(pcVar26 + -8);
              puVar25 = *(undefined8 **)(lVar18 + 8);
              *puVar25 = pcVar26 + -0x10;
              *(longlong *)(pcVar26 + -0x10) = lVar18;
              *(ulonglong *)(pcVar26 + -8) = (ulonglong)((uint)lVar4 & 3) | (ulonglong)puVar25;
              *(code **)(lVar18 + 8) = pcVar26 + -0x10;
              *(code **)(pcVar26 + 0x10) = pcVar24;
              *(longlong *)pcVar24 = *(longlong *)pcVar24 + 1;
              if ((local_a8[0] != (code *)0x0) &&
                 (*(longlong *)local_a8[0] = *(longlong *)local_a8[0] + -1,
                 *(longlong *)local_a8[0] == 0)) {
                (**(code **)(*(longlong *)(local_a8[0] + 8) + 0x30))();
              }
            }
            local_118 = _Py_NoneStruct_exref;
            local_a8[0] = pcVar26;
            if (((code *)local_b8._0_8_ != (code *)0x0) &&
               ((code *)local_b8._0_8_ != _Py_NoneStruct_exref)) {
              FUN_23e91b1b0(param_1,local_b8,local_b8 + 8,local_a8);
            }
            plVar21 = *(longlong **)(local_b8._8_8_ + 0x28);
            if (local_a8[0] == local_118) {
              pcVar24 = (code *)0x0;
            }
            else {
              pcVar24 = local_a8[0];
              if (local_a8[0] != (code *)0x0) {
                *(longlong *)local_a8[0] = *(longlong *)local_a8[0] + 1;
              }
            }
            *(code **)(local_b8._8_8_ + 0x28) = pcVar24;
            if ((plVar21 != (longlong *)0x0) && (*plVar21 = *plVar21 + -1, *plVar21 == 0)) {
              (**(code **)(plVar21[1] + 0x30))();
            }
            plVar21 = *(longlong **)(param_1 + 0x138);
            *(undefined8 *)(param_1 + 0x138) = local_b8._8_8_;
            if ((plVar21 != (longlong *)0x0) && (*plVar21 = *plVar21 + -1, *plVar21 == 0)) {
              (**(code **)(plVar21[1] + 0x30))();
            }
            *(longlong *)local_b8._0_8_ = *(longlong *)local_b8._0_8_ + -1;
            if (*(longlong *)local_b8._0_8_ == 0) {
              (**(code **)(*(longlong *)(local_b8._0_8_ + 8) + 0x30))();
            }
            if ((local_a8[0] != (code *)0x0) &&
               (*(longlong *)local_a8[0] = *(longlong *)local_a8[0] + -1,
               *(longlong *)local_a8[0] == 0)) {
              (**(code **)(*(longlong *)(local_a8[0] + 8) + 0x30))();
            }
            local_a8[0] = (code *)0x0;
            local_b8 = (undefined1  [16])0x0;
            iVar14 = FUN_23a35ebd0(param_1,*(undefined8 *)(*(longlong *)(param_1 + 0x138) + 8),
                                   *(undefined8 *)PyExc_BaseException_exref);
            pcVar26 = local_108;
            if (iVar14 == 0) {
              pcVar28 = *(code **)(param_1 + 0x138);
              if ((pcVar28 == local_118) || (pcVar28 == (code *)0x0)) {
                pcVar23 = *(code **)PyExc_RuntimeError_exref;
                pcVar27 = (code *)PyUnicode_FromString("No active exception to reraise");
                pcVar28 = *(code **)(param_1 + 0x138);
                *(longlong *)pcVar23 = *(longlong *)pcVar23 + 1;
                *(longlong **)(param_1 + 0x138) = plVar20;
                if (pcVar28 != (code *)0x0) {
                  local_110._0_4_ = 0x2a;
                  bVar9 = true;
                  pcVar24 = (code *)0x0;
                  goto LAB_23c04c5a0;
                }
                local_68 = (code *)0x0;
                local_110._0_4_ = 0x2a;
                local_78 = pcVar23;
                pcStack_70 = pcVar27;
              }
              else {
                pcVar23 = *(code **)(pcVar28 + 8);
                pcVar24 = *(code **)(pcVar28 + 0x28);
                *(longlong *)pcVar28 = *(longlong *)pcVar28 + 1;
                *(longlong *)pcVar23 = *(longlong *)pcVar23 + 1;
                if ((pcVar24 != (code *)0x0) &&
                   (*(longlong *)pcVar24 = *(longlong *)pcVar24 + 1,
                   plVar5 == *(longlong **)(pcVar24 + 0x18))) {
                  *(undefined4 *)(plVar5 + 5) = *(undefined4 *)(pcVar24 + 0x24);
                }
                bVar9 = true;
                *(longlong **)(param_1 + 0x138) = plVar20;
                local_110._0_4_ = 0;
                pcVar27 = pcVar28;
LAB_23c04c5a0:
                *(longlong *)pcVar28 = *(longlong *)pcVar28 + -1;
                if (*(longlong *)pcVar28 == 0) {
                  (**(code **)(*(longlong *)(pcVar28 + 8) + 0x30))();
                }
                local_78 = pcVar23;
                pcVar10 = pcVar23;
                pcStack_70 = pcVar27;
                pcVar11 = pcVar27;
                local_68 = pcVar24;
                pcVar12 = pcVar24;
                if (!bVar9) goto LAB_23c04c134;
              }
              *(undefined4 *)(plVar5 + 5) = 0x2a;
              plVar20 = (longlong *)FUN_23e957a30(param_1,local_120);
              if (plVar20 == (longlong *)0x0) {
                pcVar24 = *(code **)(param_1 + 0x70);
                pcVar23 = *(code **)(param_1 + 0x60);
                pcVar27 = *(code **)(param_1 + 0x68);
                *(undefined8 *)(param_1 + 0x70) = 0;
                *(undefined1 (*) [16])(param_1 + 0x60) = (undefined1  [16])0x0;
                FUN_23a35d6b0(&local_78);
                local_110._0_4_ = 0x2a;
                pcVar10 = local_78;
                pcVar11 = pcStack_70;
                pcVar12 = local_68;
              }
              else {
                *plVar20 = *plVar20 + -1;
                pcVar24 = local_68;
                pcVar23 = local_78;
                pcVar27 = pcStack_70;
                pcVar10 = local_78;
                pcVar11 = pcStack_70;
                pcVar12 = local_68;
                if (*plVar20 == 0) {
                  (**(code **)(plVar20[1] + 0x30))(plVar20);
                  pcVar24 = local_68;
                  pcVar23 = local_78;
                  pcVar27 = pcStack_70;
                  pcVar10 = local_78;
                  pcVar11 = pcStack_70;
                  pcVar12 = local_68;
                }
              }
            }
            else {
              pcStack_70 = *(code **)(param_1 + 0x138);
              local_78 = *(code **)(pcStack_70 + 8);
              local_68 = *(code **)(pcStack_70 + 0x28);
              *(undefined4 *)(plVar5 + 5) = 0x2a;
              if (local_68 == (code *)0x0) {
                local_68 = local_118;
              }
              plVar21 = (longlong *)FUN_23e956150(param_1,local_120);
              if (plVar21 == (longlong *)0x0) {
                pcVar24 = *(code **)(param_1 + 0x70);
                pcVar23 = *(code **)(param_1 + 0x60);
                pcVar27 = *(code **)(param_1 + 0x68);
                *(undefined1 (*) [16])(param_1 + 0x60) = (undefined1  [16])0x0;
              }
              else {
                iVar14 = FUN_23a35f020(plVar21);
                *plVar21 = *plVar21 + -1;
                if (*plVar21 == 0) {
                  (**(code **)(plVar21[1] + 0x30))(plVar21);
                }
                if (iVar14 != -1) {
                  if (iVar14 == 0) {
                    pcVar28 = *(code **)(param_1 + 0x138);
                    bVar9 = false;
                    if ((pcVar28 == local_118) || (pcVar28 == (code *)0x0)) {
                      pcVar23 = *(code **)PyExc_RuntimeError_exref;
                      pcVar27 = (code *)PyUnicode_FromString("No active exception to reraise");
                      pcVar28 = *(code **)(param_1 + 0x138);
                      *(longlong *)pcVar23 = *(longlong *)pcVar23 + 1;
                      *(longlong **)(param_1 + 0x138) = plVar20;
                      if (pcVar28 == (code *)0x0) {
                        local_68 = (code *)0x0;
                        local_110._0_4_ = 0x2a;
                        pcVar24 = local_68;
                        pcVar10 = pcVar23;
                        pcVar11 = pcVar27;
                        pcVar12 = local_68;
                        goto LAB_23c04c134;
                      }
                      local_110._0_4_ = 0x2a;
                      pcVar24 = (code *)0x0;
                    }
                    else {
                      pcVar23 = *(code **)(pcVar28 + 8);
                      pcVar24 = *(code **)(pcVar28 + 0x28);
                      *(longlong *)pcVar28 = *(longlong *)pcVar28 + 1;
                      *(longlong *)pcVar23 = *(longlong *)pcVar23 + 1;
                      if ((pcVar24 != (code *)0x0) &&
                         (*(longlong *)pcVar24 = *(longlong *)pcVar24 + 1,
                         plVar5 == *(longlong **)(pcVar24 + 0x18))) {
                        *(undefined4 *)(plVar5 + 5) = *(undefined4 *)(pcVar24 + 0x24);
                      }
                      local_110._0_4_ = 0;
                      *(longlong **)(param_1 + 0x138) = plVar20;
                      pcVar27 = pcVar28;
                    }
                    goto LAB_23c04c5a0;
                  }
                  plVar5 = *(longlong **)(param_1 + 0x138);
                  *(longlong **)(param_1 + 0x138) = plVar20;
                  if ((plVar5 != (longlong *)0x0) && (*plVar5 = *plVar5 + -1, *plVar5 == 0)) {
                    (**(code **)(plVar5[1] + 0x30))();
                  }
                  lVar18 = *(longlong *)(*(longlong *)(param_1 + 0x38) + 8);
                  plVar5 = *(longlong **)(lVar18 + 0x28);
                  plVar20 = (longlong *)plVar5[2];
                  *(undefined8 *)(*(longlong *)(param_1 + 0x38) + 8) =
                       *(undefined8 *)(lVar18 + 0x30);
                  *(undefined4 *)(plVar5 + 8) = 0xffffffff;
                  if (plVar20 != (longlong *)0x0) {
                    plVar5[2] = 0;
                    *plVar20 = *plVar20 + -1;
                    if (*plVar20 == 0) {
                      (**(code **)(plVar20[1] + 0x30))();
                    }
                  }
                  *plVar5 = *plVar5 + -1;
                  if (*plVar5 == 0) {
                    (**(code **)(plVar5[1] + 0x30))(plVar5);
                  }
                  plVar5[0xf] = 0;
                  *plVar17 = *plVar17 + -1;
                  if (*plVar17 == 0) {
                    (**(code **)(plVar17[1] + 0x30))(plVar17);
                  }
                  lVar18 = *(longlong *)local_108;
                  *(longlong *)local_108 = lVar18 + -1;
                  if (lVar18 + -1 == 0) {
                    (**(code **)(*(longlong *)(local_108 + 8) + 0x30))(local_108);
                  }
                  lVar18 = *(longlong *)local_120;
                  *(longlong *)local_120 = lVar18 + -1;
                  if (lVar18 + -1 == 0) {
                    (**(code **)(*(longlong *)((longlong)local_120 + 8) + 0x30))(local_120);
                  }
                  *(longlong *)local_118 = *(longlong *)local_118 + 1;
                  *(longlong *)pcVar15 = *(longlong *)pcVar15 + -1;
                  if (*(longlong *)pcVar15 == 0) {
                    (**(code **)(*(longlong *)(pcVar15 + 8) + 0x30))(pcVar15);
                  }
                  goto LAB_23c04affb;
                }
                pcVar23 = *(code **)(param_1 + 0x60);
                pcVar27 = *(code **)(param_1 + 0x68);
                pcVar24 = *(code **)(param_1 + 0x70);
                *(undefined1 (*) [16])(param_1 + 0x60) = (undefined1  [16])0x0;
              }
              pcVar28 = *(code **)(param_1 + 0x138);
              bVar9 = false;
              *(undefined8 *)(param_1 + 0x70) = 0;
              local_110._0_4_ = 0x2a;
              *(longlong **)(param_1 + 0x138) = plVar20;
              pcVar10 = pcVar23;
              pcVar11 = pcVar27;
              pcVar12 = pcVar24;
              if (pcVar28 != (code *)0x0) goto LAB_23c04c5a0;
            }
          }
          else {
            cVar13 = FUN_23a39bc50(param_1,pcVar19,DAT_23ee075d8,plVar20);
            *plVar20 = *plVar20 + -1;
            if (*plVar20 == 0) {
              FUN_23a334bc0(plVar20);
            }
            if (cVar13 == '\0') goto LAB_23c04cbc3;
LAB_23c04b2e7:
            iVar14 = (*pcVar26)(plVar16,DAT_23ee075e0);
            if (iVar14 == -1) {
              local_98 = *(undefined8 *)(param_1 + 0x60);
              uStack_90 = *(undefined8 *)(param_1 + 0x68);
              pcVar24 = *(code **)(param_1 + 0x70);
              local_118._0_4_ = 0x32;
              *(undefined8 *)(param_1 + 0x70) = 0;
              *(undefined1 (*) [16])(param_1 + 0x60) = (undefined1  [16])0x0;
              goto LAB_23c04c2b1;
            }
            if (iVar14 == 1) {
              lVar18 = FUN_23e913e30(param_1,pcVar15,DAT_23ee075e0);
              if (lVar18 != 0) {
                lVar4 = *(longlong *)(param_1 + 0x10);
                plVar20 = *(longlong **)(lVar4 + 0xe20);
                if (plVar20 == (longlong *)0x0) {
                  plVar20 = (longlong *)FUN_23e916a20(PyTuple_Type_exref,2);
                }
                else {
                  lVar7 = plVar20[3];
                  *(int *)(lVar4 + 0xebc) = *(int *)(lVar4 + 0xebc) + -1;
                  *(longlong *)(lVar4 + 0xe20) = lVar7;
                  *plVar20 = 1;
                }
                plVar20[4] = 0;
                lVar4 = *(longlong *)
                         (*(longlong *)(*(longlong *)(local_110 + 0x1f8) + 0x10) + 0x2e8);
                lVar7 = plVar20[-1];
                puVar25 = *(undefined8 **)(lVar4 + 8);
                *puVar25 = plVar20 + -2;
                uVar22 = DAT_23ee075e0;
                plVar20[-2] = lVar4;
                plVar20[-1] = (ulonglong)((uint)lVar7 & 3) | (ulonglong)puVar25;
                *(longlong **)(lVar4 + 8) = plVar20 + -2;
                plVar20[3] = lVar18;
                lVar18 = FUN_23a38cc10(param_1,plVar16,uVar22);
                if (lVar18 == 0) {
                  local_98 = *(undefined8 *)(param_1 + 0x60);
                  uStack_90 = *(undefined8 *)(param_1 + 0x68);
                  pcVar24 = *(code **)(param_1 + 0x70);
                  *(undefined1 (*) [16])(param_1 + 0x60) = (undefined1  [16])0x0;
                  local_118._0_4_ = 0x33;
                  *(undefined8 *)(param_1 + 0x70) = 0;
                  *plVar20 = *plVar20 + -1;
                  if (*plVar20 == 0) {
                    FUN_23a334bc0(plVar20);
                    local_118._0_4_ = 0x33;
                  }
                  goto LAB_23c04c2b1;
                }
                plVar20[4] = lVar18;
                plVar20 = (longlong *)FUN_23ebf8230(param_1,plVar20);
                if (plVar20 != (longlong *)0x0) {
                  cVar13 = FUN_23a39bc50(param_1,pcVar19,DAT_23ee075e0);
                  *plVar20 = *plVar20 + -1;
                  if (*plVar20 == 0) {
                    FUN_23a334bc0(plVar20);
                  }
                  if (cVar13 != '\0') goto LAB_23c04b306;
                }
              }
              local_98 = *(undefined8 *)(param_1 + 0x60);
              pcVar24 = *(code **)(param_1 + 0x70);
              *(undefined1 (*) [16])(param_1 + 0x60) = (undefined1  [16])0x0;
              local_118._0_4_ = 0x33;
              *(undefined8 *)(param_1 + 0x70) = 0;
              uStack_90 = *(undefined8 *)(param_1 + 0x68);
              goto LAB_23c04c2b1;
            }
LAB_23c04b306:
            plVar20 = (longlong *)FUN_23e8bc2f0(pcVar19,DAT_23ee075e8);
            if (plVar20 == (longlong *)0x0) {
LAB_23c04ca3e:
              local_98 = *(undefined8 *)(param_1 + 0x60);
              pcVar24 = *(code **)(param_1 + 0x70);
              local_118._0_4_ = 0x35;
              *(undefined8 *)(param_1 + 0x70) = 0;
              *(undefined1 (*) [16])(param_1 + 0x60) = (undefined1  [16])0x0;
              uStack_90 = *(undefined8 *)(param_1 + 0x68);
              goto LAB_23c04c2b1;
            }
            *(undefined4 *)(plVar5 + 5) = 0x35;
            plVar21 = (longlong *)FUN_23e9557e0(param_1,plVar20,DAT_23ee075f0);
            *plVar20 = *plVar20 + -1;
            if (*plVar20 == 0) {
              (**(code **)(plVar20[1] + 0x30))(plVar20);
            }
            if (plVar21 == (longlong *)0x0) goto LAB_23c04ca3e;
            *plVar21 = *plVar21 + -1;
            if (*plVar21 == 0) {
              (**(code **)(plVar21[1] + 0x30))(plVar21);
            }
            *(longlong *)pcVar19 = *(longlong *)pcVar19 + 1;
            uVar22 = DAT_23ee075f8;
            *(undefined4 *)(plVar5 + 5) = 0x2a;
            plVar20 = (longlong *)FUN_23e957a30(param_1,local_120,uVar22);
            if (plVar20 != (longlong *)0x0) {
              *plVar20 = *plVar20 + -1;
              if (*plVar20 == 0) {
                (**(code **)(plVar20[1] + 0x30))(plVar20);
              }
              *plVar17 = *plVar17 + -1;
              if (*plVar17 == 0) {
                (**(code **)(plVar17[1] + 0x30))(plVar17);
              }
              lVar18 = *(longlong *)local_108;
              *(longlong *)local_108 = lVar18 + -1;
              if (lVar18 + -1 == 0) {
                (**(code **)(*(longlong *)(local_108 + 8) + 0x30))(local_108);
              }
              lVar18 = *(longlong *)local_120;
              *(longlong *)local_120 = lVar18 + -1;
              local_118 = pcVar19;
              if (lVar18 + -1 == 0) {
                (**(code **)(*(longlong *)((longlong)local_120 + 8) + 0x30))(local_120);
              }
              goto LAB_23c04af98;
            }
            pcVar23 = *(code **)(param_1 + 0x60);
            pcVar24 = *(code **)(param_1 + 0x70);
            local_118 = _Py_NoneStruct_exref;
            *(undefined8 *)(param_1 + 0x70) = 0;
            local_110._0_4_ = 0x2a;
            *(undefined1 (*) [16])(param_1 + 0x60) = (undefined1  [16])0x0;
            pcVar26 = local_108;
            pcVar27 = *(code **)(param_1 + 0x68);
            pcVar10 = local_78;
            pcVar11 = pcStack_70;
            pcVar12 = local_68;
          }
LAB_23c04c134:
          local_68 = pcVar12;
          pcStack_70 = pcVar11;
          local_78 = pcVar10;
          *plVar17 = *plVar17 + -1;
          if (*plVar17 == 0) {
            (**(code **)(plVar17[1] + 0x30))(plVar17);
          }
          lVar18 = *(longlong *)local_108;
          *(longlong *)local_108 = lVar18 + -1;
          if (lVar18 + -1 == 0) {
            (**(code **)(*(longlong *)(local_108 + 8) + 0x30))();
          }
          if ((local_120 != (code *)0x0) &&
             (lVar18 = *(longlong *)local_120, *(longlong *)local_120 = lVar18 + -1,
             lVar18 + -1 == 0)) {
            (**(code **)(*(longlong *)((longlong)local_120 + 8) + 0x30))(local_120);
          }
          local_108 = *(code **)(param_1 + 0x138);
          local_d8._8_8_ = pcVar27;
          local_d8._0_8_ = pcVar23;
          local_c8[0] = pcVar24;
          if (local_108 != (code *)0x0) {
LAB_23c04bc70:
            *(longlong *)local_108 = *(longlong *)local_108 + 1;
            local_c8[0] = pcVar24;
          }
          if (local_c8[0] == (code *)0x0) goto LAB_23c04c090;
          if ((int)local_110 != 0) goto LAB_23c04b4ac;
        } while( true );
      }
      local_118 = *(code **)(param_1 + 0x60);
      pcVar24 = *(code **)(param_1 + 0x70);
      *(undefined8 *)(param_1 + 0x70) = 0;
      local_120 = *(code **)(param_1 + 0x68);
      *(undefined1 (*) [16])(param_1 + 0x60) = (undefined1  [16])0x0;
      if (pcVar24 == (code *)0x0) {
        pcVar19 = (code *)0x0;
        plVar16 = (longlong *)0x0;
        pcVar26 = (code *)0x0;
        iVar14 = 0x26;
LAB_23c04c23d:
        local_110 = _PyRuntime_exref;
        goto LAB_23c04bf26;
      }
      if (*(longlong **)(pcVar24 + 0x18) == plVar5) {
        pcVar19 = (code *)0x0;
        plVar16 = (longlong *)0x0;
        pcVar26 = (code *)0x0;
        pcVar23 = pcVar24;
        goto LAB_23c04ba50;
      }
      pcVar19 = (code *)0x0;
      plVar16 = (longlong *)0x0;
      pcVar26 = (code *)0x0;
      iVar14 = 0x26;
      local_110 = _PyRuntime_exref;
    }
  }
LAB_23c04b9b7:
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
  *(longlong **)(pcVar23 + 0x18) = plVar5;
  *plVar5 = *plVar5 + 1;
  lVar18 = *(longlong *)(local_110 + 0x1f8);
  *(int *)(pcVar23 + 0x24) = iVar14;
  *(undefined4 *)(pcVar23 + 0x20) = 0xffffffff;
  lVar18 = *(longlong *)(*(longlong *)(lVar18 + 0x10) + 0x2e8);
  lVar4 = *(longlong *)(pcVar23 + -8);
  puVar25 = *(undefined8 **)(lVar18 + 8);
  *puVar25 = pcVar23 + -0x10;
  *(longlong *)(pcVar23 + -0x10) = lVar18;
  *(ulonglong *)(pcVar23 + -8) = (ulonglong)((uint)lVar4 & 3) | (ulonglong)puVar25;
  lVar4 = *(longlong *)pcVar24;
  *(code **)(lVar18 + 8) = pcVar23 + -0x10;
  *(code **)(pcVar23 + 0x10) = pcVar24;
  if (lVar4 == 0) {
    (**(code **)(*(longlong *)(pcVar24 + 8) + 0x30))(pcVar24);
  }
LAB_23c04ba50:
  FUN_23e8bba40(plVar5,"oooooo",plVar3,pcVar15,pcVar26,plVar16,pcVar19,0);
  if (DAT_23ee0b660 == plVar5) {
    *plVar5 = *plVar5 + -1;
    if (*plVar5 == 0) {
      (**(code **)(plVar5[1] + 0x30))(plVar5);
    }
    DAT_23ee0b660 = (longlong *)0x0;
  }
  lVar18 = *(longlong *)(*(longlong *)(param_1 + 0x38) + 8);
  plVar5 = *(longlong **)(lVar18 + 0x28);
  *(undefined8 *)(*(longlong *)(param_1 + 0x38) + 8) = *(undefined8 *)(lVar18 + 0x30);
  plVar17 = (longlong *)plVar5[2];
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
  *(longlong *)pcVar15 = *(longlong *)pcVar15 + -1;
  if (*(longlong *)pcVar15 == 0) {
    (**(code **)(*(longlong *)(pcVar15 + 8) + 0x30))(pcVar15);
  }
  if ((pcVar26 != (code *)0x0) &&
     (*(longlong *)pcVar26 = *(longlong *)pcVar26 + -1, *(longlong *)pcVar26 == 0)) {
    (**(code **)(*(longlong *)(pcVar26 + 8) + 0x30))(pcVar26);
  }
  if ((plVar16 != (longlong *)0x0) && (*plVar16 = *plVar16 + -1, *plVar16 == 0)) {
    (**(code **)(plVar16[1] + 0x30))(plVar16);
  }
  if ((pcVar19 != (code *)0x0) &&
     (*(longlong *)pcVar19 = *(longlong *)pcVar19 + -1, *(longlong *)pcVar19 == 0)) {
    (**(code **)(*(longlong *)(pcVar19 + 8) + 0x30))(pcVar19);
  }
  *plVar3 = *plVar3 + -1;
  if (*plVar3 == 0) {
    (**(code **)(plVar3[1] + 0x30))(plVar3);
  }
  FUN_23a33aa70(param_1,local_118,local_120,pcVar23);
  return (code *)0x0;
LAB_23c04c090:
  if ((int)local_110 == 0) {
    uVar29 = (undefined4)plVar5[5];
  }
  else {
    uVar29 = 0x2a;
  }
LAB_23c04b8c6:
  pcVar24 = DAT_23ed6a4f8;
  if (DAT_23ed6a4f8 == (code *)0x0) {
    pcVar24 = (code *)FUN_23a33a530(PyTraceBack_Type_exref);
    pcVar23 = local_c8[0];
  }
  else {
    pcVar23 = *(code **)DAT_23ed6a4f8;
    *(longlong *)DAT_23ed6a4f8 = 1;
    DAT_23ed6a4f8 = pcVar23;
    DAT_23ed6a4f0 = DAT_23ed6a4f0 + -1;
    pcVar23 = (code *)0x0;
  }
  pcVar27 = _PyRuntime_exref;
  *(longlong *)(pcVar24 + 0x10) = 0;
  *(longlong **)(pcVar24 + 0x18) = plVar5;
  *plVar5 = *plVar5 + 1;
  lVar18 = *(longlong *)(pcVar27 + 0x1f8);
  *(undefined4 *)(pcVar24 + 0x20) = 0xffffffff;
  lVar18 = *(longlong *)(lVar18 + 0x10);
  *(undefined4 *)(pcVar24 + 0x24) = uVar29;
  lVar18 = *(longlong *)(lVar18 + 0x2e8);
  lVar4 = *(longlong *)(pcVar24 + -8);
  puVar25 = *(undefined8 **)(lVar18 + 8);
  *puVar25 = pcVar24 + -0x10;
  *(longlong *)(pcVar24 + -0x10) = lVar18;
  *(ulonglong *)(pcVar24 + -8) = (ulonglong)((uint)lVar4 & 3) | (ulonglong)puVar25;
  *(code **)(lVar18 + 8) = pcVar24 + -0x10;
  goto joined_r0x00023c04b53c;
}
